#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define PN printf("\n")
#define MODV 1000000007

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
void addmod(int &a, ll b){a=(a+b); if(a>=MODV)a-=MODV;}
void mulmod(int &a, ll b){a=(a*b)%MODV;}
template<class T>bool domin(T &a, const T &b){return a>b?a=b,1:0;}
template<class T>bool domax(T &a, const T &b){return a<b?a=b,1:0;}
int gi(){int a;scanf("%d",&a);return a;}
ll gll(){ll a;scanf("%lld",&a);return a;}

class graphwal
{
  public:
    int n;
    //0 1->bidirectional, 2->reverse edges
    typedef vector<pair<int,ll>> vpi;
    vector<vpi> ed;
    graphwal(int n):n(n),ed(n){}
    void reset(int n){
    ed.clear();
    this->n=n;
    ed.resize(n);
  }
    void add(int a, int b, int w){ed[a].pb(mp(b,w));}
    void load(int m){ for(int i=0;i<m;i++){int a=gi(),b=gi();ll w=gll();add(a-1,b-1,w);}}
};

class prims{
  public:
    typedef ll dt;
    typedef pair<dt,int> pt;
    int n;
    const graphwal &g;
    vector<dt> d;
    vi pr;
    vector<bool> v;
    const static dt MAXV=LLONG_MAX;
    priority_queue<pt,vector<pt>,greater<pt>> h;
    prims(const graphwal &g):
      n(g.n),g(g),d(n),pr(n),v(n){}
    dt calc(int sr=0){
      pt ret;
      dt mst=0;
      int nmst=0;
      fill(v.begin(),v.end(),false);
      fill(pr.begin(),pr.end(),-1);
      fill(d.begin(),d.end(),MAXV);
      d[sr]=0;
      h.push(pt(0,sr));
      while(!h.empty()){
        ret=h.top();
        h.pop();
        if(v[ret.se])continue;
        v[ret.se]=true;
        mst+=ret.fi;
        nmst++;
        for(auto i:g.ed[ret.se]){
          if(!v[i.fi] && d[i.fi] > i.se){
            d[i.fi]=i.se;
            pr[i.fi]=ret.se;
            h.push(pt(d[i.fi],i.fi));
          }
        }
      }
      if(nmst!=n)return -1;
      return mst;
    }
    bool inmst(int a, int b){
      return (pr[a]==b || pr[b]==a);
    }
};

int main() {
  int n=gi();
  set<pair<ll,int>> x,y;
  vi ax,ay;
  for(int i=0;i<n;i++) {
    ll tx=gi(), ty=gi();
    x.insert({tx,i}), y.insert({ty,i});
    ax.pb(tx), ay.pb(ty);
  }
  graphwal g(n);
  for(int i=0;i<n;i++) {
    ll tx=ax[i], ty=ay[i];
    auto it=x.find({tx,i});
    it++;
    if(it!=x.end()){
      g.add(i,(*it).se,(*it).fi-tx);
    }
    it--;
    if(it!=x.begin()){
      it--;
      g.add(i,(*it).se,tx-(*it).fi);
    }

    auto yt=y.find({ty,i});
    yt++;
    if(yt!=y.end()){
      g.add(i,(*yt).se,(*yt).fi-ty);
    }
    yt--;
    if(yt!=y.begin()){
      yt--;
      g.add(i,(*yt).se,ty-(*yt).fi);
    }
  }
  prims pr(g);
  cout<<pr.calc()<<endl;


  return 0;
}