#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
const ll MOD = 1000000007;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    ll g = gcd(a, b);
    return a / g * b;
}

ll mulMod(ll a, ll b)
{
    return (((a % MOD) * (b % MOD)) % MOD);
}

const string YES = "YES";
const string NO = "NO";

void solve(long long r, long long g, long long b)
{
    if ((100 * r + 10 * g + b) % 4 == 0)
    {
        cout << YES << endl;
    }
    else
    {
        cout << NO << endl;
    }
}

int main()
{
    long long r;
    scanf("%lld", &r);
    long long g;
    scanf("%lld", &g);
    long long b;
    scanf("%lld", &b);
    solve(r, g, b);
    return 0;
}
