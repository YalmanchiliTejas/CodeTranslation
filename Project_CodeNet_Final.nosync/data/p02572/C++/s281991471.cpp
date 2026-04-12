/**
 *	@file: C.cpp
 *	@author: Huy Le
 *	@created: 2020-08-29 19:25
**/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int)(x).size()
const char newl = '\n';

void DEBUGLOCAL() { cerr << ")" << newl; }
template<class A, class... B> 
void DEBUGLOCAL(A argc, B... argv) {
	cerr << argc;
	if(sizeof...(argv))
		cerr << ", ";
	DEBUGLOCAL(argv...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") [" << __FUNCTION__ << "] -> (" << #__VA_ARGS__ << "): (",DEBUGLOCAL(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

int ts;
int n;
const ll MOD = 1e9+7;
const int mxN = 2e5+5;
ll a[mxN];
ll dp[mxN];

void solve() {
    cin >> n;
    ll sum = 0;

    for(int i=0; i<n; ++i) {
        cin >> a[i];
        sum += a[i]%MOD;
        dp[i] = sum %MOD;
    }
    ll ans = 0;
    for(int i=n-1; i>=0; --i) {
        ans += a[i] * dp[i-1] %MOD;
        ans %= MOD;
    }
    cout << ans << newl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

		//++i,cout << "Case #" << i << ": ",
		solve();
}
