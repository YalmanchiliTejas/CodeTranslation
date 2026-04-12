#include <bits/stdc++.h>

using namespace std;

int n;
int max_gap;
vector<long long> a;

long long used[3][200002];
long long dp[3][200002];

long long calc(int gap, int idx) {
    if (idx < 0) return 0;
    if (used[gap][idx]) return dp[gap][idx];
    long long ans = - (1LL << 60);
    for (int i = 0; i <= gap; i++) {
        ans = max(ans, a[idx] + calc(gap - i, idx - 2 - i));
        if (i != 0) ans = max(ans, calc(gap - i, idx - i));
    }
    used[gap][idx] = true;
    return dp[gap][idx] = ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        a.push_back(x);
    }
    max_gap = n % 2 == 0 ? 1 : 2;
    
    cout << calc(max_gap, n - 1) << endl;
    return 0;
}