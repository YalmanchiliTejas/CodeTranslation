#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n; cin>>n;
    vector<ll> a(n);rep(i,n)cin>>a[i];
    if(n%2==1){
        vector<ll> dp1(n/2+1), dp2(n/2+1);
        dp1[0]=0;
        dp2[0]=0;
        ll sum = a[0];
        for(int i=1; i<=n/2; i++){
            dp1[i] = a[i*2]+max(dp1[i-1],dp2[i-1]);
            dp2[i] = max(sum, a[i*2-1]+dp2[i-1]);
            sum+=a[2*i];
        }
        cout<<max(dp1[n/2],dp2[n/2])<<endl;
    }else{
        ll ans = -INF;
        vector<ll> sum1(n/2+1,0),sum2(n/2+1,0);
        for(int i=0; i<n/2; i++){
            sum1[i+1]=sum1[i]+a[2*i];
            sum2[i+1]=sum2[i]+a[2*i+1];
        }
        for(int i=0; i<=n/2; i++){
            ll a = sum1[i]+(sum2[n/2]-sum2[i]);
            ans = max(a,ans);
        }
        cout<<ans<<endl;
    }

    return 0;
}