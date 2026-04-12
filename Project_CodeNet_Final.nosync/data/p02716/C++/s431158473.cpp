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
constexpr ll MOD = (ll)((1E+9)+7);

int main(){
  cin.tie(0); // cut the cin and cout (default, std::flush is performed after std::cin)
  ios::sync_with_stdio(false); // cut the iostream and stdio (DON'T endl; BUT "\n";)

  ll N;
  IN(N);
  vll A(N);
  REP(i,N) IN(A[i]);

  if(N%2==0){
    vll Even_sum(N/2+1, 0);
    vll Odd_sum(N/2+1, 0);
    REP(i,N/2) Even_sum[i+1] = Even_sum[i] + A[2*i];
    REP(i,N/2) Odd_sum[i+1] = Odd_sum[i] + A[N-1-2*i];

    ll ans = -(INFLL-1);
    REP(i,N/2+1){
      chmax(ans, Even_sum[i]+Odd_sum[N/2-i]);
    }

    OUT(ans);

  }else{
    ll ans = -(INFLL-1);
    //case 1
    ll ans1 = -(INFLL-1);
    REP(i,N/2){
      ans1 += A[2*i];
    }
    chmax(ans, ans1);
    FOR(i,N/2-1,0){
      ans1 -= A[2*i];
      ans1 += A[2*i+1];
      chmax(ans, ans1);
    }
    FOR(i,N/2-1,0){
      ans1 -= A[2*i+1];
      ans1 += A[2*i+2];
      chmax(ans, ans1);
    }

    //case2
    vll Even_sum_first(N/2+1, 0);
    vll Even_sum_last(N/2+1, 0);
    REP(i,N/2) Even_sum_first[i+1] = Even_sum_first[i] + A[2*i];
    REP(i,N/2) Even_sum_last[i+1]  = Even_sum_last[i]  + A[N-1-2*i];

    ll ans2 = -(INFLL-1);
    REP(i,N/2+1){
      chmax(ans2, Even_sum_first[i]+Even_sum_last[N/2-i]);
    }
    chmax(ans, ans2);

    //case3
    vll Odd_sum_first(N/2+1, 0);
    vll Odd_sum_last(N/2+1, 0);
    REP(i,N/2) Odd_sum_first[i+1] = Odd_sum_first[i] + A[2*i+1];
    REP(i,N/2) Odd_sum_last[i+1]  = Odd_sum_last[i]  + A[N-2-2*i];

    ll ans3 = -(INFLL-1);
    REP(i,N/2+1){
      chmax(ans3, Odd_sum_first[i]+Even_sum_last[N/2-i]);
      chmax(ans3, Even_sum_first[i]+Odd_sum_last[N/2-i]);
    }
    chmax(ans, ans3);

    chmax(ans, Odd_sum_first[N/2]);
    chmax(ans, Odd_sum_last[N/2]);
    chmax(ans, Even_sum_first[N/2]);
    chmax(ans, Even_sum_last[N/2]);

    //case4
    
    if(N>6){
      ll b_max = A[0] + A[3];
      ll c = 2;
      ll last_pos = 3;
      ll ans4 = b_max + Even_sum_last[N/2-c];
      while(last_pos+2<N){
        last_pos += 2;
        b_max += A[last_pos];
        c++;
        chmax(b_max, Even_sum_first[c-1]+A[last_pos]);
        chmax(ans4, b_max + Even_sum_last[N/2-c]);
      }
      chmax(ans, ans4);
    }

    OUT(ans);
  }

  return 0;
}
