#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    sort(all(a));
    reverse(all(a));

    if(n%2==0){
        ll ans=0;
        rep(i,n/2-1) ans+=2*a[i];
        ans+=a[n/2-1];
        ans-=a[n/2];
        for(int i=n/2+1;i<n;i++) ans-=a[i]*2;
        cout<<ans<<endl;
    }
    else{
        ll ans1=0;
        rep(i,n/2-1) ans1+=a[i]*2;
        ans1+=a[n/2-1]+a[n/2];
        for(int i=n/2+1;i<n;i++) ans1-=a[i]*2;

        ll ans2=0;
        rep(i,n/2) ans2+=a[i]*2;
        ans2-=a[n/2]+a[n/2+1];
        for(int i=n/2+2;i<n;i++) ans2-=a[i]*2;

        cout<<max(ans1,ans2)<<endl;
    }
}