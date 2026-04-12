#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
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
#define mod 1000000007

struct UnionFind{
  vector<int> v;
  UnionFind(int n) : v(n, -1) {}
  void init(){ for(int i = 0;i < v.size();i++)v[i]=-1; }
  int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (-v[x] < -v[y]) swap(x, y);
    v[x] += v[y]; v[y] = x;
    return true;
  }
  bool root(int x) { return v[x] < 0; }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -v[find(x)]; }
};

ll mod_pow(ll a,ll n){
  ll res=1;
  while(n>0){
    if(n&1)res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

int N,M;

int main(){
  while(1){
    cin>>N>>M;
    if(N==0)break;
    UnionFind uf(N);
    rep(i,M){
      int a,b;
      cin>>a>>b;
      a--;b--;
      uf.unite(a,b);
    }
    vector<bool> used(N,false);
    int sum=0;
    ll p=1;
    rep(i,N){
      if(used[uf.find(i)])continue;
      used[uf.find(i)]=true;
      if(uf.size(i)>1){
        sum+=uf.size(i);
        (p*=2)%=mod;
      }
    }
    ll res=mod_pow(2,N-sum);
    if(sum>0){
      (res*=p)%=mod;
      (res+=1)%=mod;
    }
    cout<<res<<endl;
  }
  return 0;
}

