#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

constexpr ll mod = 998244353;
struct mint {
    ll x;
    mint(ll x=0):x((x%mod+mod)%mod){}
    
    friend ostream &operator<<(ostream& os,const mint& a){
        return os << a.x;
    }

    friend istream &operator>>(istream& is,mint& a){
        ll t;
        is >> t;
        a = mint(t);
        return (is);
    }

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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,S;
    cin >> N >> S;
    vec<int> A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    vvec<mint> dp(N+1,vec<mint>(S+1));
    mint ans = 0;
    for(ll i=0;i<N;i++){
        if(S>=A[i]){
            dp[i+1][A[i]] += i+1;
        }
        for(int j=1;j<S;j++){
            dp[i+1][j] += dp[i][j];
            if(j+A[i]<=S) dp[i+1][j+A[i]] += dp[i][j];
        }
    }
    for(ll i=1;i<=N;i++) ans += dp[i][S]*(N-i+1);
    cout << ans << "\n";
}