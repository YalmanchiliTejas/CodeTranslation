#define _CRT_SECURE_NO_WARNINGS
#include"bits/stdc++.h"
#ifdef _DEBUG
#define DBG(n) n
#else
#define DBG(n)
#endif
#define INF            1e9
#define INFLL          1e18
#define EPS            1e-9
#define REP(i,n)       for(ll i=0,i##_len=(n);i<i##_len;++i)
#define REP1(i,n)      for(ll i=1,i##_len=(n);i<=i##_len;++i)
#define REPR(i,n)      for(ll i=(n)-1;i>=0;--i)
#define REPR1(i,n)     for(ll i=(n);i>0;--i)
#define REPC(i,obj)    for(auto i:obj)
#define ALL(obj)       (obj).begin(),(obj).end()
#define SETP(n)        cout<<fixed<<setprecision(n)
#define VV(T,h,w)      move(vector<vector<T>>(h,vector<T>(w)))
#define VVI(T,h,w,i)   move(vector<vector<T>>(h,vector<T>(w,i)))
using namespace std;
using ll = long long;
template<typename T, ll h, ll w>using vec2 = vector<vector<T>>;
template<typename T = ll>inline T in() { T ret; cin >> ret; return ret; }

signed main()
{
	ll n;
	for (ll h = 0; n = in(); ++h) {
		if (h != 0)cout << endl;
		vector<string>name(n);
		vector<pair<ll, ll>>point(n);
		REP(i, n) {
			ll w, l, d;
			cin >> name[i] >> w >> l >> d;
			point[i] = make_pair(w * 3 + d, -i);
		}
		sort(ALL(point), greater<pair<ll, ll>>());
		REPC(i, point) cout << name[-i.second] << ',' << i.first << endl;
	}
}
