#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <iomanip>
#include <utility>
using namespace std;
#define ll long long

ll MOD=1000000007;
ll fac[2000010], inv[2000010], finv[2000010];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < 2000010; ++i){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
	ll N, M, K;
	cin >> N >> M >> K;
	COMinit();
	ll r=((N-1)*N*(N+1)/6)%MOD, c=((M-1)*M*(M+1)/6)%MOD;
	for(int i=0; i<2; ++i){
	    r=(r*M)%MOD;
	    c=(c*N)%MOD;
	}
	cout << (((r+c)%MOD)*COM(N*M-2, K-2))%MOD << endl;
	return 0;
}
