#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pullull;
typedef pair<ll, int> plli;
typedef pair<int, pii> pipii;
typedef vector<vector<int> > mati;
typedef vector<vector<double> > matd;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<pll> vpll;

#define FOR(i,x,y) for(ll i=(ll)x; i<(ll)y; ++i)
#define REP(i,y) FOR(i, 0, y)
#define RFOR(i,x,y) for(ll i=(ll)x; i>=(ll)y; --i)
#define RREP(i,x) RFOR(i, x, 0)
#define ALL(a) a.begin(), a.end()
#define pb push_back

inline void IN(void){
  return;
}

template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){
  cin >> first;
  IN(rest...);
  return;
}

inline void OUT(void){
  cout << "\n";
  return;
}

template <typename First, typename... Rest>
void OUT(First first, Rest... rest){
  cout << first << " ";
  OUT(rest...);
  return;
}

template <typename T>
void vec_print(vector<T> VEC){
  REP(i, VEC.size()){
    cout << VEC[i] << " ";
  }
  cout << "\n";
};

template <typename T>
void mat_print(vector<vector<T> > MAT){
  REP(i, MAT.size()){
    REP(j, MAT[i].size()){
      cout << MAT[i][j] << " ";
    }
    cout << "\n";
  }
};

template <typename CLASS1, typename CLASS2>
class HOGE{
  public:
    CLASS1 key;
    CLASS2 value;
    HOGE(void){
      return;
    };
    HOGE(CLASS1 key, CLASS2 value){
      this->key = key;
      this->value = value;
    };
    ~HOGE(void){
      return;
    };

    void print(void){
      cout << "key : " << key << ", value : " << value << "\n";
      return;
    };
    
    bool operator==(const HOGE &obj){
      return (this->value == obj.value);
    };
    bool operator<(const HOGE &obj){
      return (this->value < obj.value);
    };
    bool operator>(const HOGE &obj){
      return (this->value > obj.value);
    };
};

template <typename CLASS1, typename CLASS2>
bool operator==(const HOGE<CLASS1, CLASS2> &hoge1, const HOGE<CLASS1, CLASS2> &hoge2){
  return hoge1.value == hoge2.value;
};

template <typename CLASS1, typename CLASS2>
bool operator<(const HOGE<CLASS1, CLASS2> &hoge1, const HOGE<CLASS1, CLASS2> &hoge2){
  return hoge1.value < hoge2.value;
};

template <typename CLASS1, typename CLASS2>
bool operator>(const HOGE<CLASS1, CLASS2> &hoge1, const HOGE<CLASS1, CLASS2> &hoge2){
  return hoge1.value > hoge2.value;
};

constexpr int INF = (1<<30);
constexpr ll INFLL = 1LL<<62;
constexpr long double EPS = 1e-12;
constexpr ll MOD = (ll)((1E+9)+7);

ll N;
vll A;

class LIS{
  private:
    ll N;
    vll a;
    vll dp; // 長さがi+1である増加部分列における最終要素の最小値

  public:
    LIS(ll N_){
      N = N_;
      a.resize(N, 0);
      dp.resize(N, INFLL);
      return;
    }

    void update(ll i, ll n){
      a[i] = n;
      return;
    }

    ll solve(void){
      for(int i=0; i<N; ++i){
        *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
      }
      return ll(lower_bound(dp.begin(), dp.end(), INFLL) - dp.begin());
    }
};

int main(){
  cin.tie(0); // cut the cin and cout (default, std::flush is performed after std::cin)
  ios::sync_with_stdio(false); // cut the iostream and stdio (DON'T endl; BUT "\n";)

  IN(N);
  LIS lis(N);
  REP(i,N){
    ll tmp;
    IN(tmp);
    lis.update(N-1-i, tmp);
  }

  OUT(lis.solve());
  return 0;
}