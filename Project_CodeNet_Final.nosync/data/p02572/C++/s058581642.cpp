#include <bits/stdc++.h>
using namespace std;
#define LL long long

const LL mod = 1e9+7;
LL N, A[200010], sumAll=0, sumSq=0, ans=0;

int main () {
	cin >> N;
	for(int i=1; i<=N; i++) {
		cin >> A[i];
		sumAll += A[i]; sumAll %= mod;
		sumSq += (A[i]*A[i])%mod; sumSq %= mod;
	}
	ans = (sumAll*sumAll)%mod - sumSq;
	ans %= mod;
	ans += mod;
	ans %= mod;
	ans *= 500000004;
	ans %= mod;
	cout << ans << endl;
}
