#include<stdio.h>
#include<algorithm>
using namespace std;
int d[120];
int main(){
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<a;i++)scanf("%d",d+i);
	for(int i=0;i<a;i++){
		for(int j=0;j<=b+c;j+=d[i]){
			if(b-c<=j&&j<=b+c){
				printf("%d\n",i+1);
				return 0;
			}
		}
	}
	printf("-1\n");
}