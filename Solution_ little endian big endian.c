#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) 
{
    short s;
    s=0x1234;
    char c[sizeof(s)];
    c[sizeof(s)]=s;

   if (sizeof(s) == 2)
   {
      if(c[0] < c[1])
	{
          printf("big-endian\n");
          printf("Size is=%lu \n ",sizeof(s) );		

     	}
         else if (c[0] > c[1])
         {
          printf("little-endian\n");
          printf("Size is=%lu \n ", sizeof(s));		
         }    
    }
 exit(0);
}
