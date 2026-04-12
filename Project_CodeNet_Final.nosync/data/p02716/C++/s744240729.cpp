#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pll pair<ll,ll>
#define sll set<ll>
#define mll map<ll,ll>
#define vll vector<ll>
#define vpl vector<pll>
#define gll greater<ll>
#define spl set<pll>
#define lb lower_bound
#define ub upper_bound
#define prq priority_queue
#define mp make_pair
#define pb push_back
#define mem(x,y) memset(x, y, sizeof x)
#define rapido ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
typedef long double ld;
ll mx=INT_MAX;
ll mn=INT_MIN;
ll mod=1e9+7;
const ll maxs=1e6+6;
ll max2d=1e3+3;
ll INF = 9e18;
 
int main(){
    ll N; cin>>N;
    ll a[N+1]; 
    for(ll i=1; i<=N; i++) cin>>a[i];
    ll dp[N+1]; mem(dp, 0);
    ll pref[N+1]; mem(pref, 0);
    pref[1] = a[1]; pref[2] = a[2];
    dp[1] = 0; dp[2] = max(a[1],a[2]);
    for(ll i=3; i<=N; i++){
        pref[i] = a[i] + pref[i-2];
        if(i&1) dp[i] = max(a[i]+dp[i-2] , dp[i-1]); 
        else dp[i] = max(a[i]+dp[i-2] , pref[i-1]);
    }
    cout<<dp[N];
    return 0;
}