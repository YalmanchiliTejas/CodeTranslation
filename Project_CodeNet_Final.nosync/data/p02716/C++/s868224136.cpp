// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define add(x) accumulate(x)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end() 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
const ll mod = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
//
//
                void solve(){
                        ll n;
                        cin>>n;
                        vll vec(n);
                        rep(i,0,n)
                                cin>>vec[i];
                        ll dp[n+1][2]; // 0 means don't include present 1 means including the current index
                        dp[1][0] = vec[0];
                        dp[1][1] = vec[1];
                        dp[0][0] = 0;
                        dp[0][1] = 0;
                        rep(i,2,n){
                                if(i&1){
                                        dp[i][1] = vec[i] + dp[i-1][0];
                                        dp[i][0] = vec[i-1] + dp[i-2][0];
                                }
                                else{
                                        dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
                                        dp[i][1] = vec[i] + max(dp[i-2][0], dp[i-2][1]);
                                        // dp[i] = max(dp[i-2][1] + vec[i], vec[i-1] + dp[i-2][0]);
                                }
                                // cout<<dp[i][0]<<" "<<dp[i][1]<<'\n';
                        }
                        cout<<max(dp[n-1][0], dp[n-1][1]);
                }
                int main(){ 
                        hs;
                        ll t;
                        t=1;
                        // cin>>t;
                        for (int i=1; i<=t; i++){
                                //cout<<"Case #"<<i<<": ";
                                solve();
                         }
        return 0; 
}         
