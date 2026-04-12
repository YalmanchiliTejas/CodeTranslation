#include<cstdio>
#include<iostream>
#include<algorithm>
#define M 200005
using namespace std;
int A[M],B[M],C[M];
int main(){
	int n;
	scanf("%d",&n);
	int t=n%2;
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	int k=(n+2)/2;
	B[1]=k;
	for(int i=2;i<=n;i++){
		int p=i/2;
		if(i%2==0){
			if(t)B[i]=k+p;
			else B[i]=k-p;
		}else{
			if(t)B[i]=k-p;
			else B[i]=k+p;
		}
	}
	for(int i=1;i<=n;i++)C[B[i]]=A[i];
	for(int i=1;i<=n;i++)printf("%d ",C[i]);
	puts("");
	return 0;
}