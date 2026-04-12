#include <bits/stdc++.h>

using namespace std;

const long long MN = -1e17;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<pair<int, int>, long long> mem;
    function<long long(int, int)> dp;
    dp = [&] (int i, int need) {
        int mx = (i+2)/2;
        if (need < 0 || need > mx) {
            return MN;
        }
        pair<int, int> pr(i, need);
        if (mem.count(pr) == 0) {
            mem[pr] = i < 0
                ? 0
                : max(dp(i-1, need), dp(i-2, need-1) + a[i]);
        }
        return mem[pr];
    };
    cout << dp(n-1, n/2) << endl;
}

