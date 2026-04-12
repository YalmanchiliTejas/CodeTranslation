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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W;
    string a[10];

    cin >> H >> W;
    REP(i, H)
    cin >> a[i];

    REP(i, H)
    REP(j, W)
    {
        int in = 0, out = 0;

        REP(k, 4)
        {
            if (i + dy[k] < 0 || H <= i + dy[k] || j + dx[k] < 0 || W <= j + dx[k])
                continue;

            if (a[i + dy[k]][j + dx[k]] == '#')
            {
                if (k == 1 || k == 3)
                    in++;
                else
                    out++;
            }
        }

        if (in > 1 || out > 1)
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    cout << "Possible" << endl;

    return 0;
}