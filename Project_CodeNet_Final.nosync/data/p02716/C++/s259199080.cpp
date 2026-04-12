#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pr;
typedef vector<ll> vc;
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define reps(i,v) for(ll i=0;i<v.size();i++)

int main() {
    // your code goes here
    ll n,a[200005],dpa[200005],dpb[200005],dp[200005],ans,mm;
    cin >> n;
    rep(i,1,n) cin >> a[i];
    if(n%2==0){
        dpa[n+2]=0;
        for(ll i=n;i>0;i=i-2){
            dpa[i]=dpa[i+2]+a[i];
        }
        dpb[1]=a[1];
        for(ll i=3;i<=n;i=i+2){
            dpb[i]=dpb[i-2]+a[i];
        }
        ans=dpa[2];
        for(ll i=1;i<=n;i=i+2){
            if(ans<dpa[i+3]+dpb[i]) ans=dpa[i+3]+dpb[i];
        }
    } else {
        dpa[1]=a[1];
        for(ll i=3;i<=n;i=i+2) dpa[i]=dpa[i-2]+a[i];
        dpa[n+2]=dpa[n];
        dp[0]=0;
        if(a[1]>a[2]) dp[2]=a[1];
        else dp[2]=a[2];
        for(ll i=4;i<=n;i=i+2){
            dp[i]=dp[i-2]+a[i];
            if(dp[i]<dpa[i-1]) dp[i]=dpa[i-1];
        }
        ans=dpa[n]-a[1];
        for(ll i=n;i>2;i=i-2){
            mm=dpa[n+2]-dpa[i]+a[i-1]+dp[i-3];
            if(ans<mm) ans=mm;
        }
    }
    cout << ans << endl;
    return 0;
}