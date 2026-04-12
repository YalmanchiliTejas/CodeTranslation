#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int64 i = 0;i < (n);i++)
#define FOR(i, a, b) for(int64 i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
	return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
	for(auto &e:u) fill_v<T>(e,v...);
}

struct monoid {
	public:
	  static int64 op(const int64 a, const int64 b) {
	    return max(a, b);
	  }
	  static int64 e() { return -INF_LL; }
	};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64 N, Q;
  cin >> N >> Q;
  vector<int64> A(N);
  REP(i, N) cin >> A[i];
  segtree<int64, monoid::op, monoid::e> sg(A);
  REP(_, Q) {
    int64 t, a, b;
    cin >> t >> a >> b; a--;
    if (t == 1) {
      sg.set(a, b);
    } else if (t == 2) {
      cout << sg.prod(a, b) << endl;
    } else {
      cout << sg.max_right(a, [&](int64 x) { return x < b; }) + 1 << endl;
    }
  }
}

