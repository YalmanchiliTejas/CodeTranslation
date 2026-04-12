#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9+7;
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++) cin>>a[i];
    int pre[n];
    pre[0] = a[0];
    for (int i=1; i<n; i++){
        pre[i] = (a[i]+pre[i-1])%mod;
    }
    int ans = 0;
    for (int i=n-1; i>0; i--){
        int prev = pre[i-1];
        int here = (prev*a[i])%mod;
        ans = (ans + here)%mod;
    }
    cout<<ans<<endl;

    return 0;
}
