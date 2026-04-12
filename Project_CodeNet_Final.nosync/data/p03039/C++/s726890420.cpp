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

class MODCOM{
  //nCr
  private:
    const ll MAX = 1000000;
    vll fac, finv, inv;
  public:
    MODCOM(void){
      fac.resize(MAX);
      finv.resize(MAX);
      inv.resize(MAX);

      fac[0] = fac[1] = 1;
      finv[0] = finv[1] = 1;
      inv[1] = 1;
      for(int i=2; i<MAX; ++i){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
      }
    };

    ~MODCOM(void){
      return;
    };

    ll calc(ll n, ll k){
      if(n<k) return 0;
      if(n<0 || k<0) return 0;
      return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
    };
};


int main(){
  cin.tie(0); // cut the cin and cout (default, std::flush is performed after std::cin)
  ios::sync_with_stdio(false); // cut the iostream and stdio (DON'T endl; BUT "\n";)

  ll N,M,K;
  IN(N,M,K);

  MODCOM com;

  ll x_cost=0, y_cost=0;

  for(ll d=1; d<N; ++d){
    x_cost += d*(N-d)*M*M;
    x_cost %= MOD;
  }
  ll tmp = com.calc((ll)(N*M-2), (ll)(K-2));
  x_cost *= tmp;
  for(ll d=1; d<M; ++d){
    y_cost += d*(M-d)*N*N;
    y_cost %= MOD;
  }
  y_cost *= tmp;

  OUT((x_cost%MOD + y_cost%MOD)%MOD);

  return 0;
}
