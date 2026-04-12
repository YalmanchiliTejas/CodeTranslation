#include<bits/stdc++.h>
#define ll long long int 
#define double /*long*/ double
#define endl '\n'
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define vppll vector<pair<pll,pll>>
#define mp make_pair
#define pb push_back
#define mapll map<ll,ll>
#define fir first
#define sec second
#define _cin ios_base::sync_with_stdio(0);  cin.tie(0);
#define fo(i,b) for(i=0;i<b;i++)
#define repa(i,a,b) for(i=a;i<b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define all(x) (x).begin(), (x).end()
#define s(v) v.size()
const long long int MAX = (ll)(1e16+1);
const long long int MIN = (ll)(-1e16-1);
const long long int mod = (ll)(1e9+7);
using namespace std;

ll max(ll a,ll b,ll c) {return max(max(a, b), c);}
ll min(ll a,ll b,ll c) { return min(min(a, b), c);}
ll max(ll a,ll b) {return (a>b) ? a : b;}
ll min(ll a,ll b) {return (a<b) ? a : b;}
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power_mod(ll a, ll n, ll mod_){ ll p=1; while(n){ if(n%2){ p=(p*a)%mod_;} n/=2; a=(a*a)%mod_;} return p%mod_;}
                                                 /*Code Begins*/
pll dp[3002][3002]; //1-> Max, 2->Min
vll a;

pll count(ll x, ll y){
    if(dp[x][y] != mp(MIN,MAX)) return dp[x][y];
    pll p1 = count(x+1,y);
    pll p2 = count(x,y-1);
    dp[x][y].first = max(p1.second+a[x] , p2.second+a[y]);
    dp[x][y].second = min(p1.first-a[x] , p2.first-a[y]);
    return dp[x][y];
}

int main(){
    _cin;
    cout << setprecision(22);
    ll mn = MAX, mx = MIN;
    ll n, t, m, k, i, j,  sum=0,  prev, flag=0, cnt=0;
    ll x=0, y=0, fx, diff, tot=0, l , r;
    int TC=1;
    // cin >> TC;
while(TC--){
    cin >> n;
    a.assign(n+1,0);
    fo(i,n) cin >> a[i+1];

    fo(i,3002) fo(j,3002) dp[i][j]={MIN,MAX};
    fo(i,n+1) dp[i][i]=(n%2) ? mp(a[i],a[i]) : mp(-a[i],-a[i]);
    dp[3001][3001]=mp(0,0);
    pll p = count(1,n);
    // repa(i,1,n+1){
    //     repa(j,i,n+1) cout << dp[i][j].first << ',' << dp[i][j].second << ' ';
    //     cout << endl;
    // }
    // cout << dp[1][1].first << endl;
    cout << p.first;

}
 return 0;      
}