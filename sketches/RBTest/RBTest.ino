#include <RingBuffer.h>

RingBuffer rb(4);

void show()
{
  Serial.println(rb.isEmpty() ? "rb is EMPTY" : "rb is NOT EMPTY");
  Serial.println(rb.isFull()  ? "rb is FULL"  : "rb is NOT FULL");
}

void setup() 
{
  Serial.begin(115200);
  show();
  for (byte b = 0; b < 5; ++b) {
    if (!rb.isFull()) {
      Serial.print("pushing ");
      Serial.println(b, DEC);
      rb.push(b);
    } else {
      Serial.print("skipping ");
      Serial.println(b, DEC);
    }
    show();
  }
  while (!rb.isEmpty()) {
    Serial.print("popped ");
    Serial.println(rb.pop(), DEC);
    show();
  }
  Serial.print("popped ");
  Serial.println(rb.pop(), DEC);
  show();
}

void loop()
{
}
