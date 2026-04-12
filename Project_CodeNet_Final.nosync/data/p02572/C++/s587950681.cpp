#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1000000007;
// const int mod = 998244353;

struct mint
{
    ll x;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint &operator+=(const mint m)
    {
        if((x += m.x) >= mod) x -= mod;
        return *this;
    }
    mint &operator-=(const mint m)
    {
        if((x += mod - m.x) >= mod) x -= mod;
        return *this;
    }
    mint &operator*=(const mint m)
    {
        (x *= m.x) %= mod;
        return *this;
    }
    mint operator+(const mint m) const
    {
        return mint(*this) += m;
    }
    mint operator-(const mint m) const
    {
        return mint(*this) -= m;
    }
    mint operator*(const mint m) const
    {
        return mint(*this) *= m;
    }
    mint pow(ll n) const
    {
        if(!n) return 1;
        mint m = pow(n>>1);
        m *= m;
        if(n & 1) m *= *this;
        return m;
    }
    mint inv() const { return pow(mod-2);}
    mint &operator/=(const mint m) { return *this *= m.inv();}
    mint operator/(const mint m) const { return mint(*this) /= m;}
};
istream &operator>>(istream &is, mint &m) { return is >> m.x;}
ostream &operator<<(ostream &os, const mint &m) { return os << m.x;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    ll sum = accumulate(A.begin(), A.end(), 0LL);
    mint ans = 0;
    for(int i=0; i<N; i++)
    {
        ans += ((sum - A[i]) % mod) * A[i];
    }
    cout << ans / 2 << endl;

    return 0;
}
