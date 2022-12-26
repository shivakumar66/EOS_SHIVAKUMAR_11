#include<stdio.h>
 #include <fcntl.h>              /* Obtain O_* constant definitions */
#include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
#define buff_size 1024
char buff[buff_size];
int main()
{
    int fd[2],count,i;
    char s;
    pid_t id;
    pipe(fd);
    id=fork();
    if(0==id)
    {
            close(fd[1]);
           while(buff[i]!=sizeof(buff))
            {

            
            read(fd[0],buff,sizeof(buff));
            printf("%s\n",buff);
            if(buff=='s')
            {
                count++;
            }
            }

        printf("%d\n",count);
        close(fd[0]);
    }
    else
    {
        close(fd[1]);
    fd[0]=open("usr/include/stdio.h", O_RDONLY,S_IRUSR | S_IWUSR);
        read(fd[0],buff,sizeof(buff));
        close(fd[0]);
        write(fd[1],buff,sizeof(buff));
        close(fd[1]);
    }
 
}