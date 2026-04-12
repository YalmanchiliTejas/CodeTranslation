    #include <iostream>
    #include <vector>
    #include <bits/stdc++.h>
    #define rep(i, n) for (int i = 0; i < (n); ++i)
    using namespace std;
    typedef long long ll;
    typedef pair<int, int> P;
     
    #define pb push_back
    #define eb emplace_back
    #define fi first
    #define se second
    #define bg begin()
    #define ed end()
    #define all(x) x.bg, x.ed
    #ifdef LOCAL
    #define dmp(x) cerr << __LINE__ << " " << #x << " " << x << endl
    #else
    #define dmp(x) void(0)
    #endif
     
    template <class t, class u>
    void chmax(t &a, u b)
    {
      if (a < b)
        a = b;
    }
    template <class t, class u>
    void chmin(t &a, u b)
    {
      if (b < a)
        a = b;
    }
    const int mod = 1000000007;
    struct mint
    {
      ll x; // typedef long long ll;
      mint(ll x = 0) : x((x % mod + mod) % mod) {}
      mint &operator+=(const mint a)
      {
        if ((x += a.x) >= mod)
          x -= mod;
        return *this;
      }
      mint &operator-=(const mint a)
      {
        if ((x += mod - a.x) >= mod)
          x -= mod;
        return *this;
      }
      mint &operator*=(const mint a)
      {
        (x *= a.x) %= mod;
        return *this;
      }
      mint operator+(const mint a) const
      {
        mint res(*this);
        return res += a;
      }
      mint operator-(const mint a) const
      {
        mint res(*this);
        return res -= a;
      }
      mint operator*(const mint a) const
      {
        mint res(*this);
        return res *= a;
      }
      mint pow(ll t) const
      {
        if (!t)
          return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1)
          a *= *this;
        return a;
      }
     
      // for prime mod
      mint inv() const
      {
        return pow(mod - 2);
      }
      mint &operator/=(const mint a)
      {
        return (*this) *= a.inv();
      }
      mint operator/(const mint a) const
      {
        mint res(*this);
        return res /= a;
      }
    };
    struct combination
    {
      vector<mint> fact, ifact;
      combination(int n) : fact(n + 1), ifact(n + 1)
      {
        assert(n < mod);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
          fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i)
          ifact[i - 1] = ifact[i] * i;
      }
      mint operator()(int n, int k)
      {
        if (k < 0 || k > n)
          return 0;
        return fact[n] * ifact[k] * ifact[n - k];
      }
    };
     
    template <class t>
    using vc = vector<t>;
    template <class t>
    using vvc = vc<vc<t>>;
     
    using vi = vc<int>;
    int gcd(int a, int b)
    {
      if (b == 0)
        return a;
      return gcd(b, a % b);
    }
    int lcm(int a, int b)
    {
      return (a * b) / gcd(a, b);
    }
     
    int main()
    {
      int n, m;
      cin >> n >> m;
      if(n == m)cout << "Yes" <<endl;
      else cout<<"No"<<endl;
    }