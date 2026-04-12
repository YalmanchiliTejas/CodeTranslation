#include <bits/stdc++.h>
#define rep(i,n)    for(long long i = 0; i < (n) ; ++i)
#define orep(i,n)   for(long long i = 1; i <= (n); ++i)   // one rep
#define drep(i,n)   for(long long i = (n)-1; i >= 0; --i) // down rep
#define srep(i,s,t) for(long long i = (s); i < (t); ++i)  // set rep
#define rng(x)  (x).begin(),(x).end()

  // range
#define rrng(a) (a).rbegin(),(a).rend() // reverse range
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define ru(x,y) (((x)+(y)-1)/(y)) // round up
#define fi first
#define se second
#define eb emplace_back
#define fcout cout << fixed << setprecision(15)


using namespace std;
using ll  = long long;
using P   = pair<int,int>;
using vi  = vector<int>;
using vvi = vector<vi>;
using vp  = vector<P>;
using vl  = vector<ll>;

template<typename T> void Yes(T flag) {
  cout << (flag ? "Yes" : "No") << endl;
}

template<typename T> void pv(vector<T> vec) {
  cout << "[";
  for(auto& v : vec) { cout << v << ","; }
  cout << "]" << endl;
}

template<>
void pv(vector<P> vec) {
  cout << "[";
  for(auto& v : vec) {
    cout << "<" << v.fi << ","<< v.se << ">" << ",";
  }
  cout << "]" << endl;
}

template<typename T> void pv2(vector<vector<T>> vec) {
  for(auto& v : vec) pv(v);
}

// 条件をみたす数が何個あるか知りたいときの桁dp

const int keta = 101;
const int miflag = 2;
const int arsum = keta;
//桁 未満フラグ 条件達成数
ll dp[keta][miflag][arsum];

// 条件達成フラグ
bool archieve(int x,int k) {
    if(x!=0) return true;
    return false;
}

int archieveNum(int x,int k) {
  if(archieve(x,k)) return k+1;
  else return k;
}

void dpInit() {
    rep(i,keta) rep(j,miflag) rep(k,arsum) dp[i][j][k] = 0;
}

// v:上限 n:桁数 self:自分自身を含むか
ll ketaDP(vi &v,int n,int anum,bool self = true) {
  dpInit();
  dp[0][0][0] = 1;

  rep(i,n) rep(j,2) rep(k,n) rep(x,j ? 10 : v.at(i) + 1) {
    dp[i+1][j or x < v.at(i)][archieveNum(x,k)] += dp[i][j][k];
  }
  // anum = 条件達成数
  if(self) return dp[n][1][anum] + dp[n][0][anum];
  else return dp[n][1][anum];
}


int main() {
  string s;cin >> s;
  int n = s.size();
  vi v(n,0);
  rep(i,n) v.at(i) = s.at(i) - '0';
  int k;cin >> k;
  cout << ketaDP(v,n,k) << endl;

  return 0;
}
