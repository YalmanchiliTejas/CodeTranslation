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
#define SETP(n)     cout<<fixed<<setprecision(n)
using namespace std;
using ll = long long;
template<typename T = ll>inline T in() { T ret; cin >> ret; return ret; }

ll mypow(ll b, ll i)
{
	return i == 0 ? 1 : i % 2 == 0 ? mypow(b * b, i / 2) : b * mypow(b, i - 1);
}
ll len(ll lv)
{
	return mypow(2, lv + 2) - 3;
}
ll pat(ll lv)
{
	return mypow(2, lv + 1) - 1;
}
ll eatable(ll lv, ll x)
{
	if (x <= 0) {
		return 0;
	} else if (lv == 0) {
		return 1;
	} else {
		ll ret = 0, lv_len_1 = len(lv - 1);
		x -= 1;
		if (x < lv_len_1) {
			ret += eatable(lv - 1, x);
		} else {
			ret += pat(lv - 1);
			x -= lv_len_1;
			if (x > 0) {
				ret += 1;
				x -= 1;
				ret += eatable(lv - 1, x);
			}
		}
		return ret;
	}
}
signed main()
{
	ll lv = in(), x = in();
	cout << eatable(lv, x) << endl;
}