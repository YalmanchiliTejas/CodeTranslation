#include "bits/stdc++.h"
using namespace std;
#define pb          push_back
#define mp          make_pair
#define ll          long long
#define pii         pair<ll, ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll, ll>
#define mii         map<pii, ll>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (ll)x.size()
#define endl        '\n'
#define hell        1000000007
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define rev(i,a,b)  for(ll i=a;i>=b;i--)

#define bg(i)       i.begin()
#define fset(it,s)   for(auto it = s.begin(); it != s.end(); it++)
 
#define track(x)                 cerr<<#x<<": "<<x<<endl
#define track2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define track3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define track4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
 
#define ed(i)       i.end()
#define mem(a)	    memset(a, 0, sizeof(a))

#define MOD         1000000007
ll mult(ll a,ll b, ll p=MOD){return ((a%p)*(b%p))%p;}
ll add(ll a, ll b, ll p=MOD){return (a + b + p)%p;}
ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; for (; k; k >>= 1LL) {if (k & 1LL) r = mult(r,n,p); n = mult(n,n,p);} return r;}
ll inv(ll a, ll p = MOD) {return fpow(a, p - 2, p);}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
const ll INF = 1e9 + 5;
#define N	    	4000
ll a[N];
ll dp[N][N][2];
bool check[N][N];
pii get(ll l, int r) {
    if(check[l][r]) 
        return mp(dp[l][r][0], dp[l][r][1]);
    check[l][r] = true;
    if(l == r) {
        dp[l][r][0] = a[l];
        dp[l][r][1] = 0;
        return mp(a[l], 0);
    }
    pii aa = get(l+1, r);
    pii bb = get(l, r-1);
    ll v1 = a[l] + aa.y;
    ll v2 = a[r] + bb.y;
    if(v1 > v2) {
        dp[l][r][0] = v1;
        dp[l][r][1] = aa.x;
    }
    else if(v1 < v2) {
        dp[l][r][0] = v2;
        dp[l][r][1] = bb.x;
    }
    else {
        dp[l][r][0] = v1;
        dp[l][r][1] = min(aa.x, bb.x);
    }
    return mp(dp[l][r][0], dp[l][r][1]);
}
void solve(){
    ll n;
    cin>>n;
    rep(i, 0, n)
        cin>>a[i];
    pii tmp = get(0, n-1);

    cout<<tmp.x-tmp.y<<endl;
}
int main() {
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(20);
	cin.tie(0);
	cout.tie(0);
	ll t = 1;
//	cin>>t;
	while(t--){
		solve();
	}
}


