#include <bits/stdc++.h>
//#include <atcoder/all>
using ll = long long;
using namespace std;
//using namespace atcoder;

int main() {
    int mod=1e9+7;
    int n;cin>>n;
    int a[n],b[n];
    cin>>a[0];
    b[0]=a[0];
    for (int i=1;i<n;i++) {
        cin>>a[i];
        b[i]=(b[i-1]+a[i])%mod;
    }
    int ans=0;
    for (int i=1;i<n;i++)
        ans=(ans+(ll)a[i]*b[i-1])%mod;
    cout<<ans<<endl;
    return 0;
}