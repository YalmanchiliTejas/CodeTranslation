#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cassert>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};

ll n, x, z[51], m[51];

ll num(ll a, ll b)
{
    if (a == 0)
        return 1;

    if (b == 0)
        return 0;

    if (b < z[a - 1])
        return num(a - 1, b - 1);

    ll r = 0;

    if (b >= z[a - 1])
    {
        if (m[a - 1] == 0)
        {
            r = num(a - 1, z[a - 1] - 1);
            m[a - 1] = r;
        }
        else
        {
            r = m[a - 1];
        }
    }

    if (b == z[a - 1])
        return r;

    if (b == z[a - 1] + 1)
        return r + 1;

    if (b >= z[a] - 2)
        return r * 2 + 1;

    return r + 1 + num(a - 1, b - (z[a - 1] + 2));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    fill(m, m + 51, 0);

    cin >> n >> x;

    z[0] = 1;

    for (int i = 1; i <= 50; i++)
    {
        z[i] = (z[i - 1] * 2) + 3;
    }

    ll res = num(n, x - 1);

    cout << res << endl;

    return 0;
}