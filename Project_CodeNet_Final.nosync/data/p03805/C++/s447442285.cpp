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
#include <cstring>
#include <climits>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define mp make_pair
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
constexpr int di[] = {0, 0, 1, -1};
constexpr int dj[] = {1, -1, 0, 0};

int n, m;

V g[10];

bool used[10];

int dfs(int i)
{
    int res = 0;

    used[i] = true;

    bool ok = true;
    REP(j, n)
    if (!used[j + 1])
        ok = false;

    if (ok)
    {
        used[i] = false;
        return 1;
    }

    for (int j : g[i])
    {
        if (!used[j])
            res += dfs(j);
    }

    used[i] = false;

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    REP(i, m)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    fill(used, used + n + 1, false);

    cout << dfs(1) << endl;

    return 0;
}