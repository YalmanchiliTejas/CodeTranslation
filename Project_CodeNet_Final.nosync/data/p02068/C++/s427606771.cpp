#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	long long A[N];
	for(int i=0;i<N;i++)scanf("%lld", &A[i]);
	long long ans = 0;
	for(long long i=2;i*i<=1000000000;i++){
		long long tmpans = 0;
		for(int j=0;j<N;j++)if(A[j]%i==0)tmpans+=A[j];
		ans=max(ans, tmpans);
	}
	long long B[N];
	for(int i=0;i<N;i++){
		B[i]=A[i];
		for(long long j=2;j*j<=1000000000;j++){
			while(B[i]%j==0)B[i]/=j;
		}
	}
	for(int i=0;i<N;i++){
		long long tmpans = 0;
		for(int j=0;j<N;j++){
			if(B[i]!=1&&A[j]%B[i]==0)tmpans += A[j];
		}
		ans=max(ans, tmpans);
	}
	printf("%lld\n", ans);
	return 0;
}
