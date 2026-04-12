#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define ld long double
typedef pair<ll,ll> pll;
typedef pair<pll,pll> ppll;
typedef vector <ll> vi;
#define out(x) return cout<<x,0;
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define lc(n) 2*n+1
#define rc(n) 2*n+2
#define fill(a,b) memset((a),(b),sizeof((a)))
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL)); 
const ll M = 105;
string s;
ll n, k;
ll dp[M][M][2];
vi v;

ll slove( ll pos , ll check , ll cnt ){
	if( cnt > k ) return 0;

	if(pos == v.size()){
		if(cnt == k) return 1;
		else return 0;
	}

	if(dp[pos][cnt][check] != -1) return dp[pos][cnt][check];

	ll res=0;
	ll limit;

	if(check == 0)
		limit = v[pos];
	else
		limit = 9;

	for(ll d = 0 ; d <= limit ; d ++ ){
		ll nck = check;
		ll nt = cnt;
		if(check == 0 && d < limit) nck=1;

		if(d > 0) nt++;
		if(nt <= k) res += slove(pos+1 , nck , nt);
	}
	return dp[pos][cnt][check] = res;
}

int main() {
    FAST;
    ll x = 0, y = 0, i, t, ans = 0, j, c = 0, z = 0, m;
    cin >> s >> k;
    n = s.size();
    fill(dp , -1);
    for( i = 0 ; i < n ; i ++ )
		v.pb(s[i]-'0');
	
    cout << slove(0 , 0 , 0);
}