#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    long long k; cin >> k;
    vector<long long> len(n + 1), pate(n + 1);
    len[0] = pate[0] = 1;
    for (int i = 1; i <= n; i++) {
        len[i] = 1 + len[i - 1] + 1 + len[i - 1] + 1;
        pate[i] = pate[i - 1] + 1 + pate[i - 1];
    }
    auto rec = [&](auto rec, int m, long long k) {
        if (k == len[m]) return pate[m];
        long long ans = 0;
        k--;
        if (k > 0) {
            long long l = min(k, len[m - 1]);
            ans += rec(rec, m - 1, l);
            k -= l;
        }
        if (k > 0) {
            ans++;
            k--;
        }
        if (k > 0) {
            long long l = min(k, len[m - 1]);
            ans += rec(rec, m - 1, l);
            k -= l;
        }
        return ans;
    };
    cout << rec(rec, n, k) << endl;
    return 0;
}
