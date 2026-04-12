#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;

int main() {
    int n;
    while (cin>>n,n) {
        vector<ll> a(n);
        rep(i,n) cin>>a[i];
        sort(a.begin(),a.end());
        a.pop_back();
        sort(a.begin(),a.end(),greater<>());
        a.pop_back();
        ll sum = 0;
        rep(i,n-2) sum+=a[i];
        ll ans=sum/(n-2);
        cout<<ans<<endl;
    }
}
