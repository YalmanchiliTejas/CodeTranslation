#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

static const int M = (int)2e5+5;
int A[M];
int ans[M];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	int L=1,R=n;
	for(int i=n;i>=1;--i){
		if((i&1)==(n&1))ans[L++]=A[i];
		else ans[R--]=A[i];
	}
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	puts("");
	return 0;
}