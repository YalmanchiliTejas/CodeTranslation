#include <bits/stdc++.h>

#define endl '\n'
#define left aba
#define right abc
#define oo if(LOG)
#define pb push_back
#define FIO ios_base::sync_with_stdio(0); cin.tie(0)

#ifdef LOCAL
#define LOG 1
#else
#define LOG 0
#endif

using namespace std;

const int N = 3003;

int n;

int a[N];
long long dp[N][N][2];

long long go2(int left, int right);

long long go1(int left, int right) {
    if(left == right) return a[left];
    if(dp[left][right][0] != -1) return dp[left][right][0];
    return dp[left][right][0] = max(go2(left + 1, right) + a[left], go2(left, right - 1) + a[right]);
}

long long go2(int left, int right) {
    if(left == right) return -a[left];
    if(dp[left][right][1] != -1) return dp[left][right][1];
    return dp[left][right][1] = min(go1(left + 1, right) - a[left], go1(left, right - 1) - a[right]);
}

int main() {
    FIO;

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) for(int k = 0; k < 2; ++k) dp[i][j][k] = -1;
    cout << go1(0, n - 1) << endl;

    oo cout << "Time: " << (double)clock() / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
