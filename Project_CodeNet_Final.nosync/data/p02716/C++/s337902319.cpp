#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl "\n"
#define deb(x) cerr << #x << ":" << x << "\n"

vector<ll> dp;
vector<int> v;
int n;

void solve(){
    cin>>n;
    v.resize(n+1);
    dp.resize(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    dp[1]=v[1];
    dp[2]=v[2];
    for(int i=3;i<=n;i++){
        if(i&1)dp[i]=dp[i-2]+v[i];
        else dp[i]=max(dp[i-2],dp[i-3])+v[i];
    }
    if(n&1){
        ll bj=v[n],ans=max(dp[n-1],dp[n-2]);
        for(int i=n-2;i>=3;i-=2){
            ans=max(ans,bj+max(dp[i-1],dp[i-2]));
            bj+=v[i];
        }
        cout<<max(ans,bj);
    }else cout<<max(dp[n-1],dp[n]);;

}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
