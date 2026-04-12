#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<n ; ++i)
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define all(v) (v).begin() , (v).end()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvc = vector<vector<char>>;
using pii = pair<int , int>;
using pll = pair<long long , long long>;

//プロトタイプ宣言
void faster(void);
template <class T>
T gcd(T , T);
template <class T>
T get_digent(T);
template <class T>
T POW(T , T);


int main(){
  faster();
  int n,m;
  cin >> n >> m;
  if(n==m) cout << "Yes";
  else cout << "No";
}



























//同期解除
void faster(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

//ユークリッドの互除法
template <class T>
T gcd(T a, T b) {
  return (b ? gcd(b, a%b) : a);
} 

//桁数取得
template <class T>
T get_digent(auto x){
  string s;
  s = to_string(x);
  ll digent = s.size();
  return digent;
} 

//べき乗計算
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

