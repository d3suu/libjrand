#include <stdbool.h> // bool type, true, false
#include <pthread.h> // mutex
#include <sys/time.h> // gettimeofday, timeval

sjrand_t* Random(void){
    // Get milliseconds as seed
    struct timeval te; 
    gettimeofday(&te, NULL); // get current time
    long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
    
    // Make structure and initialize
    sjrand_t* this = (sjrand_t*) malloc(sizeof(sjrand_t));
    if(this == NULL){
        // malloc failed
        return NULL;
    }
    
    if(pthread_mutex_init(&(this->mutexLock), NULL) != 0){
        // mutex init has failed
        free(this);
        return NULL;
    }
    
    // Lock, set variables, unlock
    pthread_mutex_lock(&(this->mutexLock));
    this->initialSeed = milliseconds;
    this->currentSeed = milliseconds;
    this->haveNextNextGaussian = false;
    pthread_mutex_unlock(&(this->mutexLock));
    
    // Return
    return this;
}
