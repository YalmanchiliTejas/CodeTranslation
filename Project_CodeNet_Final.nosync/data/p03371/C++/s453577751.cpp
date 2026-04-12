#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<n ; ++i)
#define REP(i,a,b) for(int i=a; i<b; ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

//プロトタイプ宣言
void faster(void);
ll gcd(auto , auto);
ll get_digent(auto);
ll POW(auto , auto);
ll vec_max(auto & , string);
ll vec_min(auto & , string);

int main(){
  faster();
  ll a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  ll ma = max(x,y);
  ll mi = min(x,y);
  ll ex1 = a*x + b*y;
  ll ex2 = c*ma*2;
  ll ex3 = c*x*2 + b*abs(y-x);
  ll ex4 = c*y*2 + a*abs(x-y);
  if(ex3 <= 0) ex3 = 1e12;
  if(ex4 <= 0) ex4 = 1e12;
  ll ans = min(ex1 , min(ex2 , min(ex3 , ex4)));
  cout << ans << endl;
}






























//以下、ライブラリ

//同期解除
void faster(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

//ユークリッドの互除法
ll gcd(auto a, auto b) {
  return (b ? gcd(b, a%b) : a);
} 

//桁数取得
ll get_digent(auto x){
  string s;
  s = to_string(x);
  ll digent = s.size();
  return digent;
} 

//べき乗計算
ll POW(auto x, auto y){
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

//配列内の最大要素のイテレータ取得or要素取得
ll vec_max(auto &v, string s){
  auto itr = max_element(v.begin(),v.end());
  ll element = *itr;
  ll place = itr - v.begin();
  if(s == "element") return element;
  else if(s == "place") return place;
  else return -1;
}

ll vec_min(auto &v, string s){
  auto itr = min_element(v.begin(),v.end());
  ll element = *itr;
  ll place = itr - v.begin();
  if(s == "element") return element;
  else if(s == "place") return place;
  else return -1;
}