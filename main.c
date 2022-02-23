#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
	int value = 0;
	pid_t np;
	const int time_sleep = 10;

	np = fork();
	if (np == 0) {
		printf("\n## processo filho - ");
              	printf("PID %d ## \n~seg 1\n", getpid());
		return 1;
	}
	system("ps -l");
	sleep(time_sleep);

	printf("\n## processo pai - ");
	printf("PID %d ## \n~seg %d\n", getpid(), time_sleep);

	execlp("/bin/ps", "ps", "-l", NULL);
	return 0;
}
