#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    if(k==0){
        cout << n*n<<endl;
        return 0;
    }
    for(ll i=k;i<=n;i++){
        ll num=n/i;
        ans+=(i-k)*num;
        ans+=max(n-num*i-k+1,0LL);
    }
    cout << ans<<endl;
    return 0;
}
