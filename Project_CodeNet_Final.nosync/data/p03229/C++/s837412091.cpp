#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<int>a(n+1,1e9+1);
    for(int i=1; i<=n; ++i)cin>>a[i];
    sort(a.rbegin(),a.rend());
    ll ans=0;
    if(n%2==0){
        for(int i=1; i<=n/2; ++i){
            ans+=2*a[i];
        }
        for(int i=n; i>n/2; --i){
            ans-=2*a[i];
        }
        ans-=a[n/2]-a[n/2+1];
    }
    else{
        ll res1=0,res2=0;
        for(int i=1; i<=(n+1)/2; ++i){
            res1+=2*a[i];
            res2+=2*a[i];
        }
        for(int i=n; i>(n+1)/2; --i){
            res1-=2*a[i];
            res2-=2*a[i];
        }
        res1-=a[n/2]+a[n/2+1];
        res2+=(ll)-3*a[n/2+1]+a[n/2+2];
        ans=max(res1,res2);
    }
    cout<<ans<<endl;
    return 0;
}