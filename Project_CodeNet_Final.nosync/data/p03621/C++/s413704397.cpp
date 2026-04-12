#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 998244353;
ll inv[10000100];
ll FactorialInv[10000100];
ll Factorial[10000100];
ll beki(ll a, ll b){
    a %= mod;
    if(b == 0){
        return 1;
    }
    ll ans = beki(a, b / 2);
    ans = ans * ans % mod;
    if(b % 2 == 1){
        ans = ans * a % mod;
    }
    return ans;
}
void init_combination(){
    const int MAX = 10000002;
    Factorial[0] = 1;
    inv[0] = 1;
    for(int i = 1; i <= MAX; i++){
        Factorial[i] = Factorial[i - 1] * i % mod;
    }
    FactorialInv[MAX] = beki(Factorial[MAX], mod - 2);
    for(ll i = MAX - 1; i >= 0; i--) {
        FactorialInv[i] = FactorialInv[i+1] * (i+1) % mod;
    }
    for(int i = 1; i <= MAX; i++) {
        inv[i] = FactorialInv[i] * Factorial[i-1] % mod;
    }
}
ll combination(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    if(a < b) return 0;
    ll ans = Factorial[a] * FactorialInv[b] % mod;
    ans = ans * FactorialInv[a - b] % mod;
    return ans;
}
string A, B;
ll same, diff;
vector<ll> dp[14];
template< ll mod, ll primitiveroot >
struct NumberTheoreticTransform {
  vector< vector< ll > > rts, rrts;
  void ensure_base(ll N) {
    if(rts.size() >= N) return;
    rts.resize(N), rrts.resize(N);
    for(ll i = 1; i < N; i <<= 1) {
      if(rts[i].size()) continue;
      ll w = mod_pow(primitiveroot, (mod - 1) / (i * 2));
      ll rw = inverse(w);
      rts[i].resize(i), rrts[i].resize(i);
      rts[i][0] = 1, rrts[i][0] = 1;
      for(ll k = 1; k < i; k++) {
        rts[i][k] = mul(rts[i][k - 1], w);
        rrts[i][k] = mul(rrts[i][k - 1], rw);
      }
    }
  }

  inline ll mod_pow(ll x, ll n) {
    ll ret = 1;
    while(n > 0) {
      if(n & 1) ret = mul(ret, x);
      x = mul(x, x);
      n >>= 1;
    }
    return ret;
  }

  inline ll inverse(ll x) {
    return mod_pow(x, mod - 2);
  }

  inline ll add(ll x, ll y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
  }

  inline ll mul(ll a, ll b) {
    return ll(1LL * a * b % mod);
  }

  void DiscreteFourierTransform(vector< ll > &F, bool rev) {
    const ll N = (ll) F.size();
    ensure_base(N);
    for(ll i = 0, j = 1; j + 1 < N; j++) {
      for(ll k = N >> 1; k > (i ^= k); k >>= 1);
      if(i > j) swap(F[i], F[j]);
    }
    for(ll i = 1; i < N; i <<= 1) {
      for(ll j = 0; j < N; j += i * 2) {
        for(ll k = 0; k < i; k++) {
          ll s = F[j + k], t = mul(F[j + k + i], rev ? rrts[i][k] : rts[i][k]);
          F[j + k] = add(s, t), F[j + k + i] = add(s, mod - t);
        }
      }
    }
    if(rev) {
      ll temp = inverse(N);
      for(ll i = 0; i < N; i++) F[i] = mul(F[i], temp);
    }
  }

  vector< ll > Multiply(const vector< ll > &A, const vector< ll > &B) {
    ll sz = 1;
    while(sz < A.size() + B.size() - 1) sz <<= 1;
    vector< ll > F(sz), G(sz);
    for(ll i = 0; i < A.size(); i++) F[i] = A[i];
    for(ll i = 0; i < B.size(); i++) G[i] = B[i];
    DiscreteFourierTransform(F, false);
    DiscreteFourierTransform(G, false);
    for(ll i = 0; i < sz; i++) F[i] = mul(F[i], G[i]);
    DiscreteFourierTransform(F, true);
    F.resize(A.size() + B.size() - 1);
    return F;
  }
};


void print(vector<ll> v) {
    cerr << "{";
    for(int i = 0; i < v.size(); i++) {
        if(i != 0) cout << ", ";
        cout << v[i];
    }
    cout << "}" << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    init_combination();
    cin >> A >> B;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == '1' and B[i] == '1') same++;
        if(A[i] != B[i]) diff++;
    }
    diff /= 2;
    //cerr << same << " " << diff << endl;
    NumberTheoreticTransform<mod, 3> NTT;
    for(int i = 0; i <= same; i++) {
        dp[0].push_back(FactorialInv[i+1]);
    }
    for(int i = 0; i < 13; i++) {
        //cerr << "---" << i << "---" << endl;
        //print(dp[i]);
        dp[i+1] = NTT.Multiply(dp[i], dp[i]);
        dp[i+1].resize(same + 1);
    }
    vector<ll> v;
    v.push_back(1);
    for(int i = 0; i <= 13; i++) {
        if(diff & (1 << i)) {
            //cerr << "NTT " << diff << " " << (diff & (1 << i)) << endl;
            v = NTT.Multiply(v, dp[i]);
            v.resize(same + 1);
        }
    }
    ll ans = Factorial[same+diff];
    ans = ans * Factorial[same] % mod;
    ans = ans * Factorial[diff] % mod;
    //print(v);
    ll factor = 0;
    for(ll i = 0; i <= same; i++) {
        //cerr << i << " " << FactorialInv[i] * v[same-i] << endl;
        if(same - i < v.size()) factor += v[same-i];
        factor %= mod;
    }
    //cerr << ans << " " << factor << endl;
    cout << ans * factor % mod << endl;
    return 0;
}
