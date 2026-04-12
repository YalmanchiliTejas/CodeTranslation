#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

ll mod;
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

class combination{
private:
    vector<mint> fact,inv,finv;
public:
    combination(int N){
        fact = inv = finv = vector<mint>(N+1);
        fact[0] = fact[1] = 1;
        inv[0] = inv[1] = 1;
        finv[0] = finv[1] = 1;
        for(ll i=2;i<=N;i++){
            fact[i] = fact[i-1]*i;
            inv[i] = (mint) mod - inv[mod%i]*(mod/i);
            finv[i] = finv[i-1]*inv[i];
        }
    }
    mint f(int i){
        return fact[i];
    }
    mint comb(int n,int k){
        if(n<k) return 0;
        if(n<0 || k<0) return 0;
        return fact[n]*finv[k]*finv[n-k];
    }
    mint hcomb(int n,int k){
        if(n==0 && k==0) return 1;
        return comb(n+k-1,k);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N >> mod;
    mint ans = 0;
    combination C(2*N);
    vec<ll> pow2(N+1,1);
    for(int i=1;i<=N;i++) pow2[i] = pow2[i-1]*2%(mod-1);
    vvec<mint> dp(N+1,vec<mint>(N+1));
    dp[0][0] = 1;
    for(int i=0;i<N;i++) for(int j=0;j<=i;j++){
        dp[i+1][j+1] += dp[i][j];
        dp[i+1][j] += dp[i][j];
        dp[i+1][j] += dp[i][j]*j;
    }

    for(int i=0;i<=N;i++){
        mint now = 0;
        mint t = 1;
        for(int j=1;j<=N-i;j++) t *= 2;
        for(int j=0;j<=i;j++){
            now += dp[i][j]*t.pow(j);
        }
        now *= C.comb(N,i)*((mint) 2).pow(pow2[N-i]);
        if(i%2) ans -= now;
        else ans += now;
    }

    cout << ans << "\n";
}