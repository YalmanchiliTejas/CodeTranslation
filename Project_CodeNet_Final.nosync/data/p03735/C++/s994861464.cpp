#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF 1e16

struct RangeMinQuery{
  int dat[(1<<19)-1];
  int size;

  void init(int n_){
    size=1;
    while(size<n_) size*=2;
    for(int i=0;i<2*size-1;i++)dat[i]=INT_MAX;
  }

  void update(int k,int a){
    k+=size-1;
    dat[k]=a;
    while(k>0){
      k=(k-1)/2;
      dat[k]=min(dat[k*2+1],dat[k*2+2]);
    }
  }

  int subquery(int a,int b,int k,int l,int r){
    if(r<=a||b<=l)return INT_MAX;
    if(a<=l&&r<=b)return dat[k];
    else{
      return min(subquery(a,b,k*2+1,l,(l+r)/2),subquery(a,b,k*2+2,(l+r)/2,r));
    }
  }
  
  int query(int a,int b){
    return subquery(a,b,0,0,size);
  }
};

int n;
ll x[202020],y[202020];
multiset<ll> st;
RangeMinQuery r1,r2;

int main(){
	cin.sync_with_stdio(false);
  cin>>n;
  rep(i,n){ // x[i] <= y[i]
    cin>>x[i]>>y[i];
    if(x[i]>y[i])swap(x[i],y[i]);
  }
  ll maxx=*max_element(y,y+n);
  ll minn=*min_element(x,x+n);
  ll resa,resb;
  {
    ll mina=minn,maxb=maxx;
    ll maxa=-INF;
    rep(i,n){
      maxch(maxa,x[i]);
    }
    ll minb=INF;
    rep(i,n){
      minch(minb,y[i]);
    }
    resa=(maxa-mina)*(maxb-minb);
  }
  {
    ll mina=minn,maxa=maxx;
    ll mind=INF;
    r1.init(n); r2.init(n);
    rep(i,n){
      r1.update(i,x[i]);
      r2.update(i,-x[i]);
    }
    vector<P> tmp;
    rep(i,n){
      tmp.push_back(P(x[i],i));
    }
    sort(all(tmp));
    minch(mind,-r2.query(0,n)-r1.query(0,n));
    rep(i,n){
      int idx=tmp[i].se;
      r1.update(idx,y[idx]);
      r2.update(idx,-y[idx]);
      minch(mind,-r2.query(0,n)-r1.query(0,n));
    }
    resb=(maxa-mina)*mind;
  }
  cout<<min(resa,resb)<<endl;
  return 0;
}
