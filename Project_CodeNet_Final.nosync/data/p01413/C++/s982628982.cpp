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

int n,m,W,T;
map<string,int> id;
ll w[11],b[11];
ll times[1<<8],prof[1<<8];
ll dp[10010];

ll x[11],y[11];
vector<P> prod[11];

int main(){
	cin.sync_with_stdio(false);
  cin>>n>>m>>W>>T;
  rep(i,m){
    string name;
    cin>>name>>w[i]>>b[i];
    id[name]=i;
  }

  rep(i,n){
    int l;
    cin>>l>>x[i]>>y[i];
    while(l--){
      string name;
      ll price;
      cin>>name>>price;
      prod[i].push_back(P(id[name],price));
    }
  }

  repl(S,1,1<<n){
    vector<int> vs;
    rep(i,n){
      if(((S>>i)&1)==1){
        vs.push_back(i);
      }
    }
    ll dist=INF;
    do{
      ll sum=abs(x[vs[0]])+abs(y[vs[0]])+abs(x[vs[vs.size()-1]])+abs(y[vs[vs.size()-1]]);
      rep(j,vs.size()-1){
        sum+=abs(x[vs[j]]-x[vs[j+1]])+abs(y[vs[j]]-y[vs[j+1]]);
      }
      minch(dist,sum);
    }while(next_permutation(all(vs)));

    ll minprice[11];
    rep(i,11)minprice[i]=INF;
    rep(i,vs.size()){
      for(P p : prod[vs[i]]){
        if(minprice[p.fi]>p.se)minprice[p.fi]=p.se;
      }
    }
    memset(dp,0,sizeof(dp));
    rep(i,m)rep(j,W-w[i]+1){
      maxch(dp[j+w[i]],dp[j]+mmax(0,b[i]-minprice[i]));
    }
    times[S]=dist; prof[S]=dp[W];
  }

  memset(dp,0,sizeof(dp));
  repl(i,1,1<<n)rep(j,T-times[i]+1){
    maxch(dp[j+times[i]],dp[j]+prof[i]);
  }
  cout<<*max_element(dp,dp+10010)<<endl;
	return 0;
}