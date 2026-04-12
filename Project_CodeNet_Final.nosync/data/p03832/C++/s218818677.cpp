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
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < MOD);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
}; 
combination cb(1005);

#pragma endregion library

mint ans = 0;
int n,a,b,c,d;

int main(){
    cin >> n >> a >> b >> c >> d;
    vv<mint> ans(n+1,vector<mint>(n+1));
    ans[a-1][0] = 1;
    repi(i,a,b+1){
        rep(k,n+1) ans[i][k] = ans[i-1][k];
        for(int j = c; j*i <= n && j <= d; ++j){
            rrep(k,n+1){
                if(k-j*i>=0)
                    ans[i][k]+=ans[i-1][k-j*i]*cb.ifact[i].pow(j)*cb.ifact[j];
            }
        }
    }
    cout << cb.fact[n]*ans[b][n] << '\n';
    
    

}