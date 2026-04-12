#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define INF 1LL << 60;
#define LLINF 1e12
#define PI 3.14159265359
#define ALL(a) (a).begin(), (a).end()
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int dy8[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dx8[] = {0, 1, 0, -1, 1, 1, -1, -1};
int ny, nx;
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll lcm(ll m, ll n)
{
    if ((0 == m) || (0 == n))
        return 0;
    return ((m / gcd(m, n)) * n);
}

ll llpow(ll x, ll y)
{
    ll ans = 1;
    REP(i, y)
    ans *= x;
    return ans;
}

ll llmin(ll x, ll y) { return x < y ? x : y; }
ll llmax(ll x, ll y) { return x > y ? x : y; }

unsigned GetDigit(unsigned num) { return to_string(num).length(); }

template <typename Container>
bool exist_in(const Container &c, const typename Container::value_type &v)
{
    return (c.end() != std::find(c.begin(), c.end(), v));
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

ll nCr(int n, int r)
{
    if (n == r or n == 0)
        return 1;
    if (n < r)
        return 0;
    if (r == 1)
        return n;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

//素因数分解
vector<ll> decom;

void decompositPrime(ll n)
{
    ll a = 2;
    while (n >= a * a)
    {
        if (n % a == 0)
        {
            decom.push_back(a);
            n /= a;
        }
        else
        {
            a++;
        }
    }
    decom.push_back(n);
}

//std::cout << std::defaultfloat << std::setprecision(10);
////////////////////////////////////////
int main()
{

    int X; cin >> X;
    if(X>=30) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
