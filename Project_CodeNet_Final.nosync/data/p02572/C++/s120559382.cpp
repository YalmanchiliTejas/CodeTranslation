// C - Sum of product of pairs
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main(){
	int MOD = 1e9 + 7;
	int N; cin>>N;
	vector<int> A(N);
	ll s = 0;
	for(int i=0; i<N; ++i){
		cin>>A[i];
		s += A[i];
		s %= MOD;
	}
	s *= s;
	for(int a:A){
		s -= (ll)a * a % MOD;
		s %= MOD;
		s += MOD;
	}
	s *= (MOD + 1) / 2;
	cout<< s % MOD <<endl;
}
