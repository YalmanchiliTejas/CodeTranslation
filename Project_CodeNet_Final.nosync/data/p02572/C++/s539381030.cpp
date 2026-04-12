#include<bits/stdc++.h>
#define int long long int
#define endl "\n"
#define arrinp(v) for(auto &i:v) cin>>i;
#define arrout(v) for(auto &i:v) cout<<i<<" ";
#define newline cout<<endl;
using namespace std;
const int MOD=1e9+7;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin >> t;
    while (t--) {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int p[n];
        p[0]=a[0];
        for(int i=1;i<n;i++){
            p[i]=a[i]+p[i-1];
            // cout<<p[i]<<" ";
        }
        // newline;
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=((((p[i]%MOD)-(a[i]%MOD))%MOD*a[i]%MOD)%MOD);
            ans=(ans+MOD)%MOD;
        }
        cout<<ans%MOD<<endl;
    }
    return 0;
}