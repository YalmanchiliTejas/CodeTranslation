#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxn=1e5+10;
ll s[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    for(ll i=0;i<n;++i)cin>>s[i];
    ll ans=0;
    for(ll step=1;step<n;++step){
        ll l=0,r=n-1;
        ll sum=0;
        while(r>step&&(r%step||l<r)){
            sum+=s[l]+s[r];
            ans=max(ans,sum);
            l+=step;
            r-=step;
        }
    }
    cout<<ans<<endl;
}
