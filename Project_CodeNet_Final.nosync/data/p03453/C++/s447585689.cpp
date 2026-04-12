#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int N = 100010;
const int INF = 1LL<<55;
const int mod = (1e9)+7;
const double EPS = 1e-8;
const double PI = 6.0 * asin(0.5);
typedef pair<int,int> P;
typedef long long ll;
ostream& operator<<(ostream& o,P p){return o<<"("<<p.first<<","<<p.second<<")";}
istream& operator>>(istream& i,P &p){return i>>p.first>>p.second;}
template<class T> istream& operator>>(istream& i,vector<T> &a){for(auto &t:a)cin>>t;return i;}
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
template<class T> void prArr(T a,string s=" "){int i=0;for(auto t:a)cout<<(i++?s:"")<<t;cout<<endl;}

ll mod_pow(ll x,ll n){
  ll res=1;
  while(n){
    if(n%2) res=res*x%mod;
    x=x*x%mod;
    n/=2;
  }
  return res;
}

vector<vector<P> > G;
vector<int> dijkstra(int S,int T){
  int n = G.size();
  priority_queue<P,vector<P>,greater<P> >Q;
  vector<int> D(n,INF);
  D[S] = 0;
  Q.push(P(0,S));
  while(!Q.empty()){
    auto p = Q.top();Q.pop();
    int pos = p.second;
    int cost = p.first;
    
    if(D[pos] < cost) continue;
    
    for(auto p:G[pos]){
      int to = p.first;
      int ncost = cost + p.second;
      if(D[to] <= ncost) continue;
      D[to] = ncost;
      Q.push(P(ncost,to));
    }
  }
  return D;
}

vector<int> dijkstra_cnt(int S,int T,vector<int> D,vector<int> D2){
  int n = G.size();
  priority_queue<P,vector<P>,greater<P> >Q;
  D[S] = 0;
  Q.push(P(0,S));
  vector<int> cnt(n);
  vector<int> used(n);
  cnt[S] = 1;
  while(!Q.empty()){
    auto p = Q.top();Q.pop();
    int pos = p.second;
    int cost = p.first;
    
    if(used[pos]++) continue;
    
    for(auto p:G[pos]){
      int to = p.first;
      int ncost = cost + p.second;
      if(D[pos] + D2[to] + p.second != D[T]) continue;
      cnt[to] = (cnt[to] + cnt[pos])%mod;
      Q.push(P(ncost,to));
    }
  }
  return cnt;
}

signed main(){
  int n,m;
  cin>>n>>m;
  int S,T;
  cin>>S>>T; S--,T--;

  G.resize(n);
  for(int i=0;i<m;i++){
    int u,v,d;
    cin>>u>>v>>d; u--,v--;
    G[u].push_back(P(v,d));
    G[v].push_back(P(u,d));
  }

  vector<int> D1 = dijkstra(S,T);
  vector<int> D2 = dijkstra(T,S);
  vector<int> cnt1 = dijkstra_cnt(S,T,D1,D2);
  vector<int> cnt2 = dijkstra_cnt(T,S,D2,D1);

  int ans = cnt1[T]*cnt1[T]%mod;
  for(int i=0;i<n;i++){
    if(D1[T] != D1[i]*2) continue;
    int a = cnt1[i] * cnt2[i] % mod;
    a = a * a %mod;
    ans = (ans + mod -a) % mod;
  }

  for(int i=0;i<n;i++)
    for(auto t:G[i]){
      int to = t.first;
      int cost = t.second;
      if(D1[i] + D2[to] + cost != D1[T]) continue;
      if(D1[i]*2 < D1[T] && D1[to]*2 > D1[T]) {
        int a = cnt1[i] * cnt2[to] % mod;
        a = a * a %mod;
        ans = (ans + mod -a) % mod;
      }
    }
  cout<<ans<<endl;
  return 0;
}
