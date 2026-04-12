#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<double> vd;
typedef vector<vd> vdd;

#define FOR(i,x,y) for(ll i=(ll)x; i<(ll)y; ++i)
#define REP(i,y) FOR(i, 0, y)
#define RFOR(i,x,y) for(ll i=(ll)x; i>=(ll)y; --i)
#define RREP(i,x) RFOR(i, x, 0)
#define ALL(a) a.begin(), a.end()
#define pb push_back
#define debug_print(x...) cerr << "line " << __LINE__ << " : "; debug_print_in(x);

template <typename First>
void debug_print_in(First first){
  cerr << first << endl;
  return;
}

template <typename First, typename... Rest>
void debug_print_in(First first, Rest... rest){
  cerr << first << " ";
  debug_print_in(rest...);
  return;
}

void IN(void){
  return;
}

template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){
  cin >> first;
  IN(rest...);
  return;
}

template <typename First>
void OUT(First first){
  cout << first << endl;
  return;
}

template <typename First, typename... Rest>
void OUT(First first, Rest... rest){
  cout << first << " ";
  OUT(rest...);
  return;
}

template<class t, class u> void chmax(t&a,u b){if(a<b)a=b;};
template<class t, class u> void chmin(t&a,u b){if(a>b)a=b;};
int popcount(int t){return __builtin_popcount(t);} //GCC
int popcount(ll t){return __builtin_popcountll(t);} //GCC

template <typename T>
void vec_print(vector<T> VEC){
  REP(i, VEC.size()){
    cerr << VEC[i] << " ";
  }
  cerr << endl;
};

template <typename T>
void mat_print(vector<vector<T> > MAT){
  REP(i,MAT.size()){
    REP(j,MAT[i].size()){
      cerr << MAT[i][j] << " ";
    }
    cerr << endl;
  }
};

constexpr int INF = (1<<30);
constexpr ll INFLL = 1LL<<62;
constexpr long double EPS = 1e-12;
constexpr ll MOD = (ll)998244353;

ll N, S;
vll A;

/*
ll search(ll L){
  vll A_sum(S+1, 0);
  A_sum[0] = 1;
  ll ans = 0;
  FOR(l,L,N){
    vll A_copy(S+1, 0);
    for(ll i=0; i+A[l]<=S; ++i){
      A_copy[i+A[l]] += A_sum[i];
    }
    REP(i,S+1) A_sum[i] += A_copy[i];
    ans += A_sum[S];
  }
  return ans;
}
*/

int main(){
  cin.tie(0); // cut the cin and cout (default, std::flush is performed after std::cin)
  ios::sync_with_stdio(false); // cut the iostream and stdio (DON'T endl; BUT "\n";)

  IN(N, S);
  A.resize(N);
  REP(i,N) IN(A[i]);

  ll ans = 0;
  /*
  REP(i,N){
    //debug_print(i, search(i));
    ans += search(i);
  }
  */

  vll A_sum(S+1, 0);
  REP(i,N){
    A_sum[0] += 1;
    vll A_copy(S+1, 0);
    for(ll j=0; j+A[i]<=S; ++j) A_copy[j+A[i]] += A_sum[j];
    REP(j,S+1) A_sum[j] = (A_sum[j] + A_copy[j])%MOD;
    ans = (ans + A_sum[S])%MOD;
  }

  /*
  REP(Left,N){
    vll A_sum(S+1, 0);
    A_sum[0] += 1;
    FOR(i,Left,N){
      vll A_copy(S+1, 0);
      for(ll j=0; j+A[i]<=S; ++j){
        A_copy[j+A[i]] += A_sum[j];
      }
      REP(j,S+1) A_sum[j] += A_copy[j];
      ans += A_sum[S];
    }
  }
  */

  OUT(ans);

  return 0;
}