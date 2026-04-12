#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (long long i = (long long)(0); i < (long long)(n); ++i)
#define reps(i, n) for (long long i = (long long)(1); i <= (long long)(n); ++i)
#define rrep(i, n) for (long long i = ((long long)(n)-1); i >= 0; i--)
#define rreps(i, n) for (long long i = ((long long)(n)); i > 0; i--)
#define irep(i, m, n) for (long long i = (long long)(m); i < (long long)(n); ++i)
#define ireps(i, m, n) for (long long i = (long long)(m); i <= (long long)(n); ++i)
#define SORT(v, n) sort(v, v + n);
#define REVERSE(v, n) reverse(v, v+n);
#define vsort(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) long long(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;
using vtp = vector<tuple<ll,ll,ll>>;
using vb = vector<bool>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;

void add(ll& a, ll b){
  a = (a+b) % MOD;
}

void mul(ll& a, ll b){
  a = (a*b) % MOD;
}

// https://www.hamayanhamayan.com/entry/2018/01/28/234531

ll n,m;
vpll G[100100];

void dijkstra(ll s, vll& dist, vll& dp){
  dist[s]=0;
  dp[s]=1;
  priority_queue<pll, vector<pll>, greater<pll>> q;
  q.emplace(0,s);
  
  while(!q.empty()){
    auto p=q.top(); q.pop();
    ll v=p.second, c=p.first;
    if(dist[v]<c) continue;
    for(auto e: G[v]){
      ll nv=e.first, nc=e.second;
      if(chmin(dist[nv],dist[v]+nc)){
        dp[nv]=dp[v];
        q.emplace(dist[nv],nv);
      }else{
        if(dist[nv]==dist[v]+nc){
          (dp[nv]+=dp[v])%=MOD;
        }
      }
    }
  }
}

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  cin>>n>>m;
  ll s,t; cin>>s>>t; s--,t--;
  rep(i,m){
    ll a,b,c; cin>>a>>b>>c;
    a--,b--;
    G[a].emplace_back(b,c);
    G[b].emplace_back(a,c);
  }
  
  vll dists(n,LINF), distt(n,LINF);
  vll dps(n), dpt(n);
  
  dijkstra(s,dists,dps);
  dijkstra(t,distt,dpt);
  
  ll ans=(dps[t]*dps[t])%MOD;
  ll len=dists[t];
  
  // ある頂点で衝突する場合
  rep(i,n){
    // dists[i]==distt[i] だけでは不十分 なぜなら、s,tからの距離は等しいがそれがs-t間の最短経路とは限らないから
    if(dists[i]+distt[i]==len && dists[i]==distt[i]){
      add(ans,MOD-dps[i]*dpt[i]%MOD*dps[i]%MOD*dpt[i]%MOD);
      // (dps[i]*dpt[i])^2を引く理由
      // 一方の始点、例えばsからiまで来た後、さらにiからtへの経路分の通り数が考えられる
      // 同様にtからiを経由してsへ行く通り数もdps[i]*dpt[i]となる
    }
  }
  
  // ある辺上で衝突する場合
  rep(i,n){
    for(auto e: G[i]){
      ll j=e.first, c=e.second;
      if(dists[i]+c+distt[j]==len){ // (s-iのコスト)+(c:i-jのコスト)+(j-tのコスト)==len
        // dists[i]*2<len という条件がある理由 https://ferin-tech.hatenablog.com/entry/2018/01/29/232641
        // 数えたいのは、「すれ違う可能性のある辺」である
        // 衝突するのは、最長経路の1/2地点となるため、s,tから互いに1/2未満の距離でその辺を経由すると丁度lenとなるもののみとなる
        // もしこの条件がないなら、s-tの最短経路上にある辺全てという事になってしまう
        // dists[i]<len/2 だと丸め誤差が生じる可能性があるため、左の式の両辺を2倍している
        if(dists[i]*2<len && distt[j]*2<len){
          add(ans,MOD-dps[i]*dpt[j]%MOD*dps[i]%MOD*dpt[j]%MOD);
        }
      }
    }
  }
  
  cout<<ans<<endl;
}