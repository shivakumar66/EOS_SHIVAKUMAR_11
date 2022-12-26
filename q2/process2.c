#include<stdio.h>
#include<mqueue.h>
#include<sys/stat.h>
 #include <unistd.h>
    #include <sys/stat.h>
       #include <fcntl.h>
#define buff_size 64
char buff[buff_size];
struct mq_attr usr_mq_attr;
int main()
{
    int count,i;
    mqd_t usr,send;
    int mq_sender,mq_reciever,mq_closer;
     usr_mq_attr.mq_flags =0;
    usr_mq_attr.mq_maxmsg = 4;
    usr_mq_attr.mq_msgsize=64;
    usr_mq_attr.mq_curmsgs =0;
    usr=mq_open("/desd_mq",O_RDWR,S_IRUSR | S_IWUSR,&usr_mq_attr);
    if(-1==usr)
    {
        perror("Error : mq_open\n");
    }
    while(buff[i]!=sizeof(buff))
    {
    mq_reciever=mq_receive(usr,buff,sizeof(buff),0);
    if(-1==mq_reciever)
    {
        perror("Error : mq_reciever\n");
    }
    printf("%s\n",buff);
    if(buff[i]=='s')
    {
        count++;
    }
    }
    printf("%d\n",count);
    mq_closer=mq_close(usr);
    if(-1==mq_closer)
    {
        perror("Error : mq_closer\n");
    }
}