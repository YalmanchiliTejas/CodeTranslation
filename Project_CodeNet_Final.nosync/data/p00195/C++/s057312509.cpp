#include<stdio.h>
int main(){
	while(1){
		int max=0;char sec;
		for(int i=0;i<5;i++){
			int a,b;scanf("%d%d",&a,&b);
			if(i==0&&(a|b)==0)return 0;
			if(max<a+b){
				max=a+b;sec='A'+i;
			}
		}printf("%c %d\n",sec,max);
	}
}
