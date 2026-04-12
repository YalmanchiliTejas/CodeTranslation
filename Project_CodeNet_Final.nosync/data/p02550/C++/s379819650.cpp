#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << " :";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

//modをとった余りは循環する
//鳩の巣原理


int main(){
  ll n,x,m;
  cin >> n >> x >> m;
  vector<int> id(m, -1);
  vector<int> a;    //配列

  int len = 0;   //配列の長さ
  ll tot = 0;   //ループの値の合計
  //ループの検出
  while(id[x] == -1){
    a.push_back(x);
    id[x] = len;
    len++;
    tot += x;
    x = (x*x)%m;
  }
  
  int c = len - id[x]; // サイクルの長さ
  ll sum = 0;   //サイクルの合計
  for(int i = id[x]; i < len; ++i) sum += a[i];

  ll ans = 0;
  if(n <= len){ //サイクルに入る前に打ち切り　-> 普通に求める
      REP(i,n) ans += a[i]; 
  }
  else{
    ans += tot;   //ρ (チョロ＋一周分を加算)
    n -= len;     //ρ　分の長さを減算
    ans += sum*(n/c);   //ループの合計　×　ループ数
    n %= c;
    REP(i,n) ans += a[id[x]+i]; //余り分を加算する
  }

  cout << ans << endl;

  return 0;
}