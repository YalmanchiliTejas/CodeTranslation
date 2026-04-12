// C - Sum of product of pairs
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main(){
	int MOD = 1e9 + 7;
	int N; cin>>N;
	ll s = 0, d = 0;
	for(int i=0; i<N; ++i){
		ll a; cin>>a;
		s += a;
		s %= MOD;
		d += a * a % MOD;
		d %= MOD;
	}
	s = (s * s - d) % MOD * (MOD + 1) / 2;
	cout<< s % MOD <<endl;
}
