#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T> ll size(const T& x) { return x.size(); }
#define rep(i,a,b) for(ll i = (a); i < (b); ++i)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end(); ++it)
#define pb push_back
#define fs first
#define sc second
#define MOD 1000000007
#define MOD2 998244353
#define INF 1000000000000000000ll
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

void solve()
{
    ll n;
    cin >> n;
    vi A(n);
    rep(i,0,n)
    {
        cin >> A[i];
    }
    vi P(n+1, 0);
    rep(i,0,n)
    {
        P[i+1] = (P[i] + A[i]) % MOD;
    }
    ll ans = 0;
    //cout << smod(4,6) << endl;
    rep(i,0,n)
    {
        ans = (ans + ((A[i]*(P[n] - P[i+1])) % MOD) ) % MOD;
        ans = (ans + MOD) % MOD;
    }
    cout << ans % MOD << endl;
}

int main()
{
    cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	/*ll t;
	cin >> t;
	while(t--)*/
		solve();
}
