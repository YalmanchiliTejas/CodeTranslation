#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end() 
#define MOD 998244353

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const ll INF=LLONG_MAX;
const int mxn=3003;
int a[mxn];

void add(ll &a, ll b){
	a%=MOD; b%=MOD; a+=b; a%=MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n,s;
	cin >> n >> s;
	for(int i=1; i<=n; i++)cin >> a[i];
	vector<ll>dp(s+1);
	ll ans = 0LL;
	for(int i=1; i<=n; i++){
		vector<ll>now(s+1);
		for(int j=0; j<=s; j++){
			add(now[j],dp[j]);
			if(j>=a[i])add(now[j],dp[j-a[i]]);
		}
		if(a[i]<=s)add(now[a[i]],i);
		add(ans, now[s]);
		dp = now;
	}
	cout << ans << endl;
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
