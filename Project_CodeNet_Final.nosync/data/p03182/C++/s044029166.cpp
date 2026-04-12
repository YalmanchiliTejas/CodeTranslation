#include<bits/stdc++.h>

using namespace std;

#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}

#define FOR(a,b,c) for(int a=b, __c=c; a<=__c; ++a)
#define FORD(a,b,c) for(int a=b, __c=c; a>=__c; --a)
#define forv(a,b) for(auto &a:b)

#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(a) begin(a),end(a)
#define reset(f,x) memset(f,x,sizeof(f))
#define fasty ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

#define bit(x,i) (x>>(i-1)&1ll)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1ll<<(i-1)))

const int N=2e5+5;
const int inf=1e18;
int n,m;
vector<int> in[N],out[N];
struct pack{
   int l,r,val;
} a[N];
int it[N<<2], lz[N<<2];

#define goc 1,0,n
#define mid l+(r-l)/2
#define lef i<<1,l,mid
#define rig i<<1|1,mid+1,r

void trans(int i){
   if(lz[i]){
      int T=lz[i];
      lz[i<<1]+=T; lz[i<<1|1]+=T;
      it[i<<1]+=T; it[i<<1|1]+=T;
      lz[i]=0;
   }
}
void upd(int i,int l,int r,int u,int v,int val){
   if(v<l || u>r) return;
   if(u<=l && r<=v){
      it[i]+=val;
      lz[i]+=val;
      return;
   }
   trans(i);
   upd(lef,u,v,val); upd(rig,u,v,val);
   it[i]=max(it[i<<1], it[i<<1|1]);
}
int que(int i,int l,int r,int u,int v){
   if(v<l || u>r) return -inf;
   if(u<=l && r<=v) return it[i];
   trans(i);
   return max(que(lef,u,v), que(rig,u,v));
}

int32_t main(){
   fasty;

   #define task "w"
   if(fopen(task".in","r")) freopen(task".in","r",stdin);

   cin>>n>>m;
   FOR(i,1,m){
      int l,r,val;
      cin>>l>>r>>val;
      a[i]={l,r,val};
      in[l].pb(i);
      out[r].pb(i);
   }

   int ans=0;
   FOR(i,1,n){
      forv(v,in[i]) upd(goc,0,a[v].l-1,a[v].val);
      int tmp=que(goc,0,i-1);
      ans=max(ans,tmp);
      upd(goc,i,i,tmp);
      forv(v,out[i]) upd(goc,0,a[v].l-1,-a[v].val);
   }
   cout<<ans<<'\n';
}
/**
  f[i] : max value 1->n with ans[i] = 1;
  	   = max f[j] + a[t] for t with l[t]<=i<=r[t];
         			           and !l[t]<=j<=r[t];
  n^2 can be done iterating through all posibilities;
  we speed up the algo with a seg : seg[i] as f[i]
  while iterating through a position : i,
  all query with start point at i , we update the range [0,i-1] : a[t];
  same as if we meet a end point  , we update the range [0,i-1] : -a[t];
*/