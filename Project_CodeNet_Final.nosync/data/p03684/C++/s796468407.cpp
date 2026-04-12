#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<functional>

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

#define FOR(i,x,y) for(ll i=(ll)x; i<(ll)y; ++i)
#define REP(i,y) FOR(i, 0, y)
#define RFOR(i,x,y) for(ll i=(ll)x; i>=(ll)y; --i)
#define RREP(i,x) RFOR(i, x, 0)

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

constexpr int INF = (1<<30);
constexpr ll INFLL = 1LL<<62;
constexpr long double EPS = 1e-12;
constexpr ll MOD = (ll)((1E+9)+7);

class Kruskal{
  //Kruskal algorithm
  //calculation time complexity : O(|E| log |V|)
  private:
    struct edge { ll u, v, cost; };
    static bool comp(const edge& e1, const edge& e2){
      return e1.cost < e2.cost;
    }

    vector<edge> es;
    ll V, E;

    //for union find
    vector<ll> par; // parent
    vector<ll> rank; // depth

    //search the root
    ll find(ll x){
      if(par[x] == x) return x;
      return par[x] = find(par[x]);
    };

    //merge the sets x or y belong
    void unite(ll x, ll y){
      x = find(x);
      y = find(y);
      if(x == y) return;

      if(rank[x] < rank[y]){
        par[x] = y;
      }else{
        par[y] = x;
        if(rank[x] == rank[y]){
          rank[x]++;
        }
      }
      return;
    };

    bool same(ll x, ll y){
      return find(x) == find(y);
    }

  public:
    Kruskal(ll V, vector<ll> From, vector<ll> To, vector<ll> Cost){
      //num of vertex
      this->V = V;
      E = (ll)From.size();
      if((ll)To.size() != E || (ll)Cost.size() != E){
        fprintf(stderr, "Sizes are different, %ld %ld %ld\n", From.size(), To.size(), Cost.size());
        exit(0);
      }
      es.resize(E);
      for(ll i=0; i<E; ++i){
        es[i].u = From[i];
        es[i].v = To[i];
        es[i].cost = Cost[i];
      }

      sort(es.begin(), es.end(), comp);

      //union find initialization
      par.resize(V);
      rank.resize(V, 0);
      for(ll i=0; i<V; ++i) par[i] = i;

      return;
    };

    ~Kruskal(void){
      return;
    };

    ll calculate_minimum_cost(void){
      ll res = 0;
      for(ll i=0; i<E; ++i){
        edge e = es[i];
        if(!same(e.u, e.v)){
          unite(e.u, e.v);
          res += e.cost;
        }
      }
      return res;
    };
};


int main(){
  cin.tie(0); // cut the cin and cout (default, std::flush is performed after std::cin)
  ios::sync_with_stdio(false); // cut the iostream and stdio (DON'T endl; BUT "\n";)

  ll N;
  cin >> N;
  vll x(N), y(N);
  REP(i, N) cin >> x[i] >> y[i];
  vector<HOGE<ll, ll>> Hx(N), Hy(N);
  REP(i, N){
    Hx[i].key = i;
    Hx[i].value = x[i];
    Hy[i].key = i;
    Hy[i].value = y[i];
  }

  sort(Hx.begin(), Hx.end());
  sort(Hy.begin(), Hy.end());

  vll Left(N, -1), Right(N, -1), Up(N, -1), Down(N, -1);

  Right[Hx[0].key] = Hx[1].key;
  Up[Hy[0].key] = Hy[1].key;
  FOR(i, 1, N-1){
    Right[Hx[i].key] = Hx[i+1].key;
    Left[Hx[i].key] = Hx[i-1].key;
    Up[Hy[i].key] = Hy[i+1].key;
    Down[Hy[i].key] = Hy[i-1].key;
  }
  Left[Hx[N-1].key] = Hx[N-2].key;
  Down[Hy[N-1].key] = Hy[N-2].key;

  vll From(8*N, INFLL);
  vll To(8*N, INFLL);
  vll Cost(8*N, INFLL);

  REP(i, N){
    if(Right[i]!=-1){
      From[0*N+i] = i;
      To[0*N+i] = Right[i];
      Cost[0*N+i] = min(abs(x[i]-x[Right[i]]), abs(y[i]-y[Right[i]]));
      From[4*N+i] = Right[i];
      To[4*N+i] = i;
      Cost[4*N+i] = Cost[0*N+i];
    }
    if(Left[i]!=-1){
      From[1*N+i] = i;
      To[1*N+i] = Left[i];
      Cost[1*N+i] = min(abs(x[i]-x[Left[i]]), abs(y[i]-y[Left[i]]));
      From[5*N+i] = Left[i];
      To[5*N+i] = i;
      Cost[5*N+i] = Cost[1*N+i];
    }
    if(Up[i]!=-1){
      From[2*N+i] = i;
      To[2*N+i] = Up[i];
      Cost[2*N+i] = min(abs(x[i]-x[Up[i]]), abs(y[i]-y[Up[i]]));
      From[6*N+i] = Up[i];
      To[6*N+i] = i;
      Cost[6*N+i] = Cost[2*N+i];
    }
    if(Down[i]!=-1){
      From[3*N+i] = i;
      To[3*N+i] = Down[i];
      Cost[3*N+i] = min(abs(x[i]-x[Down[i]]), abs(y[i]-y[Down[i]]));
      From[7*N+i] = Down[i];
      To[7*N+i] = i;
      Cost[7*N+i] = Cost[3*N+i];
    }
  }

  Kruskal K(N, From, To, Cost);

  cout << K.calculate_minimum_cost() << "\n";

  return 0;
}