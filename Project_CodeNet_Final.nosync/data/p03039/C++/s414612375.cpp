#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <array>
#include <random>
#include <chrono>
#include <algorithm>
 
uint64_t mod = 1000 * 1000 * 1000 + 7;
static int pow(uint64_t x, uint64_t n){
	uint64_t ans=1;
	while(n){
		if(n%2){
			ans *= x;
			ans %= mod;
			n-=1;
		}
		x *= x;
		x %= mod;
		n/=2;
	}
	return ans;
}
int main(void){
	uint64_t n, m, k;
	std::cin >> n >> m >> k;
	uint64_t sq = n * m;
	uint64_t combination = 1;
	uint64_t x = 0;
	for(int i=1;i<n;i++){
		x+=m * m * (n-i)*i;
		x %=mod;
	}
	for(int i=1;i<m;i++){
		x+=n*n*(m-i)*i;
		x %= mod;
	}
	uint64_t C = 1, O=1, M=1;
	for(int i=1;i<=n*m-2;i++){
		C *= i;
		C %= mod;
	}
	for(int i=1;i<=k-2;i++){
		O*=i;
		O %= mod;
	}
	O = pow(O, mod - 2);
	for(int i=1;i<=n*m - k;i++){
		M *= i;
		M %= mod;
	}
	M = pow(M, mod - 2);
	x*=C;
	x %= mod;
	x*= O;
	x %= mod;
	x*= M;
	x %= mod;
	std::cout << x << std::endl;
}
