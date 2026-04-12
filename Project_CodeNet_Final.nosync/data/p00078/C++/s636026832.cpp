#define _CRT_SECURE_NO_WARNINGS
#include"bits/stdc++.h"
#ifdef _DEBUG
#define DBG(n) n
#else
#define DBG(n)
#endif
#define INF         1e9
#define INFLL       1e18
#define EPS         1e-9
#define REP(i,n)    for(ll i=0,i##_len=(n);i<i##_len;++i)
#define REP1(i,n)   for(ll i=1,i##_len=(n);i<=i##_len;++i)
#define REPR(i,n)   for(ll i=(n)-1;i>=0;--i)
#define REPR1(i,n)  for(ll i=(n);i>0;--i)
#define REPC(i,obj) for(auto i:obj)
#define ALL(obj)    (obj).begin(),(obj).end()
#define SETP(n)     cout << fixed << setprecision(n)
using namespace std;
using ll = long long;
template<typename T = ll>inline T in() { T ret; cin >> ret; return ret; }

signed main()
{
	ll n;
	while (n = in()) {
		vector<vector<ll>>mag(n, vector<ll>(n, 0));
		ll x = n / 2 - 1, y = n / 2;
		REP1(i, n * n) {
			x++; x %= n;
			y++; y %= n;
			while (mag[y][x] != 0) {
				x += n - 1; x %= n;
				y++; y %= n;
			}
			mag[y][x] = i;
		}
		REP(i, n) {
			REP(j, n) {
				printf("%4lld", mag[i][j]);
			}
			cout << endl;
		}
	}
}
