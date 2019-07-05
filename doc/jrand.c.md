# jrand.c
> Based on [https://docs.oracle.com/javase/7/docs/api/java/util/Random.html](https://docs.oracle.com/javase/7/docs/api/java/util/Random.html)

## Pseudo-constructor Summary
 - `sjrand_t Random()`
   - Creates a new random number generator structure.
 - `sjrand_t Random(long seed)`
   - Creates a new random number generator structure using a single `long` seed.

## Structure Summary
 - `struct sjrand_s`
   - `libjrand` basic structure containing:
     - `long initialSeed`
       - Value containing initial seed, set by `void setSeed(long seed, sjrand_t* jrandStruct)`, `sjrand_t Random()` and `sjrand_t Random(long seed)`.
     - `long currentSeed`
       - Value containing current sequence seed.
     - `double nextNextGaussian`
       - Value containing "nextNext" Gaussian. Needed for `nextGaussian()`.
     - `bool haveNextNextGaussian`
       - Value containing "nextNext" Gaussian state in structure.
     - `pthread_mutex_t mutexLock`
       - Mutex lock, for synchronization between threads.

## Type Summary
 - `sjrand_t`
   - Defined `sjrand_s` struct.

## Function Summary

### Basic functions
 - `int next(int bits, sjrand_t* jrandStruct)`
   - Generates the next pseudorandom number.
 - `bool nextBoolean(sjrand_t* jrandStruct)`
   - Returns the next pseudorandom, uniformly distributed `bool` value from this random number generator's sequence.
 - `void nextBytes(char* bytes, unsigned int bytesLength, sjrand_t* jrandStruct)`
   - Generates random bytes and places them into a user-supplied byte array.
 - `double nextDouble(sjrand_t* jrandStruct)`
   - Returns the next pseudorandom, uniformly distributed `double` value between `0.0` and `1.0` from this random number generator's sequence.
 - `float nextFloat(sjrand_t* jrandStruct)`
   - Returns the next pseudorandom, uniformly distributed `float` value between `0.0` and `1.0` from this random number generator's sequence.
 - `double nextGaussian(sjrand_t* jrandStruct)`
   - Returns the next pseudorandom, Gaussian ("normally") distributed `double` value with mean `0.0` and standard deviation `1.0` from this random number generator's sequence.
 - `int nextInt(sjrand_t* jrandStruct)`
   - Returns the next pseudorandom, uniformly distributed `int` value from this random number generator's sequence.
 - `int nextInt(int maxInt, sjrand_t* jrandStruct)`
   - Returns a pseudorandom, uniformly distributed `int` value between `0` (inclusive) and the specified value (exclusive), drawn from this random number generator's sequence.
 - `long nextLong(sjrand_t* jrandStruct)`
   - Returns the next pseudorandom, uniformly distributed `long` value from this random number generator's sequence.
 - `void setSeed(long seed, sjrand_t* jrandStruct)`
   - Sets the seed of this random number generator using a single `long` seed.

### Custom functions
 - `long getCurrentSeed(sjrand_t* jrandStruct)`
   - Returns a single `long` seed value from current sequence.
 - `long getInitialSeed(sjrand_t* jrandStruct)`
   - Returns a single `long` seed value defined by `void setSeed(long seed)`, `sjrand_t Random()` or `sjrand_t Random(long seed)`.
 - `bool haveNextNextGaussian(sjrand_t* jrandStruct)`
   - Returns a single `bool` value from `jsrand_t* jrandStruct` of `bool haveNextNextGaussian`, while locking with mutex.

## Pseudo-constructor Detail

#### sjrand_t Random()
Creates a new random number generator structure. 
 - Seed is based on current Unix time
 - Initializes mutex

#### sjrand_t Random(long seed)
Creates a new random number generator structure using a single `long` seed.
 - Initializes mutex

Invocation `Random(seed)` is equivalent to:
```C
sjrand_t JRandStructure;
JRandStructure = Random();
setSeed((long)seed, &JRandStructure);
```

## Structure Detail

#### struct sjrand_s

##### long initialSeed
Value containing initial seed, set by `void setSeed(long seed, sjrand_t* jrandStruct)`, `sjrand_t Random()` and `sjrand_t Random(long seed)`.

##### long currentSeed
Value containing current sequence seed.

##### double nextNextGaussian
Value containing "nextNext" Gaussian. Needed for `nextGaussian()`.

##### bool haveNextNextGaussian
Value containing "nextNext" Gaussian state in structure.

##### pthread_mutex_t mutexLock
Mutex lock, for synchronization between threads.

## Function Detail
