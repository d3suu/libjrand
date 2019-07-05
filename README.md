# libjrand
Java.util.Random implementation in C

## About
`libjrand` is `java.util.Random` implementation in C. Im using it for porting Java applications to C, and building C applications which are compatible with Java, on backend layer.

## Goals
 - `libjrand` should be:
   - thread-safe
   - fully written in C
   - simple to implement
   - fully compatible with Java version (as in results)
 - Easy to read documentation
 - Readable and easy to maintain code

## Documentation
 - For libjrand code documentation, see [doc/jrand.c.md](doc/jrand.c.md)
 - For libjrand implementation guide, see [doc/libjrand_implementation.md](doc/libjrand_implementation.md)
 - For legacy `java.util.Random` code documentation, see [https://docs.oracle.com/javase/7/docs/api/java/util/Random.html](https://docs.oracle.com/javase/7/docs/api/java/util/Random.html)
 - For legacy `java.util.Random` code, see [http://developer.classpath.org/doc/java/util/Random-source.html](http://developer.classpath.org/doc/java/util/Random-source.html)

## License
Since official `java.util.Random` is licensed under GPLv2 by Free Software Foundation, this code is being released with updated version, GPLv3. Also credits for legacy `java.util.Random` code goes to Free Software Foundation. That said, this code should be interpreted as code developed on `java.util.Random` base. Same goes to code documentation.

## A few words at the end
This project is based on my previous `java.util.Random` implementation, except in C++. Since then, i wanted to change a few things, and make code well documented. You can check it, at [https://github.com/d3suu/Java-Random-except-its-in-CPP](https://github.com/d3suu/Java-Random-except-its-in-CPP)
