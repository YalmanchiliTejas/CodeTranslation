#include<stdio.h>
int m[]={5,1,2,4,1,3,1,0,0,2,3,2,2,4,5,1,4,0,4,3,3,5,0,5};
char s[99];
int main(){s[87]=1;s[78]=4;s[69]=3;s[83]=2;for(int a,b,c,n,r,d;b=r=scanf("%d",&n),n;printf("%d\n",r)){for(a=c=0;n--;r+=a%3?b%3?(b+6-a)%6<3?2:5:b?3:4:a?6:1){scanf("%s",s);d=s[*s];d?d=d+c&3,a=m[4*a+d],b=m[4*b+d]:c+=*s-76?1:3;}}}