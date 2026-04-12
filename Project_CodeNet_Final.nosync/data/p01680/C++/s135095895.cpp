#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define iter(c) __typeof((c).begin())
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
#define pb(a) push_back(a)
#define pr(a) cout<<(a)<<endl
#define PR(a,b) cout<<(a)<<" "<<(b)<<endl
#define R cin>>
#define F first
#define S second
#define ll long long
bool check(int n,int m,int x,int y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1000000007,MAXL=1LL<<60,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<int,int> P;

int p[100001];
int r[100001];
void init() {
  for(int i=0; i<100001; i++) {
    p[i]=i;
    r[i]=0;
  }
}
int find(int x) {
  if(p[x]==x) return x;
  else return p[x]=find(p[x]);
}
void unite(int x,int y) {
  x=find(x);
  y=find(y);
  if(x==y) return;

  if(r[x]<r[y]) p[x]=y;
  else {
    p[y]=x;
    if(r[x]==r[y]) r[x]++;
  }
}
bool same(int x, int y) {
  return find(x)==find(y);
}

ll mod_pow(ll x,ll n,ll mod){
  if(n == 0) return 1;
  ll res = mod_pow(x * x % mod,n / 2,mod);
  if(n & 1) res = res * x % mod;
  return res;
}

int main() {
  int n,m;
  while(cin >> n >> m && n) {
    init();
    rep(i,m) {
      int x,y;
      cin >> x >> y;
      unite(x,y);
    }
    set<int> s;
    REP(i,1,n+1) s.insert(find(i));
    cout << (mod_pow(2,s.size(),MAX)+(m?1:0))%MAX << endl;
  }
  return 0;
}
