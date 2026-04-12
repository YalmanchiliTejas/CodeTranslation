// C - Sum of product of pairs
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N; cin>>N;
	int MOD = (1e9) + 7;
	int64_t ans = 0, b = 0;
	for(int i=0; i<N; ++i){
		int a; cin>>a;
		ans += a * b % MOD;
		b += a;
		b %= MOD;
	}
	cout<< (ans + MOD) % MOD <<endl;
}
