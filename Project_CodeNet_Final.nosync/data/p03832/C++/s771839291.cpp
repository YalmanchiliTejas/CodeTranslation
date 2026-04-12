#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <list>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
int n, a, b, c, d;
ll D[1010][1010];
ll C[2010][2010];

ll pw(ll x, ll y){
	ll res = 1;
	while(y){
		if(y & 1)res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

ll R[1010];

void solve(){
	for(int i=1;i<1010;i++)R[i] = pw(i, MOD-2);
	C[0][0] = 1;
	for(int i=1;i<2010;i++){
		C[i][0] = 1;
		for(int j=1;j<=i;j++){
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
		}
	}
	scanf("%d%d%d%d%d", &n, &c, &d, &a, &b);
	D[c-1][0] = 1;
	for(int i=c;i<=d;i++){
		for(int j=0;j<=n;j++){
			D[i][j] = D[i-1][j];
			ll T = 1;
			for(int k=i;k<=j && k<=i*b;k+=i){
				T = T * C[j-k+i][i] % MOD;
				T = T * R[k/i] % MOD;
				if(k >= i*a)D[i][j] = (D[i][j] + T * D[i-1][j-k]) % MOD;
			}
		}
	}
	printf("%lld", D[d][n]);
}

int main(){
	int Tc = 1;// scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}