#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
const ll mod = 1e9+7;
#define rep(i,a,b) for(ll i=a;i<b;i++)

void swap(ll &a , ll &b){
    ll t = a;
    a = b;
    b = t;
}

ll min(ll a, ll b){
    if(a<b)return a;
    return b;
}

ll max(ll a, ll b){
    if(a>b)return a;
    return b;
}

 ll pow(ll a, ll b) {
    a %= mod;
    ll ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

const int MAX = 1e5+3;

vector<ll> vp[MAX];

ll indegree[MAX];

int main(){

  
   ios_base :: sync_with_stdio(0);
   cin.tie(0);
   ll n;
   cin>>n;
   ll a[n];
   ll total = 0;
   rep(i , 0 ,n){
    cin>>a[i];
    total += a[i];
   }

   ll dp[n+1][n+1];
   memset(dp ,0  ,sizeof(dp));
   for(int i = 0 ; i <n;i++){
        dp[i+1][i+1] = a[i];
        if(i+2 <= n)
            dp[i+1][i+2] = max(a[i],a[i+1]);
   }

   ll t1,t2;
   for(int len = 3;len<=n;len++){
        /// i....j -> i or j
        for(int i = 1 ; i <= n;i++){
            int j = i+(len-1);
            if(j >n)break;
            t1 = a[i-1]+min( dp[i+2][j],dp[i+1][j-1]);
            t2 = a[j-1]+min( dp[i][j-2] , dp[i+1][j-1]  );
            dp[i][j] = max(t1,t2);
           // cout<<" for i = "<<i<<" j = "<<j<<" val = "<<dp[i][j]<<endl;
        }
   }
   total = (total-dp[1][n]);

    cout<<dp[1][n]-total;

}
