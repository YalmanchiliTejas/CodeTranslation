#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include<cmath>
#include<climits>
#include<algorithm>
#include<bitset>
#include<set>
#include<stack>
#include<queue>
#include<iomanip>
#include<memory.h>
#include<complex>
#include<unordered_map>
using namespace std;  
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tuple<int,int> tii;
#define rep(i,n) for(int i=0;i<(n);i++)  
#define pb push_back
#define mt make_tuple
#define ALL(a) (a).begin(),(a).end()
#define FST first
#define SEC second  
const int INF = (INT_MAX/2);
const ll LLINF = (LLONG_MAX/2);
const double eps = 1e-8;
const double PI = M_PI;  
#define DEB cerr<<"!"<<endl
#define SHOW(a,b) cerr<<(a)<<" "<<(b)<<endl
#define SHOWARRAY(ar,i,j) REP(a,i)REP(b,j)cerr<<ar[a][b]<<((b==j-1)?((a==i-1)?("\n\n"):("\n")):(" "))
#define DIV int(1e9+7)
inline ll pow(ll x,ll n,ll m){ll r=1;while(n>0){if((n&1)==1)r=r*x%m;x=x*x%m;n>>=1;}return r%m;}
inline ll lcm(ll d1, ll d2){return d1 / __gcd(d1, d2) * d2;}
/* Coding Space*/
struct Edge{
  int from,to,cost;
};
vector<Edge> G;
 
#define Nodes 200020
class UF{
public:
  int value[Nodes];
  int over[Nodes]; // When over < 0, 'over' keep number of node(using negative number). -1 means this tree is a node.
  int root(int index){
    int t = index;
    while(over[t] >= 0)
      t = over[t];
    if(index!=t)over[index] = t;// reconnect
    return t;
  }
  bool merge(int a,int b){
    if(this->root(a) == this->root(b)) return false;
    over[root(a)] += over[root(b)]; // 'over' have a number of nodes.
    over[root(b)] = root(a);
    return true;
  }
  UF(){rep(i,Nodes) over[i] = -1;}
};
 
int v,e;
 
ll kruskal(){
  ll ans = 0;
  sort(ALL(G),[](Edge a, Edge b){return a.cost < b.cost;});
  UF u;
  rep(i,(int)G.size()){
    if(u.root(G[i].from) == u.root(G[i].to))
      continue;
    else{
      u.merge(G[i].from,G[i].to);
      ans += G[i].cost;
    }
  }
  return ans;
}

typedef tuple<int,int,int> tiii;
int main(){
  int n; cin >> n;
  vector<tiii> v1;
  vector<tiii> v2;
  rep(i,n){
    int x,y; cin >> x >> y;
    v1.pb(tiii{x,y,i});
    v2.pb(tiii{y,x,i});
  }
  sort(ALL(v1));
  sort(ALL(v2));
  for(int i = 1; i < n; i++){
    int x,y,ii,nx,ny,nii;
    tie(x,y,ii) = v1[i-1];
    tie(nx,ny,nii) = v1[i];
    G.pb(Edge{ii,nii,min(abs(x-nx),abs(y-ny))});
  }
  for(int i = 1; i < n; i++){
    int x,y,ii,nx,ny,nii;
    tie(y,x,ii) = v2[i-1];
    tie(ny,nx,nii) = v2[i];
    G.pb(Edge{ii,nii,min(abs(x-nx),abs(y-ny))});
  }
  cerr << G.size() << endl;
  cout << kruskal() << endl;
}