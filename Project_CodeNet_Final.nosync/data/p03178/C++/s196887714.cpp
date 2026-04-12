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

ll dp[10005][105][2],d,n;
string s;

ll f(ll cur, ll sum, ll flag) {
	if(cur == n) {
		return !sum;
	}
	if(dp[cur][sum][flag] != -1)
		return dp[cur][sum][flag];
	ll ret = 0;
	if(flag) {
		int rem = s[cur]-'0';
		fori(i,0,rem-1,1) {
			ret = (ret+f(cur+1,(sum+i)%d,0))%mod;
		}
		ret = (ret+f(cur+1,(sum+rem)%d,1))%mod;
	} else {
		fori(i,0,9,1) {
			ret = (ret+f(cur+1,(sum+i)%d,0))%mod;
		}
	}
	return dp[cur][sum][flag] = ret;
}

int main() {
	IOS
	reset(dp,-1);
	cin >> s >> d;
	n = sz(s);
	ll ans = f(0,0,1)-1;
	cout << (ans+mod)%mod << endl;
}
