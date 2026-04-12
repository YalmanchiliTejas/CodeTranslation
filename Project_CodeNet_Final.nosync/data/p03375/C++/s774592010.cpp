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
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

ll starling[3333][3333];
ll combination[3333][3333];
ll nijou[3333*3333];
ll n,m;

ll m_pow(ll a,ll b,ll mod = m){
	a %= mod;
	b %= mod;
	ll ret = 1;
	REP(i,60LL){
		if(b & (1LL << i)){
			ret = (ret * a) % mod;
		}
		a = (a * a) % mod;
	}
	return ret % mod;
}

int main()
{
	cin >> n >> m;
	REP(i,3333){
		combination[i][0] = combination[i][i] = 1;
		starling[i][0] = starling[i][i] = 1;
	}
	for(ll i = 0;i < 3333;i++){
		for(ll j = 1;j < i;j++){
			combination[i][j] = (combination[i-1][j-1] + combination[i-1][j]) % m;
			starling[i][j] = (starling[i-1][j-1] + starling[i-1][j] * (j+1))% m;
		}

	}
	nijou[0] = 1;
	REP(i,3333*3333-1)nijou[i+1] = (nijou[i] * 2) % m;
	
	ll ans = 0;
	
	//SHOW2d(starling,10,10);
	//SHOW2d(combination,10,10);
	
	for(ll i = 0;i <= n;i++){
		ll tmp = 0;
		for(ll j = 0;j <= i;j++){
		//	cout << "       "  << starling[i][j] << ' ' << m_pow(2,(n-i)*j) << endl;
			ll hoge = (starling[i][j] * nijou[(n-i)*j]) % m;
		//	cout << ' ' << j << ' ' << hoge << endl;
			tmp = (tmp + hoge) % m;
		}
		//cout << i << ' ' << tmp << endl;
		tmp *= m_pow(2,m_pow(2,n-i,m-1));
		tmp %= m;
		tmp *= combination[n][i];
		tmp %= m;
		if(i % 2 == 0){
		//	cout << '+' << endl;
			ans += tmp;
		}
		else{
		//	cout << '-' << endl;
			ans -= tmp;
			while(ans < 0)ans += m;
		}
		ans %= m;
		//cout << i << ' ' << tmp << endl;
	}
	
	cout << ans << endl;
	
	return 0;
}