#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
	
	while(1){
		int max;
		int maxnum;
		max=0;
		for(int i=0;i<5;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			if(a==0 && b==0){
				goto A;
			}
			if(a+b>max){
				max=a+b;
				maxnum=i;
			}
		}
		printf("%c %d\n",'A'+maxnum,max);
	}
	A:
	return 0;
}