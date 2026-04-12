#include<stdio.h>
int m[6][4] = {{5,1,2,4},{1,3,1,0},{0,2,3,2},{2,4,5,1},{4,0,4,3},{3,5,0,5}};
int main(){
	for(int a,b,c,n,r,d;a=c=0,b=r=scanf("%d",&n),n;printf("%d\n",r)){
		for(char s[10];n--;r+=a%3?b%3?(b+6-a)%6<3?2:5:b?3:4:a?6:1){
			scanf("%s",s);
			d=-1;
			if(s[0]=='L')c+=3; 
			if(s[0]=='R')c++;
			if(s[0]=='W')d=1;
			if(s[0]=='N')d=0;
			if(s[0]=='E')d=3;
			if(s[0]=='S')d=2;
			if(d!=-1)
				a=m[a][(d+c)%4],
				b=m[b][(d+c)%4];
		}
	}
}