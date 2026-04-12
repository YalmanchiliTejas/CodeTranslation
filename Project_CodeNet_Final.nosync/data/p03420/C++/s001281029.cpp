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

    int n, k;

    cin >> n >> k;

    ll res = 0;

    for (int i = k + 1; i <= n; i++)
    {
        ll sum = 0;

        ll num = i - k;

        sum += ((n - (i - 1)) / i + 1) * num;

        int ma = (n - (i - 1)) / i;

        /*
        int l = k - 1, r = i;

        while (r - l > 1)
        {
            int mid = (l + r) / 2;

            if (mid + i * (ma + 1) > n)
                r = mid;
            else
                l = mid;
        }

        if (r - l)
            sum += l - k + 1;
            */

        if ((ma + 1) * i + k <= n)
            sum += max(0, (n % i) - k + 1);

        if (k == 0)
            sum--;

        res += sum;
    }

    cout << res << endl;

    return 0;
}