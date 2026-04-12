#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int mod=998244353;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,s;cin >> n >> s;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ll dp[n+1][s+1]={};
    for(int i=0;i<n;i++){
        if(a[i]<=s){
            (dp[i+1][a[i]]+=i+1)%=mod;
        }
        for(int j=1;j<s;j++){
            (dp[i+1][j]+=dp[i][j])%=mod;
            if(j+a[i]<=s){
                (dp[i+1][j+a[i]]+=dp[i][j])%=mod;
            }
        }
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        (ans+=dp[i][s]*(n+1-i)%mod)%=mod;
    }
    cout << ans << endl;
}