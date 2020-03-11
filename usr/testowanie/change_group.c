#include <stdio.h>
#include <stdlib.h>
#include <lib.h>

char getgroup(int pid)
{
  message m;
  m.m1_i1 = pid;
  return _syscall(MM, GETGROUP, &m);
}

void setgroup(int pid, char group)
{
  message m;
  m.m1_i1 = pid;
  m.m1_i2 = group;
  _syscall(MM, SETGROUP, &m);
}

int main(int argc, char* argv[])
{
  char group;
  int pid = atoi(argv[1]);
  
  if (argc != 3)
  {
    printf("> Usage: %s <app_pid> <new_group:A/B/C>\n", argv[0]);
    return 0;
  }
  
  group = getgroup(pid);
  printf("> Proces pid=%d ma grupe '%c'\n", pid, group);
  
  group = argv[2][0];
  setgroup(pid, group);
  
  group = getgroup(pid);
  printf("> Proces pid=%d nowa grupa '%c'\n", pid, group);
  return 0;
}
