#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
vector<vector<ll>> dp(3010, vector<ll>(3010, -1));
vector<ll> a(3000, -1);
ll solve(int head, int tail) {
    if(dp[head][tail] != -1)
        return dp[head][tail];
    if(head == tail)
        return a[head];

    return dp[head][tail] = max(a[head] - solve(head + 1, tail),
                                a[tail] - solve(head, tail - 1));
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(0, n - 1) << endl;
}