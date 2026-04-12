#include<stdio.h>
#include<algorithm>
using namespace std;
int val[20000];
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b),a+b){
		for(int i=0;i<a+b;i++)scanf("%d",val+i);
		std::sort(val,val+a+b);
		int ret=val[0];
		for(int i=1;i<a+b;i++){
			ret=max(ret,val[i]-val[i-1]);
		}
		printf("%d\n",ret);
	}
}