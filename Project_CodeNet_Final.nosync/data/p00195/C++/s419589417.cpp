#include <cstdio>

int main(){
	char cs[]="ABCDE";
	for(;;){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==0&&b==0) break;
		int ma=a+b;
		char c='A';
		for(int i=0;i<4;i++){
			scanf("%d%d",&a,&b);
			if(a+b>ma){
				ma=a+b;
				c=cs[i+1];
			}
		}
		printf("%c %d\n",c,ma);
	}
}