#include <bits/stdc++.h>
using namespace std;
    
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n) for (int i = 0; i < n; i++)
#define repn(i, a, b) for (int i = a;i<=b;i++)
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(x) memset(x, 0, sizeof(x))
#define ritr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define pai pair < int, int> ;
#define pal pair < ll, ll> ;
#define vi vector <int> ;
#define vl vector < ll > ;
#define vpai vector < pii > ;

const int mod = 1e9+7;
const int INF = INT_MAX;
const int sze = 3005;

ll dp[sze][sze];

void solve() {
    mem(dp);
    int n;
    cin>>n;
    ll arr[n];
    ll sum=0;
    rep(i,n) {
        cin>>arr[i];
        sum+=arr[i];
    }
    rep(i,n) dp[i][i]=arr[i];
    rep(i,n-1){
        dp[i][i+1]=max(arr[i],arr[i+1]);
    }

    // rep(i,n){
    //     rep(j,n){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    repn(len,3,n){
        for(int i=0;i<=n-len;i++){
            int j=i+len-1;
            ll x=dp[i+2][j];
            ll y=dp[i+1][j-1]; 
            ll z=dp[i][j-2];
            dp[i][j]=max(arr[i]+min(x,y),arr[j]+min(y,z));
            // cout<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<len<<endl;
        }
    }

    cout<<-sum+2*dp[0][n-1]<<endl;
}


int main() {
    IOS;

    int t = 1;
    //cin >> t;
    while (t--) {
       solve();
    }

  return 0;
}