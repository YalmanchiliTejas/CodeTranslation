#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll modpow(ll a, ll b){

    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b=b/2;
    }
    return ans;
}

int inp[3010];

ll dp[3010][3010];

int main(){

    int n;

    cin>>n;

    for(int i = 0; i < 3010; i++) {
        for(int j = 0; j < 3010; j++) {
            dp[i][j] = -1000000000000000000ll;
        }
    }
    
    for(int i = 0; i < n; i++) {
        cin>>inp[i];
        dp[i][i] = inp[i];
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= n - i; j++) {
            int st = j;
            int end = j + i - 1;

            dp[st][end] = max(dp[st][end], inp[st] - dp[st+1][end]);
            dp[st][end] = max(dp[st][end], inp[end] - dp[st][end-1]);

        }
    }

    cout<<dp[0][n-1]<<endl;


}
