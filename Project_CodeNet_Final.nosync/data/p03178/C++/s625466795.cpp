#include <iostream>
using namespace std;
const int mo = 1e9 + 7;
const int ma = 10005, m = 105;
#define int long long
struct mint
{
    int x;
    mint() : x(0) {}
    mint(int x) : x((x % mo + mo) % mo) {}
    mint &fix()
    {
        x = (x % mo + mo) % mo;
        return *this;
    }
    mint operator-() const { return mint(0) - *this; }
    mint &operator+=(const mint &a)
    {
        if ((x += a.x) >= mo)
            x -= mo;
        return *this;
    }
    mint &operator-=(const mint &a)
    {
        if ((x += mo - a.x) >= mo)
            x -= mo;
        return *this;
    }
    mint &operator*=(const mint &a)
    {
        (x *= a.x) %= mo;
        return *this;
    }
    mint operator+(const mint &a) const { return mint(*this) += a; }
    mint operator-(const mint &a) const { return mint(*this) -= a; }
    mint operator*(const mint &a) const { return mint(*this) *= a; }
    bool operator<(const mint &a) const { return x < a.x; }
    bool operator==(const mint &a) const { return x == a.x; }
};
istream &operator>>(istream &i, mint &a)
{
    i >> a.x;
    return i;
}
ostream &operator<<(ostream &o, const mint &a)
{
    o << a.x;
    return o;
}
mint dp[ma][m][2];
main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    dp[0][0][0] = 1;
    for( int i = 0; i < s.size(); i++ )for( int j = 0; j < n; j++ )for( int k = 0; k < 2; k++ ) for( int x = 0; x < 10; x++ )
    {
        int nk = k;
        if( !k && x > s[i] - '0' )continue;
        if( x < s[i] - '0' ) nk = 1;
        dp[i + 1][( j + x ) % n ][nk] += dp[i][j][k];
    }
    mint ans = dp[s.size()][0][0];
    ans += dp[s.size()][0][1];
    ans -= 1;
    cout << ans << endl;
    return 0;
}