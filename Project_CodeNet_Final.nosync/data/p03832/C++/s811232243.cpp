#include <iostream>
#include <vector>

using namespace std;

// template for creating 2d vector
template<typename T>
vector<vector<T>> make_2d_vector(size_t rows, size_t cols, T init)
{ return vector< vector<T> >(rows, vector<T>(cols, init)); }


#define debug(x) cout << #x << "==" << x << endl;

const int inf = 1e+8;

const int mod = 1e+9 + 7;

typedef long long ll;

// nHk = n+k-1Ck のために二倍にとる
#define MAX_N 2000

int N, A, B, C, D;

ll pow(ll a, int b){
    int ret = 1;
    while(b){
        if(b & 1) ret = (1ll) * ret * a % mod;
        b >>= 1;
        a = (1ll) * a * a % mod;
    }
    return ret;
}

ll add(ll a, ll b) {
  return (a + b) % mod;
}

ll mul(ll a, ll b) {
  return (a * b) % mod;
}

ll div(ll a, ll b) {
  return mul( a, pow(b, mod-2) );
}


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

ll nCk(int n, int k) {
  // nPk / k!
  return mul(nPk(n, k), fact_inv[k]);
}


// g人以下のグループで p人 を分ける
ll memo[MAX_N][MAX_N];
bool checked[MAX_N][MAX_N];
ll rec(int g, int p) {

  if (p == 0) return 1;
  if (g == 0) return 0;

  if(checked[g][p]) return memo[g][p];

  ll ret = 0;

  // g人グループを使わない
  ret = add(ret, rec(g-1, p) );

  // g人グループを使う（使えるなら，使える範囲で）
  if( A <= g and g <= B ) {
    for(int k = C; k <= D; k++) {
      if( k*g <= p ) {
        ll rest = rec(g-1, p - k*g );
        // pPg*k / (g!)^k / k!
        ll comb = nPk(p, g*k);
        comb = mul( comb, pow(fact_inv[g], k) );
        comb = mul( comb, fact_inv[k] );
        ret =  add(ret, mul(rest, comb) );
      }
    }
  }

  checked[g][p] = true;
  memo[g][p] = ret;
  return ret;

}


int main() {
  ios::sync_with_stdio(false);

  create_fact();

  cin >> N >> A >> B >> C >> D;

  cout << rec(N, N) << "\n";

  return 0;
}
