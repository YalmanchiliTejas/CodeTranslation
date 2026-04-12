#include <bits/stdc++.h>
#include <atcoder/all>
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
using namespace atcoder;

ll f(ll a,ll b){return max(a,b);}
ll e(){return -1LL;};
ll z;
bool b(ll a){return a<z;}

void solve(){
	int n,q;
	cin>>n>>q;
	vector<ll>a(n);
	rep(i,n)cin>>a[i];
	segtree<ll,f,e>tree(a);
	while(q--){
		int t,x,y;
		cin>>t>>x>>y;
		if(t==1){
			x--;
			tree.set(x,y);
		}
		else if(t==2){
			x--;
			cout<<tree.prod(x,y)<<"\n";
		}
		else{
			x--;
			z=y;
			int id=tree.max_right<b>(x);
			cout<<id+1<<"\n";
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
