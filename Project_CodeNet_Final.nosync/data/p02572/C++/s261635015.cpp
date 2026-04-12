#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000000 + 7;

long long modplus(long long a, long long b){
	long long ans = a + b;
	ans %= mod;
	return ans;
}

long long modminus(long long a, long long b){
	long long ans = a - b;
	ans %= mod;
	if(ans < 0) ans += mod;
	return ans;
}

long long modmul(long long a, long long b){
	long long ans = (a % mod) * (b % mod);
	ans = ((ans % mod) + mod) % mod;
	return ans;
}

int main(){
	int N;
	cin >> N;
	long long A[N];
	long long sum[N];
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	sum[0] = A[0];
	for(int i=1;i<N;i++){
		sum[i] = modplus(A[i], sum[i-1]);
	}
	long long ans = 0;
	for(int i=0;i<N-1;i++){
		ans = modplus(ans,modmul(A[i], 
			modminus(sum[N-1], sum[i])));
	}
	cout << ans << endl;
}