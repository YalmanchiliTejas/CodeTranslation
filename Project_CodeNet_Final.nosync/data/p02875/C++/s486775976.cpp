#include <bits/stdc++.h>
using namespace std;
#define int long long
#define p 998244353

int MOD(int a){
	return (a %= p) >= 0 ? a : a + p;
}

int power(int a, int N){
	if(N == 0) return 1;
	else if(N % 2 == 0) return power(MOD(a * a), N / 2);
	else return MOD(a * power(a, N - 1));
}

int inverse(int a){
	return power(a, p - 2);
}

int fact(int N){
	static vector<int> _fact(1, 1);
	for(int i = _fact.size(); i <= N; i++){
		_fact.push_back(MOD(i * _fact[i - 1]));
	}
	return _fact[N];
}
 
int fact_inv(int N){
	static vector<int> inv(2, 1), _fact_inv(2, 1);
	for(int i = inv.size(); i <= N; i++){
		inv.push_back(MOD(-(p / i) * inv[p % i]));
		_fact_inv.push_back(MOD(inv[i] * _fact_inv[i - 1]));
	}
	return _fact_inv[N];
}
 
int combination(int N, int k){
	if(k < 0 || N < k || N < 0) return 0;
	else return MOD(fact(N) * MOD(fact_inv(N - k) * fact_inv(k)));
}

signed main(){
	int N, i, ans = 0;
	scanf("%lld", &N);
	vector<int> pow2(N + 1, 1);
	for(i = 1; i <= N; i++){
		pow2[i] = MOD(2 * pow2[i - 1]);
	}
	for(i = N / 2 + 1; i <= N; i++){
		ans = MOD(ans + combination(N, i) * pow2[N - i]);
	}
	printf("%lld\n", MOD(power(3, N) - 2 * ans));
	return 0;
}