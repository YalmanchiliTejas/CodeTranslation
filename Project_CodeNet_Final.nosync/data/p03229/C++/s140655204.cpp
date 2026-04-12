#include "bits/stdc++.h"
using namespace std;
typedef long long mLL;

int main() {
    int N;
    scanf("%d",&N);

    mLL A[N],smaller=0,bigger=0;
    for(int i=0;i<N;i++){
		scanf("%lld",&A[i]);
	}
	sort(A,A+N);
	int K=N/2;
	
	if(N%2)
	{
		for(int i=0;i<K;i++) smaller+=A[i];
		for(int i=K+1;i<N;i++) bigger+=A[i];
		mLL pattern1 = 2*bigger - 2*smaller + A[K-1] - A[K];
		mLL pattern2 = 2*bigger - 2*smaller - A[K+1] + A[K];
		printf("%lld\n", pattern1>pattern2?pattern1:pattern2);
	}
	else
	{
		for(int i=0;i<K;i++) smaller+=A[i];
		for(int i=K;i<N;i++) bigger+=A[i];
		printf("%lld\n",2*bigger-A[K]-2*smaller+A[K-1]);
	}

	return 0;
}