#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[3100][3100];
bool done[3100][3100];
vector<ll> A;
int n;
ll rec(int left, int right) {
    if (done[left][right]) return dp[left][right];
    if (left == right) return A[left];
    ll res = 0;
    res = max(A[left] - rec(left + 1, right), A[right] - rec(left, right - 1));
    done[left][right] = true;
    return dp[left][right] = res;
}
int main() {
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < 3100; i++) for (int j = i + 1; j < 3100; j++)
            done[i][j] = false;
    ll ans = rec(0, n - 1);
    cout << ans << endl;
    return 0;
}