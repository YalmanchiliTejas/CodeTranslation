#include <iostream>
#include <vector>

using namespace std;

// template for creating 2d vector
template<typename T>
vector<vector<T>> make_2d_vector(size_t rows, size_t cols, T init)
{ return vector< vector<T> >(rows, vector<T>(cols, init)); }


#define debug(x) cout << #x << "==" << x << endl;

typedef long long ll;

int N, A, B, C, D;


const int inf = 1e+8;

const int mod = 1e+9 + 7;

typedef long long ll;

#define MAX_N 1001

ll pow(ll a, int b){
    int ret = 1;
    while(b){
        if(b & 1) ret = (1ll) * ret * a % mod;
        b >>= 1;
        a = (1ll) * a * a % mod;
    }
    return ret;
}

inline ll add(ll a, ll b) { return (a + b) % mod; }
inline ll sub(ll a, ll b) { return (a - b + mod) % mod; }
inline ll mul(ll a, ll b) { return (a * b) % mod; }
inline ll div(ll a, ll b) { return mul( a, pow(b, mod-2) ); }


ll fact[MAX_N+1], fact_inv[MAX_N+1];
void create_fact() {
  fact[0] = 1;
  fact_inv[0] = 1;
  for(int i = 1; i < MAX_N; i++) {
    fact[i] = mul(fact[i-1], i);
    fact_inv[i] = pow(fact[i], mod - 2);
  }
}

ll nPk(int n, int k) {
  // n! / (n-r)!
  return mul(fact[n], fact_inv[n-k]);
}


int memo[1001][1001];
bool checked[1001][1001];
ll rec(int g, int i) {

  // debug(g); debug(i);

  if( checked[g][i] ) return memo[g][i];

  if( i == 0 ) return 1;
  if( g == 0 ) return 0;

  ll res = 0;

  // g人グループを使わない
  // cout << g-1 << "," <<  i << "\n";
  res += rec( g-1, i);

  // g人グループを使えない
  if( g < A or g > B ) {
    return res;
  }

  // g人グループを使える
  for(ll k = C; k <= D; k++) {
    if( k*g <= i ) {
      ll comb = nPk(i, k*g);
      comb = mul(comb, pow(fact_inv[g], k) );
      comb = mul(comb, fact_inv[k] );
      res = add(res, mul(comb, rec( g-1, i-k*g )));
    }
  }
  checked[g][i] = true;
  memo[g][i] = res;
  return res;


}


int main() {
  ios::sync_with_stdio(false);

  create_fact();

  cin >> N >> A >> B >> C >> D;

  vector<int> a(N);
  for(int i = 0; i < N; i++) { cin >> a[i]; }

  cout << rec( B, N );
  // debug( rec( 2,3) );

  // debug( rec( 2,0) );

  return 0;
}
