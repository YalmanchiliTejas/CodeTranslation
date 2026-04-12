#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    ll sum=0;
    rep(i,n-1) sum=(sum+a[i])%MOD;

    ll ans=0;
    for(int i=n-1;i>=1;i--){
        ll tmp=(a[i]*sum)%MOD;
        ans=(ans+tmp)%MOD;
        sum=(sum-a[i-1])%MOD;
        if(sum<0) sum+=MOD;
    }

    cout<<ans<<endl;

}
