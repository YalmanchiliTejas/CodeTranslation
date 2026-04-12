
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
string s;

int solve(int i, int cnt, int upper, bool limit) {
    if (cnt == 0) return 1;
    if (i == n) return 0;
    if (limit) {
        int res = 0;
        if (upper != 0) {
            res += solve(i + 1, cnt - 1, s[i + 1] - '0', true); // choose upper
            res += solve(i + 1, cnt - 1, 0, false) * (upper - 1); // choose others
        }
        res += solve(i + 1, cnt, s[i + 1] - '0', upper == 0); // choose 0
        return res;
    } else {
        return solve(i + 1, cnt - 1, 0, false) * 9
               + solve(i + 1, cnt, 0, false);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> k;
    n = s.length();

    int res = solve(0, k, s[0] - '0', true);
    cout << res << endl;

    return 0;
}

