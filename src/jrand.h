#ifndef JRAND_H
#define JRAND_H

// Structures
struct sjrand_s {
	long initialSeed;
	long currentSeed;
	double nextNextGaussian;
	bool haveNextNextGaussian; // Should be `false` by default
	pthread_mutex_t mutexLock;
};

// Types
typedef struct sjrand_s sjrand_t;

// Pseudo-constructors
sjrand_t* Random();
sjrand_t* RandomWithSeed(long seed);

// Functions
//// Basic functions
int next(int bits, sjrand_t* jrandStruct);
bool nextBoolean(sjrand_t* jrandStruct);
void nextBytes(char* bytes, unsigned int bytesLength, sjrand_t* jrandStruct);
double nextDouble(sjrand_t* jrandStruct);
float nextFloat(sjrand_t* jrandStruct);
double nextGaussian(sjrand_t* jrandStruct);
int nextInt(sjrand_t* jrandStruct);
int nextInt(int maxInt, sjrand_t* jrandStruct);
long nextLong(sjrand_t* jrandStruct);
void setSeed(long seed, sjrand_t* jrandStruct);
//// Custom functions
long getCurrentSeed(sjrand_t* jrandStruct);
long getInitialSeed(sjrand_t* jrandStruct);
bool haveNextNextGaussian(sjrand_t* jrandStruct);
void randomDestruct(sjrand_t* jrandStruct);

#endif
