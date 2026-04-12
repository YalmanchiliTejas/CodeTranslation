#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fi first
#define se second
#define debug(x) cerr << " - " << #x << ": " << x << endl;
#define debugs(x, y) cerr << " - " << #x << ": " << x << " " << #y << ": " << y << endl;
#define debugii(x) cerr << " - " << #x << ": " << x.fi<<","<<x.se << endl;
#define sep() cerr << "--------------------" << endl;
#define all(x) (x).begin(),(x).end()
#define sz(x) (ll)x.size()
#define ll long long
#define ii pair<ll,ll>
#define v vector<ll>
#define vii vector<ii>
#define vv vector<vector<ll> >
#define mp make_pair
#define INF 1000000000
#define pb push_back
#define EPS 1e-9
const ll MOD = 1000000007; // 998244353
ll n,a[3001],dp[2][3001][3001];
ll solve(ll turn,ll l,ll r){
    if(l>r)return 0;
    if(dp[turn][l][r]!=-1)
        return dp[turn][l][r];
    ll ans;
    if(!turn){
        ans=a[r]+solve(1-turn,l,r-1);
        ans=max(ans,a[l]+solve(1-turn,l+1,r));
    }
    else{
        ans=-a[r]+solve(1-turn,l,r-1);
        ans=min(ans,-a[l]+solve(1-turn,l+1,r));
    }
    return dp[turn][l][r]=ans;
}
int main(){
    boost;
    memset(dp,-1,sizeof dp);
    cin>>n;
    for (ll i = 0; i < n; ++i)
        cin>>a[i];
    cout<<solve(0,0,n-1);
    return 0;
}
//long long
//array bounds
//special cases
//binary search