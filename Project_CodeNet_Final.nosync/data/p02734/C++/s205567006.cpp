#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int s;
const int nax=3005;
ll mod=998244353;
int a[nax];
inline ll adds(ll a, ll b){
    a+=b;
    if(a>=mod) a-=mod;
    return a;
} 
ll fun(int st, int end){
    if(st == end){
        return a[st]==s;
    }
    int mid=(st+end)/2;
    ll ans=(fun(st,mid)+fun(mid+1,end))%mod;
    int n=end-st+1;
    ll dp[n][s+1];

    for(int i=mid+1;i<=end;i++){
        for(int j=0;j<=s;j++){

            if(j==0){
                dp[i-st][j]=1; continue;
            }
            if(i==mid+1){
                if(a[i]==j) dp[i-st][j]=1;
                else dp[i-st][j]=0;
            }
            else{
                dp[i-st][j]=adds(dp[i-1-st][j],(a[i]<=j ? dp[i-1-st][j-a[i]] : (ll)0));
            }
        }
    }
    for(int i=mid;i>=st;i--){
        for(int j=0;j<=s;j++){
            if(j==0){
                dp[i-st][j]=1; continue;
            }
            if(i==mid){
                if(a[i]==j) dp[i-st][j]=1;
                else dp[i-st][j]=0;
            }
            else{
                dp[i-st][j]=adds(dp[i+1-st][j],(a[i]<=j ? dp[i+1-st][j-a[i]] : (ll)0));
            }
        }
    }
    ll t1[s+1]={0};
    for(int j=0;j<=s;j++){
        for(int i=mid+1;i<=end;i++){
            t1[j]=adds(t1[j],dp[i-st][j]);
        }
    }
    for(int j=0;j<=s;j++){
        ll g=0;
        for(int i=mid;i>=st;i--){
            g=adds(g,dp[i-st][j]);
        }
        ans=adds(ans, (g*t1[s-j])%mod );
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n>>s;
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<fun(0,n-1)<<"\n";
}
