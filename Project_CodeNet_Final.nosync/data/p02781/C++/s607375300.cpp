#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long int;

int main() {
    string s;
    int k;
    cin >> s >> k;
    vector<ll> n(s.size());
    for (size_t i = 0; i < s.size(); i++) {
        n[i] = s[i] - 48;
    }

    vector<vector<ll>> dp0(n.size(), vector<ll>(4));
    vector<vector<ll>> dp1(n.size(), vector<ll>(4));

    dp0[0][1] = 1;
    dp0[0][2] = 0;
    dp0[0][3] = 0;

    dp1[0][1] = n[0] - 1;
    dp1[0][2] = 0;
    dp1[0][3] = 0;

    for (size_t i = 1; i < n.size(); i++) {
        // same as n
        dp0[i][1] = (n[i] == 0) ? dp0[i - 1][1] : 0;
        dp0[i][2] = (n[i] == 0) ? dp0[i - 1][2] : dp0[i - 1][1];
        dp0[i][3] = (n[i] == 0) ? dp0[i - 1][3] : dp0[i - 1][2];

        dp1[i][1] = dp1[i - 1][1] + 9;
        dp1[i][2] = dp1[i - 1][2] + dp1[i - 1][1] * 9;
        dp1[i][3] = dp1[i - 1][3] + dp1[i - 1][2] * 9;

        if (n[i] != 0) {
            dp1[i][1] += dp0[i - 1][1];
            dp1[i][2] += dp0[i - 1][2] + dp0[i - 1][1] * max(n[i] - 1, 0LL);
            dp1[i][3] += dp0[i - 1][3] + dp0[i - 1][2] * max(n[i] - 1, 0LL);
        }
    }

    cout << (dp0[n.size() - 1][k] + dp1[n.size() - 1][k]) << endl;
}