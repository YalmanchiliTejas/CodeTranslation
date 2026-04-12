#include <bits/stdc++.h>
using namespace std;

int mod = 0;
struct mint {
    long long x;
    mint(long long x=0):x((x%mod+mod)%mod){}
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
    mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

void Main()
{
    long n;
    int x;
    cin >> n >> x >> mod;
    vector<mint> a(mod);
    vector<long> aa(mod+1);
    vector<int> s(mod, -1);
    mint c = x;
    long i;
    for (i = 0; i < n; i++)
    {
        a[i] = c;
        aa[i+1] = c.x + aa[i];
        s[c.x] = i;
        c *= c;
        if (s[c.x] != -1) break;
    }
    int ss = s[c.x];
    if (i == n) { cout << aa[n] << endl; return; }
    cout << aa[i+1] 
            + (aa[i+1]-aa[ss])*((n-i-1)/(i-ss+1)) 
            + aa[(n-i-1)%(i-ss+1)+ss]-aa[ss]
        << endl;
        
    // x + x^2%m + x^4%m + x^8%m ... x^(2^i)%m
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Main();
    return 0;
}
