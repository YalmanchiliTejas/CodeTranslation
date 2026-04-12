#include <bits/stdc++.h>

#define f(i,a,b) for( ll i = a; i < b ; i++ ) 
#define af(i,a,b) for( ll i = a; i >= b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(a) (ll) a.size()
#define all(a) a.begin(), a.end()
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define inter ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
 
const ll MAX = 1e5+10;

ll dp[10010][100][2],pot[MAX],mod = 1e9+7;
string s;
ll d;

ll DP(ll n,ll r,ll f){
	if(n<0 && r == 0) return 1;
	if(n<0 && r!=0) return 0;
	ll &ans = dp[n][r][f];
	if(ans!=-1) return ans;
	ans = 0;

	f(i,0,10){
		ll x = (r - i%d +d)%d;
		if(f == 1 && s[n]-'0' == i){
			ans += DP(n-1,x,1);
			break;
		}
		ans+=DP(n-1,x,0);
	} 
	return ans%=mod;
}



int main(){
	cin >> s >> d;

	memset(dp, -1,sizeof dp);

	reverse(all(s));
	cout << (DP(s.size()-1,0,1) +mod-1)%mod << endl;
}
