#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <climits>

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
constexpr int di[] = {0, 0, 1, -1};
constexpr int dj[] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll s[112345];
    cin >> n;
    REP(i, n)
    cin >> s[i];

    ll res = 0;

    for (int i = 1; i <= n; i++)
    {
        bool used[112345];
        memset(used, 0, sizeof(used));

        ll sum = 0;
        for (int j = 0; j < n; j += i)
        {
            if (used[j] || used[n - 1 - j] || j == n - 1 - j || n - 1 - j < i)
                break;

            used[j] = true;
            used[n - 1 - j] = true;

            sum += s[j] + s[n - 1 - j];
            res = max(res, sum);
        }
    }

    cout << res << endl;

    return 0;
}