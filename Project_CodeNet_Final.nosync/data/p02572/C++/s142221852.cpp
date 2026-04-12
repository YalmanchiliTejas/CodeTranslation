#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int maxn = 2e5+5;
long long A[maxn];
long long sum[maxn];
int N;
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&A[i]);
		sum[i]=(sum[i-1]+A[i]%mod)%mod;
	}
	long long ans=0;
	for(int i=1;i<=N;i++){
		ans+=(A[i]%mod)*sum[i-1]%mod;
		ans%=mod;
	}
	printf("%d\n",ans%mod);
	return 0;
}