#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int minimum(int a, int b)  
{  
if(a<b)  
return a;   
else   
return b;   
}
void insertionSort(int *ptr,int lb,int ub)
{
int y=lb+1,z,num;
while(y<=ub)
{
num=ptr[y];
z=y-1;
while(z>=lb && ptr[z]>num)
{
ptr[z+1]=ptr[z];
z--;
}
ptr[z+1]=num;
y++;
}
}
void merge(int *x,int lb,int mid,int ub)
{
int i1,i2,i3,tmpsize,lb1,lb2,ub1,ub2,lb3,ub3;
tmpsize=ub-lb+1;
int *tmp;
tmp=(int *)malloc(sizeof(int)*tmpsize);
lb1=lb;
ub1=mid;
lb2=mid+1;
ub2=ub;
lb3=0;
ub3=tmpsize-1;
i1=lb1;
i2=lb2;
i3=lb3;
while(i1<=ub1 && i2<=ub2)
{
if(x[i1]<x[i2])
{
tmp[i3]=x[i1];
i1++;
i3++;
}
else
{
tmp[i3]=x[i2];
i2++;
i3++;
}
}
while(i1<=ub1)
{
tmp[i3]=x[i1];
i3++;
i1++;
}
while(i2<=ub2)
{
tmp[i3]=x[i2];
i2++;
i1++;
}
i3=0;
i1=lb1;
while(i1<=ub2)
{
x[i1]=tmp[i3];
i3++;
i1++;
}
free(tmp);
}
int main()
{
int n=100;
int x[n];
srand(time(0));
for(int e=0;e<n;e++)
{
x[e]=rand();
//printf("%d  ",x[e]);
}
int mid,ub;
int y=0;
while(y<n)
{
if((y-n)<64) insertionSort(x, y,n-1);  
if((y-n)>64) insertionSort(x, y,y+63);
y+=64;
}
int j=64,lb;
while(j<n)
{
lb=0;
while(lb<n)
{
mid = lb + j - 1;
if((lb+2*j-1)<n-1) ub=lb+(2*j)-1;
else ub=n-1;
merge(x, lb, mid, ub);
lb=lb+2*j;
}
j=j*2;
}
for(int e=0;e<n;e++)printf("%d   ",x[e]);
return 0;
}
