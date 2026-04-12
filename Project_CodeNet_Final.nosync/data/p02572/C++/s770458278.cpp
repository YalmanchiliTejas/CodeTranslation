// C - Sum of product of pairs
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	int N; cin>>N;
	vector<int> A(N); rep(i, N) cin>>A[i];
	vector<int64_t> S(N+1, 0);
	int MOD = (1e9) + 7;
	rep(i, N) S[i+1] = (S[i] + A[i]) % MOD;
	int64_t ans = 0;
	rep(i, N) ans = (ans + A[i] * (S.back() - S[i+1]) % MOD) % MOD;
	cout<< (ans + MOD) % MOD <<endl;
}
