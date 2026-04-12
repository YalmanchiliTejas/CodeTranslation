#include <bits/stdc++.h>
#define F(i,n) for (int i=1; i<=(int)n; i++)
#define FF(i,n) for (int i=0; i<(int)n; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pi pair < int , int >
#define re(x) (int)x.size()
#define y1 u228
using namespace std;
typedef long long ll;
const int N = 200001;
const int big = 2e9;
const int md = 1e9 + 7;
int n,m;
ll f[N],t1[N*4],t[N*4];
vector < pair < int , int > > sp[N];
void update(int v,int tl,int tr,int l,int r,ll vl){
    if (l>r) return;
    if (tl==l && tr==r){t[v]+=vl; t1[v]+=vl; return;}
    int d=(tl+tr)>>1;
    update(v+v,tl,d,l,min(r,d),vl);
    update(v+v+1,d+1,tr,max(l,d+1),r,vl);
    t[v]=max(t[v+v],t[v+v+1])+t1[v];
}
ll go(int v,int tl,int tr,int l,int r){
    if (l>r) return -9e18;
    if (tl==l && tr==r) return t[v];
    int d=(tl+tr)>>1;
    return max(go(v+v,tl,d,l,min(r,d)),go(v+v+1,d+1,tr,max(l,d+1),r))+t1[v];
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt","r",stdin);
    cin>>n>>m;
    F(i,m){
        int l,r,a;
        cin>>l>>r>>a;
        sp[l].pb(mp(l-1,a));
        sp[r+1].pb(mp(l-1,-a));
    }
    ll ans=0ll;
    F(i,n){
        FF(j,re(sp[i]))
            update(1,0,n,0,sp[i][j].fi,sp[i][j].se);
        f[i]=go(1,0,n,0,i-1);
        update(1,0,n,i,i,f[i]);
        ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
    return 0;
}





