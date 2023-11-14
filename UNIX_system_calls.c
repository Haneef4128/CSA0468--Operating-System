// C program to illustrate
// open system call
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;
int main()
{	
	// if file does not have in directory
	// then file foo.txt is created.
	int fd = open("foo.txt", O_RDONLY | O_CREAT);
	
	printf("fd = %d\n", fd);
	
	if (fd ==-1)
	{
		// print which type of error have in a code
		printf("Error Number % d\n", errno);
		
		// print program detail "Success or failure"
		perror("Program");				
	}
	return 0;
}


// C program to illustrate close system Call
#include<stdio.h>
#include <fcntl.h>
int main()
{
	int fd1 = open("foo.txt", O_RDONLY);
	if (fd1 < 0)
	{
		perror("c1");
		exit(1);
	}
	printf("opened the fd = % d\n", fd1);
	
	// Using close system Call
	if (close(fd1) < 0)
	{
		perror("c1");
		exit(1);
	}
	printf("closed the fd.\n");
}


// C program to illustrate
// read system Call
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	char c;
	int fd1 = open("sample.txt", O_RDONLY, 0);
	int fd2 = open("sample.txt", O_RDONLY, 0);
	read(fd1, &c, 1);
	read(fd2, &c, 1);
	printf("c = %c\n", c);
	exit(0);
}


// C program to illustrate
// I/O system Calls
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main (void)
{
	int fd[2];
	char buf1[12] = "hello world";
	char buf2[12];

	// assume foobar.txt is already created
	fd[0] = open("foobar.txt", O_RDWR);		
	fd[1] = open("foobar.txt", O_RDWR);
	
	write(fd[0], buf1, strlen(buf1));		
	write(1, buf2, read(fd[1], buf2, 12));

	close(fd[0]);
	close(fd[1]);

	return 0;
}
