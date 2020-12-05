#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	srand(time(NULL));
	int status;

	printf("I am the parent process. My pid is %d.\n\n", getpid());

	int f = fork();
	if (f){
		f = fork();
	}

	if (!f){
		int pid = getpid();
		printf("This is a child, and my pid is %d.\n", pid);
		int t = rand() % 9 + 2;

		sleep(t);
		printf("Child with pid %d is done.\n", pid);
		return t;
	}

	else{
		int pid = wait(&status);
		printf("\nParent: The child with pid %d has finished! It slepted for %d seconds.\n", pid, WEXITSTATUS(status));
		printf("\nParent: This parent process is finished. Bye!\n");
		return 0;
	}
}
