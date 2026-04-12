#include <bits/stdc++.h>
//----***やべーやつら***----
using namespace std;
#define int long long

//----***型定義***----
using ll = long long;
using P = pair<int,int>;

//----***Like a Pythonista***----
#define REP(ii,jj,nn) for (ll ii=jj;ii<(nn);ii++)
#define RREP(ii,nn,jj) for (ll ii = nn; jj<ii;ii--)
#define each(i,...) for (auto&& i:__VA_ARGS__)
#define ALL(vec) (vec).begin(),(vec).end()
#define sum(...) accumulate(ALL(__VA_ARGS__),0LL)
#define dsum(...) accumulate(ALL(__VA_ARGS__),0.0)
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
template<class T> inline auto max(const T& a){ return *max_element(ALL(a)); }
template<class T> inline auto min(const T& a){ return *min_element(ALL(a)); }
inline ll gcd(ll a,ll b){if(b == 0) return a;return  gcd(b,a%b);}
inline ll lcm(ll a,ll b){ll g = gcd(a,b);return a / g * b;}

//----***定数***----
#define MOD 1000000007
#define INF 100000000000000000
#define EPS 1e-9
const vector<vector<int>> DXY={{-1,0},{1,0},{0,-1},{0,1}};

//----***パーツ***----
#define fr first
#define se second
#define pb push_back
#define re return
#define br break

//----***入出力***---
void print() { std::cout << "\n"; }
template <class T>void print(const T &x) {std::cout << x<<"\n";}
template <class T, class... Args>void print(const T &x, const Args &... args) {std::cout << x << " ";print(args...);}
#define debug(var)  do{std::cerr << #var << " ↓ "<<"\n";view(var);}while(0);
#define dbg cerr<<"🥺🥺🥺🥺🥺🥺"<<endl;
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

//----***初期時読み込み***----
struct initial{initial(){cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(15);};}initial_;

signed main(){
  int H,W;cin>>H>>W;
  vector<string> G(H);
  REP(i,0,H)cin>>G[i];
  vector<vector<int>> visited(H,vector<int>(W,0));
  REP(i,0,H)REP(j,0,W){
    visited[i][j]=(G[i][j]=='#'?1:0);
  }

  queue<P> que;
  bool possible=false;
  que.push(make_pair(0,0));
  while(que.size()){
    P p = que.front();que.pop();
    visited[p.fr][p.se]=0;
    if(p.first==H-1&&p.se==W-1){
      possible=true;
      break;
    }
    P under,right;
    if(p.fr+1<H){
      under=P(p.fr+1,p.se);
    }
    if(p.second+1<W){
      right=P(p.first,p.second+1);
    }
    if(p.first+1<H&&p.second+1<W){
      if(G[under.fr][under.se]=='#'&&G[right.fr][right.se]=='#'){
        print("Impossible");
        re 0;
      }
    }
    if(p.first+1<H&&G[under.fr][under.se]=='#'){
      que.push(under);
    }
    if(p.second+1<W&&G[right.fr][right.se]=='#'){
      que.push(right);
    }
  }
  REP(i,0,H)REP(j,0,W){
    if(visited[i][j]==1)possible=false;
  }
  print((possible?"Possible":"Impossible"));

}
