#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#include <map>
#include <climits>
#include <vector>
#include <set>
#include <string>
#include <numeric>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
const int N = 2 * (1e5 + 1);
const int INF = 1e9 + 5;
const long long MOD = 1e9 + 7;

int32_t main() {
    FAST_IO;
    int x;
    cin >> x;
    cout << (800*x) - ((x/15)*200);
    return 0;
}
