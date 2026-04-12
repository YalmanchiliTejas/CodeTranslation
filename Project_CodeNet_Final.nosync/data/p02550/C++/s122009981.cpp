//                        Bismillahir Rahmanir Rahim
//ALGO:
#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define FILL(a, x) memset(a, x, sizeof(a))
#define ll long long
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define INF ll_MAX
#define MX 1000010
#define mod  998244353
#define dout if(debug) cout
#define FR(i, n) for(ll i=0; i<n; i++)
#define FOR(i, n) for(ll i=1; i<=n; i++)
const double Pi=acos(-1);
using namespace std;
ll debug=01;
void solve(){
    ll n, x, m;
    cin>>n>>x>>m;
    ll a[m+10]={0}, f[m+10]={0};
    a[1]=x;
    ll sum=x, len, start;
    f[x]=1;
    for(ll i=2;i<=n;i++){
        x=(x*x)%m;
        a[i]=x;
        if(f[x]){
            len=i-f[x];
            start=f[x];
            goto circle;
        }
        sum+=x;
        f[x]=i;
    }
    cout<<sum; return;
    circle: ;
    sum=0;
    for(ll i=1; i<start; i++)sum+=a[i];
    n-=(start-1);
    ll y=n/len;
    for(ll j=1; j<=len; j++){
        sum+=a[start+j-1]*y;
    }
    for(ll j=1; j<=(n%len); j++) sum+=a[start+j-1];
    cout<<sum;
}
int main() {
    Fast
    ll tst=1;
    //cin>>tst;
    for(ll T=1; T<=tst; T++){
        //cout<<"Case "<<T<<": ";
        solve();
    }
}
