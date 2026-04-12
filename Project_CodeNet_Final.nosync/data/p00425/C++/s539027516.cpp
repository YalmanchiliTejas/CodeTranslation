#include<stdio.h>
int m[]={5,1,2,4,1,3,1,0,0,2,3,2,2,4,5,1,4,0,4,3,3,5,0,5};
char s[99];
int main(){
	s[87]=1;s[78]=4;s[69]=3;s[83]=2;
	for(int a,b,c,n,r,d;a=c=0,b=r=scanf("%d",&n),n;printf("%d\n",r)){
		for(;n--;r+=a%3?b%3?(b+6-a)%6<3?2:5:b?3:4:a?6:1){
			scanf("%s",s);
			d=s[*s];
			d?a=m[4*a+(d+c)%4],b=m[4*b+(d+c)%4]:c+=*s==76?3:1;
		}
	}
}