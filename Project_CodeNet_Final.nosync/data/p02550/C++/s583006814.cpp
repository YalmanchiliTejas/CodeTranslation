#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

// auto mod int
int mod;
// const int mod = 998244353;
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
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
      if (!t) return 1;
      mint a = pow(t>>1);
      a *= a;
      if (t&1) a *= *this;
      return a;
    }

    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}

    // bool operator==(const mint a) { return x == a.x; }
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

ll n, x;

int main() {
    cin >> n >> x >> mod;
    vector<ll> avec;
    avec.emplace_back(x);
    vector<bool> abvec(mod+1, false);
    vector<ll> amvec;
    vector<int> abivec(mod+1, -1);

    int pre = -1, last = -1;
    for(int i = 1; ; ++i) {
        if(avec[i-1] == 0) break;
        ll ai = avec[i-1]*avec[i-1];
        ai %= mod;
        if(abvec[ai]) {
            // cout << ai << endl;
            pre = abivec[ai];
            last = i-1;
            break;
        }
        abvec[ai] = true;
        amvec.emplace_back(ai);
        avec.emplace_back(ai);
        abivec[ai] = i-1;
    }

    // 止まることを確認
    int amlen = amvec.size();
    // cout << "now " << amlen << endl;
    if(amlen == 0) {
        cout << 0 << endl;
        return 0;
    }
    long long sum = x;
    if(amvec[amlen-1] == 0) {
        for(int i = 0; i < amlen; ++i) sum += amvec[i];
    }else {
        // ループする
        for(int i = 0; i < pre; ++i) sum += amvec[i];
        ll rest = n-1-(pre);
        ll rlen = last-pre;
        ll rsum = 0;
        ll cnt = rest/rlen;
        ll rcnt = rest - rlen*cnt;
        for(int i = pre; i < last; ++i) rsum += amvec[i];
        // cout << "rsum " << rsum << endl;
        sum += rsum*cnt;
        for(int i = 0; i < rcnt; ++i) sum += amvec[pre+i];
    }

    cout << sum << endl;
}