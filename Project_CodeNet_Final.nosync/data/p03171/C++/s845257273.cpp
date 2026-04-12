#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <cmath>

#include <queue>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MN = 1e5 + 5, MOD = 1e9 + 7;

int N, a[3005];
ll dp[3005][3005];

ll f(int l, int r) {
    if (dp[l][r]) return dp[l][r];
    if (l > r) return 0;
    if (l == r) return a[l];
    return dp[l][r] = max(a[l] - f(l + 1, r), a[r] - f(l, r - 1));
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    cout << f(1, N) << '\n';
    return 0;
}