#include <stdio.h>
#include <stdlib.h>
#include <lib.h>

char getgroup(int pid)
{
  message m;
  m.m1_i1 = pid;
  return _syscall(MM, GETSCHEDGROUP, &m);
}

void setgroup(int pid, char group)
{
  message m;
  m.m1_i1 = pid;
  m.m1_i2 = group;
  _syscall(MM, SETSCHEDGROUP, &m);
}


int main(int argc, char* argv[])
{
  pid_t pid = getpid();
  char group;
  
  if (argc != 2)
  {
    printf("Usage: %s <sched group:A/B/C\n", argv[0]);
    return 0;
  }
  
  group = getgroup(pid);
  printf("> Process pid=%d (this) is of group '%c'\n", pid, group);
  
  group = argv[1];
  if (group <'A' || group > 'C')
  {
    printf("Usage: %s <sched group:A/B/C\n");
    return 0;
  }

  setgroup(pid, group);
  
  group = getgroup(pid);
  printf("> Process pid=%d (this) is now of group '%c'\n", pid, group);

  while (1){};
  
  return 0;
}
