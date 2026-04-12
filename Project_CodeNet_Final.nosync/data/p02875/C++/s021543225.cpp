#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll mod = 998244353;
struct mint {
    ll x;
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
    int N;
    cin >> N;
    mint ans = 1;
    combination c(N);
    vector<mint> beki2(N+1,1);
    for(int i=1;i<=N;i++) beki2[i] = beki2[i-1]*2;
    for(int i=0;i<N;i++) ans *= 3;
    for(int i=N/2+1;i<=N;i++) ans -= c.comb(N,i)*beki2[N-i]*2;
    cout << ans.x << endl;
}