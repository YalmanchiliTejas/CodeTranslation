#include<stdio.h>
int main()
{
int r,g,b;
scanf("%d %d %d",&r,&g,&b);
if((100*r+10*g+b)%4==0)
printf("YES");
else
printf("NO");
return 0;
}