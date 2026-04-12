#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>

#define rep(i,x) for(int i = 0; i < x; i++)
#define rrep(i,x) for(int i = 1; i <= x; i++)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using ll = long long;
using namespace std;
const int INF = 1001001001;
const ll LINF = 1002003004005006007;
const int mod = 998244353;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
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
    int n, s; cin >> n >> s;
    vector<int> a_list(n);
    rep(i, n) cin >> a_list[i];
    mint ans = 0;
    vector<mint> dp(s + 1, 0);
    rep(index, n){
        dp[0] += 1;
        int a = a_list[index];
        for (int i = s; i >= a; --i){
            dp[i] = dp[i] + dp[i - a];
        }
        ans += dp[s];
    }
    cout << ans.x << endl;
}
