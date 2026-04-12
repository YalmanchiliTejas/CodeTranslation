#include<bits/stdc++.h>
#define enld '\n'
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
constexpr ll INF = 1e18;
constexpr int inf = 1e9;
constexpr ll mod2 = 1000000007;
constexpr ll mod = 998244353;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[6] = {1, 0, -1, 0,1,1};
const int dy[6] = {0, 1, 0, -1,1,-1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ---------------------------------------------------------------------------

// snukeさんのmodint
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

// mint N;
//cout << N.x << endl;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,S;
    cin >> N >> S;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    vector<mint> q(S+1,0);
    mint ans = 0;
    for(int i=0; i<N; i++){
        q[0] += 1;
        vector<mint> q2(S+1,0);
        for(int j=0; j<=S; j++){
            q2[j] += q[j];
            if(j+A[i] <= S) q2[j+A[i]] += q[j];
        }
        q = q2;
        ans += q[S];
    }
    cout << ans.x << enld;
    return 0;
}