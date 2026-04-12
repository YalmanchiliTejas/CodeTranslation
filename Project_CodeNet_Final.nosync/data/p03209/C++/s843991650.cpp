#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define PRINT(v) for (auto x : (V)) cout <<x <<" " <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> struct edge { int from, to; T cost;};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }


ll hamburger(int N, ll X, ll layer){
  // レベルNバーガーの下からX層にパティは何枚存在するか
  // 但しレベルNバーガーの層の合計はlayerとする
  if (N == 0) return X;
  if (X == 0) return 0;
  
  ll res = 0;
  if (X == layer / 2 + 1) res = hamburger(N-1, X-2, (layer-3)/2) + 1;
  else if (X == layer) res = hamburger(N-1, (X-3)/2, (layer-3)/2) * 2 + 1;
  else if (X <= layer / 2) res = hamburger(N-1, X-1, (layer-3)/2);
  else res = hamburger(N-1, (layer-3)/2, (layer-3)/2) + 1 + hamburger(N-1, X - 2 - (layer-3)/2, (layer-3)/2);
  return res;
}

int main() {
  int N; cin >>N;
  ll X; cin >>X;
  ll layer = 1;
  rep(i, N) layer = 2 * layer + 3;
  ll res = hamburger(N, X, layer);
  cout <<res <<endl;
}