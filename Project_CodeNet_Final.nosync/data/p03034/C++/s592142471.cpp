#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define ft first
#define sd second
#define mp make_pair
#define fr(i,n) for(int i=0;i<(n);i++)
#define Fr(i,n) for(int i=0;i++<(n);)
#define ifr(i,n) for(int i=(n)-1;i>=0;i--)
#define iFr(i,n) for(int i=(n);i>0;i--)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,ans=0;
    cin>>n;
    vector<ll> s(n);
    for(auto& i:s) cin>>i;
    Fr(c,n-1){
        vector<bool> vis(n);
        ll ka=0;
        fr(i,(n-1)/c){
            if(vis[i*c]) break;
            vis[i*c]=1;
            if(vis[n-1-i*c]) break;
            vis[n-1-i*c]=1;
            ka+=s[i*c]+s[n-1-i*c];
            ans=max(ans,ka);
            //if(ka==13) cout<<c<<" "<<i<<endl;
        }
    }
    cout<<ans<<endl;
}