#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int packSize = 8;
const int packSizeH = 4;

int main(){
	ll s,t;
	ll p,q,M;
	ll y;
	cin>>s>>t;
	cin>>p>>q>>M;
	cin>>y;
	p %= M;
	q %= M;

	// (((x*p+q)*p+q)*p+q)*p+q
	// p^4*x + p^3*q + p^2*q + p*q + q
	// p^4*x + (((p+1)*p+1)*p+1)*q

	ll P = p * p % M * p % M * p % M * p % M * p % M * p % M * p % M;
	ll Q = (((((((p + 1) * p % M + 1) * p % M + 1)* p % M + 1)* p % M + 1)* p % M + 1)* p % M + 1) * q % M;

	ll r[packSize] = {y};
	ll a[packSize] = {0};

	for(int i = 1; i < packSize; ++i){
		a[i] = (a[i-1]*p + q)%M;
	}
	
	const int T = 1e8;
	for(int i = 0; i < T; i+=packSize){
		for(int j = 0; j < packSizeH; ++j){
			r[j] ^= a[j];
			a[j] = (a[j]*P+Q)%M;
 		}
		for (int j = packSizeH; j < packSize; ++j) {
			r[j] ^= a[j];
			a[j] = (a[j]*P+Q)%M;
 		}
	}
	ll res = r[0];
	for(int i = 1; i < packSize; ++i){
		res ^= r[i];
	}
	cout << res << endl;
	return 0;
}

