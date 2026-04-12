#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,n) for(int i = 1; i <= n; i++)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)
#define rreps(i,n) for(int i = n; i >= 1; i--)
#define mrep(i,from,n) for(int i = from; i < n; i++)
#define mreps(i,from,n) for(int i = from; i <= n; i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define ERASE(x,val) x.erase(remove(ALL(x), val), x.end())
typedef long long ll;
typedef pair<ll, ll> P;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
ll mod = 1000000007;

vector<ll> n_tot, n_p;
ll rec(ll n,ll x)
{
	if(n==0 && x==1)return 1;
	if(x==0 || x==1)return 0;
	else if(x <= 1+n_tot[n-1]) return rec(n-1,x-1);
	else if(x==2+n_tot[n-1]) return n_p[n-1]+1;
	else if(x < n_tot[n])return n_p[n-1]+1+rec(n-1,x-n_tot[n-1]-2);
	else return n_p[n];
}

void solve()
{
	int n; cin >> n;
	ll x; cin >> x;
	n_tot.resize(n+1);
	n_p.resize(n+1);
	rep(i, n+1)n_tot[i]=((4LL<<i)-3);
	rep(i, n+1)n_p[i]=((2LL<<i)-1);
	ll ans = rec(n,x);
	cout << ans << endl;
	return;	
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
