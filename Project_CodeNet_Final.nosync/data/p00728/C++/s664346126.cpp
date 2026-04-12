#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <numeric>
#include <cstring>
#include <cmath>
#include <set>
#include <climits>
#include <queue>
#include <stack>

const int MOD = 1e9 + 7;
const int iINF = 1000000000;
const long long int llINF = 1000000000000000000;
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
using ll = long long int;
using P = pair<int, int>;
using edge = struct
{
    int to;
    int cost;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int n;

    while (cin >> n, n)
    {
        int s = 0;
        int maxs = 0, mins = iINF, sum = 0;

        rep(i, n)
        {
            cin >> s;
            maxs = max(maxs, s);
            mins = min(mins, s);
            sum += s;
        }

        cout << (sum - maxs - mins) / (n - 2) << endl;
    }

    return 0;
}
