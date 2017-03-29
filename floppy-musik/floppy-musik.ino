  int floppy1 = 2;
  int floppy2 = 4;

void setup() {
 pinMode(floppy1+1, OUTPUT);
 pinMode(floppy1, OUTPUT);
 pinMode(floppy2+1, OUTPUT);
 pinMode(floppy2, OUTPUT);

}

void loop() {
 resetAll();

play2(floppy1,floppy2,15,8,1);
play(floppy1,15,8,1);
play(floppy2,15,8,1);
wave(floppy2,3);
play(floppy1,15,8,1);
play(floppy2,15,8,0);
 
}

void wave(int id, int speed)
{
  play(id,15,speed,0);
  play(id,15,speed,1);
}

void wave2(int id, int id2, int speed)
{
    play2(id,id2,15,speed,0);
    play2(id,id2,15,speed,1);
}

void bass3(int speed,int riktning)
{
  play(floppy1,15,speed,riktning);
  play(floppy2,15,speed,riktning);
}

void reset(int id)
{
        digitalWrite(id, LOW);
        for (int i = 0;i<100;i++)
      {
        tick(id,2);
      }
}

void resetAll()
{
      digitalWrite(floppy1, LOW);
      digitalWrite(floppy2, LOW);
      for (int i = 0;i<100;i++)
      {
        tick2(floppy1,floppy2,2);
      }
}

void play2(int id, int id2, int lengd, int tid, int riktning)
{
    if (riktning == 1)
  {
      digitalWrite(id, HIGH);
      digitalWrite(id2, HIGH);
      for (int i = 0;i<lengd;i++)
      {
        tick2(id,id2,tid);
      }
  } else
  {
      digitalWrite(id, LOW);
      digitalWrite(id2, LOW);
      for (int i = 0;i<lengd;i++)
      {
        tick2(id,id2,tid);
      }
    }
}

void play(int id, int lengd, int tid, int riktning)
{
  if (riktning == 1)
  {
      digitalWrite(id, HIGH);
      for (int i = 0;i<lengd;i++)
      {
        tick(id,tid);
      }
  } else
  {
      digitalWrite(id, LOW);
      for (int i = 0;i<lengd;i++)
      {
        tick(id,tid);
      }
    }
}

void tick2(int id, int id2, int tid)
{
        digitalWrite(id + 1, HIGH);
        digitalWrite(id2 + 1, HIGH);
        delay(tid);
        digitalWrite(id + 1, LOW);
        digitalWrite(id2 + 1, LOW);
        delay(tid);
}

void tick(int id, int tid)
{
        digitalWrite(id + 1, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(tid);                       // wait for a second
        digitalWrite(id + 1, LOW);    // turn the LED off by making the voltage LOW
        delay(tid);
}


