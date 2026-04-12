#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int A,B,C,X,Y,cost=0;
	scanf("%d %d %d %d %d",&A,&B,&C,&X,&Y);
	if(A+B>C*2){
		while(X>0&&Y>0){
			cost+=C*2;
			X-=1;Y-=1;
		}
	}
	if(A>C*2){
		while(X>0){
			cost+=C*2;
			X-=1;Y-=1;
		}
	}
	if(B>C*2){
		while(Y>0){
			cost+=C*2;
			X-=1;Y-=1;
		}
	}
	if(X>0||Y>0){
		while(X>0){
			cost+=A;
			X-=1;
		}
		while(Y>0){
			cost+=B;
			Y-=1;
		}
	}
	printf("%d",cost);
	return 0;
}