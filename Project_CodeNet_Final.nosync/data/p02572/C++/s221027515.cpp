#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n;
    cin>>n;
    vector<long> a(n);
    long wa=0;
    long long ans=0;
    rep(i,n){
        cin>>a[i];
        ans=ans+a[i]*wa;
        wa+=a[i];
        ans%=1000000007L;
        wa%=1000000007L;
    }
    cout<<ans<<endl;
}