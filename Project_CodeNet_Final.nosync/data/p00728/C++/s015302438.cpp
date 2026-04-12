#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int a;
	while(scanf("%d",&a),a){
		int M=0;int m=9999;
		int sum=0;
		for(int i=0;i<a;i++){
			int b;scanf("%d",&b);M=max(M,b);m=min(m,b);sum+=b;
		}
		printf("%d\n",(sum-M-m)/(a-2));
	}
}