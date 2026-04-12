#include<iostream>
#include<vector>
#include<string>

#define rep(i, n) for(int i = 0; i < (n); i++)
using ll = long long;
const ll mod = 1000000007;

int main(){
	int N;
	std::cin >> N;
	std::vector<ll> A(N);
	std::vector<ll> c(N);
	rep(i, N) std::cin >> A[i];

	if(N == 2){
		std::cout << A[0] * A[1] % mod << std::endl;
		return 0;
	}

	c[N-2] = A[N-1];
	for(int i=N-3; i>=0; i--){
		c[i] = c[i+1] + A[i+1];
		c[i] %= mod;
	}

	ll res = 0;
	rep(i, N-1){
		res += (A[i] * c[i]);
		res %= mod;
	}
	std::cout << res << std::endl;
	return 0;
	
}