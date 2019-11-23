#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char const *argv[]) {
  int p,p1,err;
  int status;
  p = fork();
  if (p==0){
    err = execlp("gcc","gcc",argv[1],"-o","prog1.o",NULL);
    exit(1);
  }
  p1= waitpid(p,&status,0);
  if ((status>>8)!=0){
    printf("Executable not created\n");
    return 2;
  }

  if (p>0){
      // p=fork();
      // err = execlp("gcc","-o",)

  }


  err = execlp("./prog1.o","prog1.o",NULL);
  return 3;

}
