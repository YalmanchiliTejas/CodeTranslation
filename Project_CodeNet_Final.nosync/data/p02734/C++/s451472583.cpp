#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

const int mod=998244353;
ll dp[3001][3001];
int n,s;
int a[3001];
int main(){
    cin>>n>>s;
    rep(i,n) cin>>a[i];
    ll ans=0;
    rep(i,n){
        rep(j,s){
            if(j+a[i]<=s){
                dp[i+1][j+a[i]]+=dp[i][j];
                if(j==0) dp[i+1][j+a[i]]+=i+1;
                dp[i+1][j+a[i]]%=mod;
                if(j+a[i]==s){
                    ans+=dp[i+1][j+a[i]]*(n-i);
                    ans%=mod;
                }
            }
            dp[i+1][j]+=dp[i][j];
        }
    }
    cout<<ans<<endl;
    return 0;
}