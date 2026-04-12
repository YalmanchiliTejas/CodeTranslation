#include<bits/stdc++.h>
using namespace std;

//省略形
#define rep(i,n) for(auto i=0; i<n ; ++i)
#define REP(i,a,b) for(auto i=a; i<b; ++i)
#define all(v) (v).begin() , (v).end()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvc = vector<vector<char>>;
using pii = pair<int , int>;
using pll = pair<long long , long long>;

//よく使う定数
const int INF = 1e9;
const int MOD = 1e9+7;
//逆元
const int INV = 1e9+5;

//UnionFindTree
struct union_find{
  vector<int> data;
  union_find(int size) : data(size , -1) { }

  void merge(int x , int y){
    x = root(x); y = root(y);
    if(x == y) return;
    if(data[y] < data[x]) swap(x , y);
    data[x] += data[y];
    data[y] = x;
    return; 
  }

  bool same(int x , int y){
    x = root(x) , y = root(y);
    return x == y;
  }

  int root(int x){
    return data[x] < 0 ? x : (data[x] = root(data[x]));
  }

  int size(int x){
    return -data[root(x)];
  }
};

//プロトタイプ宣言
void faster(void);
template <class T>
T get_digent(T);
template <class T>
T POW(T , T);
template <class T>
T modpow(T , T , T);

//メモ
//最大公約数:__gcd　|　最小公倍数:__lcm


int main(){
  faster();
  string s;
  cin >> s;
  if(s == "AAA" || s == "BBB"){
    cout << "No";
    return 0;
  }
  cout << "Yes";
}


























//同期解除
void faster(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

//桁数取得
template <class T>
T get_digent(auto x){
  string s;
  s = to_string(x);
  ll digent = s.size();
  return digent;
} 

//繰り返し自乗法
template <class T>
T POW(T x, T y){
  if(y==0) return 1;
  if(y%2 == 1){
    ll temp = POW(x,y-1);
    return (temp*x);
  }
  else{
    ll temp = POW(x,y/2);
    return temp*temp;
  }
} 

//繰り返し自乗法(剰余)
template <class T>
T modpow(T x , T y , T mod){
  if(y == 0) return 1;
  if(y%2 == 1){
    ll temp = modpow(x,y-1,mod);
    return temp*x%mod;
  }
  else{
    ll temp = pow_mod(x,y/2,mod);
    return temp*temp%mod;
  }
}

