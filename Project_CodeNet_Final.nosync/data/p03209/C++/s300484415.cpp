#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll bur[51], pat[51];

ll solve(int n, ll x){
	if(x < 1){
		return 0;
	}
	if(x == 1){
		if(n == 0) return 1;
		return 0;
	}
	if(x <= 1 + bur[n-1]){
		return solve(n-1, x-1);
	}
	if(x == 2 + bur[n-1]){
		return pat[n-1] + 1;
	}
	if(x <= 2 + 2 * bur[n-1]){
		return solve(n-1, x - 2 - bur[n-1]) + pat[n-1] + 1;
	}
	if(x == 3 + 2 * bur[n-1]){
		return 2 * pat[n-1] + 1;
	}
	return 0;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	ll x;
	cin >> n >> x;
	bur[0] = 1;
	pat[0] = 1;
	for(int i = 1; i <= 50; ++i){
		bur[i] = 3 + 2 * bur[i-1];
		pat[i] = 1 + 2 * pat[i-1];
	}
	ll ans = solve(n, x);
	cout << ans << endl;
	return 0;
}
