#pragma region head
    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
    using vi = vector<int>;
    using vll = vector<ll>;
    using pi = pair<int, int>;
    using pll = pair<ll,ll>;
    template <class T> using vv = vector<vector<T>>;
    #define rep(i,n) for(int i = 0; i < (int)(n); i++)
    #define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
    #define rrep(i,n) for(int i = (int)(n)-1; i >= 0; i--)
    #define rrepi(i,a,b) for(int i = (int)(b)-1; i >= (int)(a); i--)
    #define all(x) (x).begin(), (x).end()
    #define rall(x) (x).rbegin(), (x).rend()    
    #define bit(n) (1LL<<(n))
    template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
    template<class T> inline bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
    const int INF = 1002003004;
    const ll LINF = 1002003004005006007ll;
    struct preprocess{preprocess()
    {cin.tie(nullptr);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}}____;
#pragma endregion head

#pragma region library
const int MOD = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%MOD+MOD)%MOD){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
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
  // for prime MOD
  mint inv() const {
    return pow(MOD-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};
ostream& operator<< (ostream& os, const mint& value) {
  os << value.x;
  return os;
}

#pragma endregion library

int main(){
    int n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];
    vector<mint> ac(n);
    ac[0] = a[0];
    rep(i,n-1){
        ac[i+1] = ac[i] + a[i+1];
    }
    mint ans = 0;
    repi(i,1,n){
        ans += (mint)a[i]*ac[i-1];
    }
    cout << ans << '\n';
    

}
