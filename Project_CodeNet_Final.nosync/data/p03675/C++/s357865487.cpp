#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int seq[1000100] = {0};
int a[100010] = {0};
int front,back;
int main(){
	scanf("%d",&N);
	for(int i = 1;i <= N;i++)scanf("%d",&a[i]);
	if(N & 1){
		for(int i = N;i >= 1;i-= 2)printf("%d ",a[i]);
		for(int i = 2;i <= N;i+= 2)printf("%d ",a[i]);	
	}
	else{
		for(int i = N;i >= 2;i-=2)printf("%d ",a[i]);
		for(int i = 1;i <= N;i+=2)printf("%d ",a[i]);	
	}
	return 0;
}
