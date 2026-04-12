#include <bits/stdc++.h>

using namespace std;
#define ll long long
const long double EPS = 1e-8;
const long double PI = acos(-1);
const int N = 3e3 + 2;
const int mod = 1e5 + 7;
ll mem[N][N][2];
int arr[N];
int n, k;

ll solve(int i = 0, int j = n - 1, int player = 0) {
    if (i > j)return 0;
    if (~mem[i][j][player])return mem[i][j][player];
    if (!player) {
        return mem[i][j][player] = max(solve(i + 1, j, !player) + arr[i], solve(i, j - 1, !player) + arr[j]);
    } else {
        return mem[i][j][player] = min(solve(i + 1, j, !player) - arr[i], solve(i, j - 1, !player) - arr[j]);
    }
}

int main() {
    cin >> n;
    memset(mem, -1, sizeof mem);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << solve() << endl;
}
