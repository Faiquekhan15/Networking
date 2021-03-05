#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>
#include<string.h>
#include <sys/stat.h>
int main(){
	FILE * fptr;
	char* token1;
    char* token2;
    char buffer[500];
	int cpu_work=0;
	int sumofidle;
	float average=0;
	int user=0,nice=0,system=0,idle=0,iowait=0,irq=0,softirq=0;
	for(int i=0;i<2;i++)
	{
	fptr=fopen("/proc/stat.txt","r");
	fscanf(fptr, "%s %d %d %d %d %d %d %d",buffer,&user,&nice,&system,&idle,&iowait,&irq,&softirq);
	token1=strtok(buffer,"\n");
    idle++;	
	token2=strtok(token1," ");
    while(token2!=NULL)
	{
		iowait=atoi(token2);
        sumofidle=idle+iowait;
        if(idle>1)
		{
          cpu_work=cpu_work-iowait;
        }		  
	}
	token2=strtok(NULL," ");
    idle++;
	fclose(fptr);
    sleep(1);  
	}
	average=cpu_work+sumofidle/2;
    printf("Average Utilization = %f\n",average);

   
return 0; 
}
	