#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
ll mx(ll a,ll b){if(a>=b) return a;return b;}
ll mn(ll a,ll b){if(a<b) return a;return b;}
#define pb push_back
#define mp make_pair
#define endl "\n"
#define INF (ll) (3e18)
ll dp[3005][3005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vi v;
    ll n,x;cin>>n;
    for(ll i=0;i<n;i++)
        cin>>x,v.pb(x);
    for(ll i=n-1;i>=0;i--)
        for(ll j=i;j<n;j++){
            if(i==j)
                dp[i][j]=v[i];
            else
                dp[i][j]=mx(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
        }
    cout<<dp[0][n-1]<<endl;
    return 0;
}



