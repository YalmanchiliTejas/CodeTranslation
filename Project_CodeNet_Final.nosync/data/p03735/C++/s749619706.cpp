#include "bits/stdc++.h"

#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i, x, n) for(int i = x; i >= n; i--)
#define rrep(i, n) RREP(i,n,0)
#define pb push_back
#define show_table(n, k, table) rep(i,n){ rep(j,k) cout << table[i][j] << " "; cout << endl;}

using namespace std;

template<class T> inline void chmax(T& a,T const& b){a=max(a,b);}
template<class T> inline void chmin(T& a,T const& b){a=min(a,b);}

using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;

// 変数ダンプ先。coutかcerr
#define DUMPOUT cout
 
// 提出時はコメントアウト
#define DEBUG_
 
#ifdef DEBUG_
#define DEB
#else
// DEB と打つとデバッグ時以外はコメントアウトになる
#define DEB /##/
#endif
 
// 変数ダンプ用マクロ。デバッグ時以外は消滅する
// 引数はいくつでもどんな型でも可（ストリーム出力演算子があればOK）
#define dump(...) DEB DUMPOUT<<"  "; \
DUMPOUT<<#__VA_ARGS__<<" :["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl; \
DUMPOUT<<"    "; \
dump_func(__VA_ARGS__)
 
// デバッグ用変数ダンプ関数
void dump_func() {
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&&... tail)
{
    DUMPOUT << head;
    if (sizeof...(Tail) == 0) {
        DUMPOUT << " ";
    }
    else {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}
 
// vector出力
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
    os << "{";
    for (int i = 0; i<vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}
 
const int mod=1e9+7,INF=1<<30;
const double EPS=1e-12,PI=3.1415926535897932384626;
const ll lmod = 1e9+7,LINF=1LL<<60;

int main(){
  // cin.tie(0);
  // ios::sync_with_stdio(false);
  int N; scanf("%d",&N);
  vl x(N),y(N);
  rep(i,N){
    scanf("%lld%lld",&x[i],&y[i]);
    if(x[i]>y[i]) swap(x[i],y[i]);
  }
  vi ind(N);
  iota(ind.begin(),ind.end(),0);
  sort(ind.begin(),ind.end(),[&](int l,int r){return x[l]<x[r];});
  ll ma = 0LL, mi = LINF;
  ll ans;
  ll rma = 0LL, bma = x[ind[N-1]], rmi = LINF, bmi = x[ind[0]];
  rep(i,N){
    // ma       -> r, mi       -> b
    // large(y) -> r, small(x) -> b
    chmax(rma,y[i]);
    chmin(rmi,y[i]);
  }
  ans = (rma - rmi) * (bma - bmi);
  chmin(rmi,x[ind[0]]);
  chmax(rma,x[ind[N-1]]);
  ll nxt1 = LINF, nxt2 = 0;
  ll bmi2 = LINF;
  for(auto i:ind){
    chmin(bmi2,nxt1);
    chmax(bma,nxt2);
    nxt1 = nxt2 = y[i];
    bmi = min(x[i],bmi2);
    // dump(bmi,bma);
    // dump(rmi,rma);
    chmin(ans,(rma - rmi) * (bma - bmi));
  }
  cout << ans << endl;
  return 0;
}
