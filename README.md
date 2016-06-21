# RingBuffer

This class implements a _ring buffer_ of a fixed capacity of bytes.  This is also sometimes called a _FIFO_ (first in first out) buffer or simply a FIFO.

Bytes can be "pushed" into a ring buffer one at a time, and they can be "popped" back out with their push order preserved (first in, first out).  Pushes and pops may happen in any order, with two conditions.

1. Pushing into a full buffer will cause the oldest byte in the buffer to be lost.
2. Popping from an empty buffer will return a zero byte.

If these behaviors are not desired, methods are provided to test if a buffer is full or empty; it will often be neither.
An additional method is available to clear the current contents of the buffer.

Beware of creating a ring buffer that's too large; because it resides in the processor's RAM, you're constrained by the size of RAM.  For example, an Arduino Uno has only 2048 bytes of RAM, and some of that will certainly be used by other variables in your code and the libraries you use.

The examples directory contains a sample sketch to show how the RingBuffer class is used.
