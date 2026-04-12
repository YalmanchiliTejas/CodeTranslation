#include <bits/stdc++.h>
using namespace std;

long long under[110][5];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s; int k; cin >> s >> k;
    int n = s.size(); int cnt = 0;
    for (int i = 0; i < n; i++) {
        int sn = s[i] - '0';
        for (int u = 0; u <= 3; u++) {
            for (int d = 0; d < 10; d++) {
                under[i+1][u+(d!=0)] += under[i][u];
            }
        }
        for (int d = 0; d < sn; d++) {
            if ((cnt + (d!=0)) < 5) under[i+1][(d!=0)+cnt] += 1;
        }
        cnt += (sn != 0);
    }
    cout << under[n][k] + (cnt == k) << "\n";
    return 0;
}