#include <bits/stdc++.h>

using namespace std;

#define DBG cerr << '!' << endl;
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(ll (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(ll (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(10)
#define INF 1000000000

typedef long long ll;
typedef pair<ll,ll> P;

int main()
{
	ll n,k;cin >> n >> k;
	ll ans = 0;
	
	for(ll i = k+1;i <= n;i++)
	{
		ll tmp = n % i;
		if(tmp > 0)
		{
			ans += max(tmp - k + 1,0LL);
			if(k == 0)ans--;
		}
		ans += max(0LL,(n / i)*(i - k));
	}
	
	cout << ans << endl;
	
	return 0;
}