#include<stdio.h>
int dat[100];
int main(){
	int a,b,c,d,e;
	while(scanf("%d%d%d%d%d",&a,&b,&c,&d,&e),a){
		for(int i=0;i<a;i++)scanf("%d",dat+i);
		int now=0;
		int frame=-1;
		int x=e;
		while(frame<=10001&&now<a){
			frame++;
			if(dat[now]==x){
				now++;
				x=(x*b+c)%d;
			}else{
				x=(x*b+c)%d;
			}
		}
		if(frame>10000)printf("-1\n");
		else printf("%d\n",frame);
	}
}