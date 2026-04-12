// C - Sum of product of pairs
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N; cin>>N;
	vector<int> A(N);
	int64_t sum_a = 0;
	for(int i=0; i<N; ++i){
		cin>>A[i];
		sum_a += A[i];
	}
	int MOD = (1e9) + 7;
	int64_t ans = 0;
	for(int a:A){
		sum_a -= a;
		sum_a %= MOD;
		ans += sum_a * a % MOD;
		ans %= MOD;
	}
	cout<< (ans + MOD) % MOD <<endl;
}
