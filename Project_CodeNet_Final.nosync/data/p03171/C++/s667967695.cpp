#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
#define pof pop_front
#define pob pop_back
#define mp make_pair
#define pll pair<ll,ll>
#define pii pair<int,int>
#define all(s) s.begin(),s.end()
#define vll vector<ll>
#define vi vector<int>
#define vpii vector<pii>
#define vpll vector<pll>
#define vd vector<double>
#define vull vector<ull>
#define vc vector<char>
#define vs vector<string>
#define fi first
#define se second
#define sz(x) x.size()
#define cinarr(n,a) for(int i = 0; i < n; i++) cin >> a[i];
#define coutarr(n,a) for(int i = 0; i < n; i++) cout << a[i] << (i+1==n?'\n':' ');
#define fori(i,a,b,x) for(int i = a; i <= b; i+=x)
#define ford(i,a,b,x) for(int i = a; i >= b; i-=x)
#define tc int t; cin >> t; for(int cs = 1; cs <= t; cs++)
#define IOS ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ld long double
#define reset(x,y) memset(x,y,sizeof x);
#define sqr(x) 1LL*(x)*(x)
#define cube(x) 1LL*(x)*(x)*(x)
#define ub(v, a) upper_bound(all(v), a)
#define lb(v, a) lower_bound(all(v), a)
#define EPS 1e-10
#define INF 2000000000
#define mod 1000000007
#define minof(a) min_element(all(a))
#define maxof(a) max_element(all(a))
#define debug(val) cerr << "The value of " << #val << " is = " << val << endl;
#define testing cerr << "--------------------------\n";

//input space ---> scanf("%[^\n]%*c",s);

ll n,a[3005],sum,dp[3005][3005],vis[3005][3005];

ll f(ll l, ll r) {
	if(l+1 == r) {
		return max(a[l],a[r]);
	}
	if(l == r) {
		return a[l];
	}
	if(vis[l][r])
		return dp[l][r];
	ll ret = -INF;
	ll add = min(f(l+1,r-1),f(l+2,r));
	ret = max(ret,a[l]+add);
	add = min(f(l,r-2),f(l+1,r-1));
	ret = max(ret,a[r]+add);
	vis[l][r] = 1;
	return dp[l][r] = ret;
}

int main() {
	IOS
	cin >> n;
	fori(i,0,n-1,1) {
		cin >> a[i];
		sum += a[i];
	}
	ll X = f(0,n-1);
	cout << 2*X - sum << endl;
}
