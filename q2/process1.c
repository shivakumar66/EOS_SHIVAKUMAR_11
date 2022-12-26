#include<stdio.h>
#include<mqueue.h>
#include<sys/stat.h>
 #include <unistd.h>
    #include <sys/stat.h>
       #include <fcntl.h>
       #include<stdlib.h>


#define buff_size 64
char buff[buff_size];
struct mq_attr usr_mq_attr;
int main()
{
    mqd_t usr;
    int mq_sender,mq_closer,send;
     usr_mq_attr.mq_flags =0;
    usr_mq_attr.mq_maxmsg = 4;
    usr_mq_attr.mq_msgsize=64;
    usr_mq_attr.mq_curmsgs =0;
    usr=mq_open("/desd_mq",O_CREAT | O_RDWR,S_IRUSR | S_IWUSR,&usr_mq_attr);
    if(-1==usr)
    {
        perror("Error : mq_open\n");
    }
    send=open("/usr/include/stdio.h",O_RDONLY,S_IRUSR | S_IWUSR);
     read(send,buff,sizeof(buff));
    mq_sender=mq_send(usr,buff,sizeof(buff),0);
      if(-1==mq_sender)
    {
        perror("Error:mq_sender");
        exit(EXIT_FAILURE);
    }
    mq_closer=mq_close(usr);
      if(-1==mq_closer)
    {
        perror("Error:mq_close");
        exit(EXIT_FAILURE);
    }
    
}