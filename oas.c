#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
 int main()
{
int r;
//no of resources

int p;
//no of process

int a[10];
//variables use to check process is safe or unsafe 
int TA[10];
int b=1;
//used if any process request resources

int max_need[10][10];
//maximum instances required

int T[10];
//total value list

int Available[10];
//available resources

int need[10][10];
//resources needed to complete the process
int f=0;
//used to compare the resources 

int i;
//used to operate loops

int j;
//used to operate loops

int Allocate[10][10];
//allocated resources



printf("Enter no of resources\n");
scanf("%d",&r);
if(r==0)
{
printf("ITs imossible that system have no resources");
exit(0);
}
printf("Enter no of process\n");
scanf("%d",&p);
if(p==0)
{printf("there should be some process");
exit(0);
}
printf("Enter the allocated values\n");
for(i=0;i<p;i++)
   {
     printf("*****************Process(%d):*****************\n",i);
     for(j=0;j<r;j++)
      {
         printf("Resource(%d):\t",j);
         scanf("%d",&Allocate[i][j]);
                                        }
                                                        }


printf("Enter the maximum instances required\n");
for(i=0;i<p;i++)
      {
         printf("************Process(%d):*************\n",i);
         for(j=0;j<r;j++)
           {
              printf("Resource(%d)\t",j);
              scanf("%d",&max_need [i][j]);
                                                }
                                                         }

printf("Enter total available resources\n");
for(j=0;j<r;j++)
      {
         printf("Resource(%d)\t",j);
         scanf("%d",&T[j]);
                                       }
printf("Need values\n");
//need of resources
while(b==1){
     for(i=0;i<p;i++)
        {
           for(j=0;j<r;j++)
               {
                  need[i][j]=max_need[i][j]-Allocate[i][j];
                  printf("%d",need [i][j]);
                                                               }
           printf("\n");
                                                                   }
     for(j=0;j<r;j++)
        {
           for(i=0;i<p;i++)
               {
                  TA[j]+=Allocate[i][j];
                                                               }
											                       }
     
	 printf("Available is \n");
     for(j=0;j<r;j++)
        {
                    Available[j]=T[j]-TA[j];
                    printf("%d\t",Available[j]);
                                                            }
     for(i=0;i<3*p;i++)
        {
            for(j=0;j<r;j++)
                {
                    if(need[j][i]<=Available[j])
                    f++;
                                                          }
            if(f==r)
                {
                    printf("process P(%d) is safe",i);
                    for(j=0;j<r;j++)
                        {
                           Available[j]= Allocate[j][i]+Available[j];
                           printf("%d\t",Available[j]);
                                                                      }
                    printf("is new available list\n");
                    a[i]=1;
                                                                            }
                                                                                    }
     for (i=0;i<p;i++)
        {
            if(a[i]!=1)
                {
                    printf("process p(%d) is unsafe\n",i);
                                                             }
            printf("if you want to change request process press 1 otherwise 0\n");
            scanf("%d",&b);
            if(b==1)
                {             
                    printf("Enter process Id if he request resources :\n");
                    scanf("p(%d)",&i);
                    for(j=0;j<r;j++)
                       {
                            printf("Resource(%d)\t",j);
                            scanf("%d",&Allocate[j][i]);
                                                           }
                                                                                  } 
                                                                                                  }
                                                                                                           }//here while loop ends
return 0;
}//here main function ends 
