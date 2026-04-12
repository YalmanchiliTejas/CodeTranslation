#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
const int MOD=998244353;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,s;cin >> n >> s;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<ll> dp(s+1);
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=s-1;j>=0;j--){
            if(j+a[i]<=s){
                (dp[j+a[i]]+=dp[j])%=MOD;
            }
        }
        if(a[i]<=s){
            dp[a[i]]+=i+1;
        }
        (ans+=dp[s])%=MOD;
    }
    cout << ans << endl;
}