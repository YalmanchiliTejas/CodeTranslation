#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    string n;
    cin >> n;
    int k;
    cin >> k;

    int len = n.size();
    vector<vector<long>> d_less(len + 1, vector<long>(k + 1));
    vector<vector<long>> d_equal(len + 1, vector<long>(k + 1));

    d_equal[0][0] = 1;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= k; j++) {
            for (char x = '0'; x <= '9'; x++) {
                int j2 = j + (x > '0');
                if (j2 > k) continue;
                d_less[i + 1][j2] += d_less[i][j];
                if (x < n[i]) {
                    d_less[i + 1][j2] += d_equal[i][j];
                } else if (x == n[i]) {
                    d_equal[i + 1][j2] += d_equal[i][j];
                }
            }
        }
    }
    long res = d_less[len][k] + d_equal[len][k];
    cout << res << "\n";

    return 0;
}