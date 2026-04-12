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
	ll n = in();
	vector<ll>a(n);
	REPC(&i, a)i = in();
	sort(ALL(a), greater<ll>());
	deque<ll>first(a.begin(), a.begin() + n - n / 2), second(a.end() - n / 2, a.end());
	ll ans = 0;
	if (n % 2 == 0) {
		REPC(i, first)ans += i * 2;
		ans -= first.back();
		REPC(i, second)ans -= i * 2;
		ans += second.front();
	} else {
		REPC(i, first)ans += i * 2;
		ans -= *(first.end() - 1);
		ans -= *(first.end() - 2);
		REPC(i, second)ans -= i * 2;
		ll foo = 0;
		second.push_front(first.back());
		first.pop_back();
		REPC(i, first)foo += i * 2;
		REPC(i, second)foo -= i * 2;
		foo += *(second.begin());
		foo += *(second.begin() + 1);
		ans = max(ans, foo);
	}
	cout << ans << endl;
}