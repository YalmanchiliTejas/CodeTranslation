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

template<class t, class u> t chmax(t&a,u b){if(a<b)a=b; return a;};
template<class t, class u> t chmin(t&a,u b){if(a>b)a=b; return a;};
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
constexpr ll MOD = (ll)((1E+9)+7);

ll N;
vll a;
vll a_tmp;

bool possible(ll K){
  ll val = 0;
  //debug_print("possible : ", K);
  REP(i,N){
    // a[i]+(K-v)-Nv < N
    // a[i]+K-v-Nv < N
    // a[i]+K-N < (N+1)v
    ll tmp = (a[i]+K-N)/(N+1);
    while(tmp*(N+1)>a[i]+K-N) tmp--;
    while(tmp*(N+1)<=a[i]+K-N) tmp++;
    if(tmp<0) tmp=0;
    val += tmp;
    //a_tmp[i] = a[i]+(K-tmp)-N*tmp;
    a_tmp[i] = tmp;
  }
  //debug_print(val, K);
  //vec_print(a_tmp);
  if(val<=K) return true;
  return false;
}

ll possible_judge(ll K){
  FOR(i, max((ll)0, K-N), K+N+1){
    debug_print(K, K-N, i);
    if(possible(i)) return i;
  }
  return -1;
}

ll binary_search(ll low, ll high){
  debug_print(low, high);
  if(high-low<N){
    return possible_judge((low+high)/2);
  }
  ll mid = (high+low)/2;
  ll tmp = possible_judge(mid);
  if(tmp<0) return binary_search(mid+N, high);
  if(low<mid-N) return binary_search(low, tmp);
  return tmp;
}

int main(){
  cin.tie(0); // cut the cin and cout (default, std::flush is performed after std::cin)
  ios::sync_with_stdio(false); // cut the iostream and stdio (DON'T endl; BUT "\n";)

  IN(N);
  a.resize(N);
  a_tmp.resize(N);
  bool flag = true;
  REP(i,N){
    IN(a[i]);
    if(a[i]>=N) flag = false;
  }

  if(flag){
    printf("0\n");
    return 0;
  }

  ll ans = binary_search(0, (1E16+1024)*N);

  printf("%lld\n", ans);

  return 0;
}