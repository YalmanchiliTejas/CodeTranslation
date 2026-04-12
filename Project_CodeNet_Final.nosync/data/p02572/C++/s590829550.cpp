// C - Sum of product of pairs
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main(){
	int MOD = 1e9 + 7;
	int N; cin>>N;
	vector<int> A(N);
	int s = 0;
	for(int i=0; i<N; ++i){
		cin>>A[i];
		s = ((ll)s + A[i]) % MOD;
	}
	s = (ll)s * s % MOD;
	for(int a:A) s = (s - a * (ll)a) % MOD;
	s = (ll)s * ((MOD + 1) / 2) % MOD;
	cout<< ((ll)s + MOD) % MOD <<endl;
}
