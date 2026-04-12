#include <bits/stdc++.h>
//#include <atcoder/all>
#define rep(i, a) for (int i = (int)0; i < (int)a; ++i)
#define rrep(i, a) for (int i = (int)a - 1; i >= 0; --i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define RREP(i, a, b) for (int i = (int)a - 1; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define popcount __builtin_popcount
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;

// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
template <class T>
inline bool chmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}

ll gcd(ll n, ll m)
{
	ll tmp;
	while (m != 0)
	{
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m)
{
	return abs(n) / gcd(n, m) * abs(m); //gl=xy
}

using namespace std;
//using namespace atcoder;

void solve(){
	ll n,x,m;
	cin>>n>>x>>m;
	vector<ll>a(m+5),sum(m+5),used(m+5);
	ll ans=0;
	a[1]=x;
	sum[1]=x;
	ll loop=1;
	int pos=0;
	for(int i=2;i<=n;++i){
		x*=x;
		x%=m;
		a[i]=x;
		sum[i]=sum[i-1]+a[i];

		if(n==i){
			cout<<sum[n];
			return;
		}

		if(used[a[i]]>0){
			pos=used[a[i]];
			loop=i-used[a[i]];
			break;
		}
		used[a[i]]=i;
	}
	ll len=(n-pos)/loop;
	ans+=len*(sum[pos+loop]-sum[pos]);
	ans+=sum[n-len*loop];
	cout<<ans;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
