#include <bits/stdc++.h>
#define ll long long
const ll MOD = 1e9 + 7;
using namespace std;
int main(){
	int N;
	cin >> N;
        ll pairs[N];	
	for(int i = 0; i < N; ++i){
		cin >> pairs[i];
	}
	ll Sum1 = pairs[N-1] % MOD;
	ll Sum2 = 0;
	for(int i = N-2; i >= 0; --i){
		Sum2+=((pairs[i]%MOD)*(Sum1%MOD))%MOD;
		Sum1+=pairs[i]%MOD;
	}
	cout << Sum2 % MOD;
}
