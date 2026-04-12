#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define INF 1LL << 60;
#define LLINF 1e12
#define PI 3.14159265359
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
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

//std::cout << std::defaultfloat << std::setprecision(10);
////////////////////////////////////////
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    string S; cin >> S;

    REP(i, S.size()-1){
        if(S[i]=='A' and S[i+1]=='C'){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
