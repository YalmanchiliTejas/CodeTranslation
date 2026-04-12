#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
ll n;
ll a[200005];
ll s;
ll b[200005];
ll ans;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i+1]=(b[i]+a[i])%MOD;
        s=(s+a[i])%MOD;
    }
    for(int i=0;i<n;i++){
        ans=(ans+(a[i]*(s-b[i+1]))%MOD)%MOD;
    }
    if(ans<0){
        ans+=MOD;
    }
    cout<<ans<<endl;
    
}
