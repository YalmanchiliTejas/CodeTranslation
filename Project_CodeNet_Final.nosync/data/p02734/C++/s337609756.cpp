#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    int N,S;
    cin >> N >> S;
    vec<int> A(N);
    for(auto& x:A) cin >> x;
    vvec<mint> dp(N+1,vec<mint>(S+1,0));
    mint ans = 0;
    dp[0][0] = 1;
    for(int i=0;i<N;i++){
        dp[i+1][0] = 1;
        for(int j=0;j<=S;j++){
            dp[i+1][j] += dp[i][j];
            if(j+A[i]<=S) dp[i+1][j+A[i]] += dp[i][j];
        }
        ans += (dp[i+1][S]-dp[i][S])*(N-i);
    }
    cout << ans << "\n";
}