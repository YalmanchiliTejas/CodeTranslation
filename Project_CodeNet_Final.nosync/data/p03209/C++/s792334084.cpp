#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

vector<ll> memo1(51, -1);
vector<ll> memo2(51, -1);

ll level(ll N);
ll p(ll N);
ll f(ll N, ll X);

int main()
{
    ll N, X;
    cin >> N >> X;
    cout << f(N, X) << endl;
}

ll level(ll N)
{
    if (N == 0)
    {
        return memo1[N] = 1;
    }
    if (memo1[N] != -1)
    {
        return memo1[N];
    }
    return memo1[N] = 2 * level(N - 1) + 3;
}

ll p(ll N)
{
    if (N == 0)
    {
        return memo2[N] = 1;
    }
    if (memo2[N] != -1)
    {
        return memo2[N];
    }
    return memo2[N] = 2 * p(N - 1) + 1;
}

ll f(ll N, ll X)
{
    if (X <= 0)
    {
        return 0;
    }
    if (N == 0)
    {
        return 1;
    }
    if (level(N - 1) + 1 >= X)
    {
        return f(N - 1, X - 1);
    }
    else
    {
        return f(N - 1, X - 2 - level(N - 1)) + p(N - 1) + 1;
    }
}