//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

vector<ll> pn(51,0);
ll ans=0;

void dfs(ll k,ll a,ll b,ll l,ll r){
    if(k==0){
        ans++; return;
    }
    ll ce=(l+r)/2;
    if(a<=ce && ce<=b) ans++;
    if(a<=l+1 && ce-1<=b) ans+=pn[k-1];
    else if(a<ce && b>l) dfs(k-1,max(a,l+1),min(b,ce-1),l+1,ce-1);
    if(a<=ce+1 && r-1<=b) ans+=pn[k-1];
    else if(b>ce && a<r) dfs(k-1,max(a,ce+1),min(b,r-1),ce+1,r-1);
}

int main(){
    pn[0]=1;
    rep(i,50) pn[i+1]=pn[i]*2+1;
    ll n,x,cnt=1; cin>>n>>x;
    rep(i,n) cnt=cnt*2+3;
    dfs(n,0,x-1,0,cnt-1);
    cout<<ans<<endl;
}