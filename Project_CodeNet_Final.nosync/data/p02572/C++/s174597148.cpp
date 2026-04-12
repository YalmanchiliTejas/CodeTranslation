#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const int MAX = 3e5 + 10;

int a[MAX];
int sum[MAX];
void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]%=mod;
    }
    for(int i=n;i>0;i--){
        sum[i]+=a[i]+sum[i+1];
        sum[i]%=mod;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int tem=a[i]*(sum[i+1])%mod;
        tem%=mod;
        ans+=tem;
        ans%=mod;
    }
    cout<<ans%mod;
}

signed main() {
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int _ = 1;
    //cin>>_;
    while (_--) {
        solve();
    }
    return 0;
}
