#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

ll solve(string s, int k) {
    ll n = s.size();
    if (n < k) return 0;

    ll ans = 0;

    if (k == 1) {
        ans += s[0] - '0';
        ans += (n - 1) * 9;
    } else if (k == 2) {
        ans += (s[0] - '0' - 1) * 9 * (n - 1);
        ans += 81 * (n - 1) * (n - 2) / 2;
        string t = s.substr(1, n - 1);
        while (t.size() > 0 && t[0] == '0') t = t.substr(1, t.size() - 1);
        ans += solve(t, 1);
    } else if (k == 3) {
        ans += (s[0] - '0' - 1) * 81 * (n - 1) * (n - 2) / 2;
        ans += 729 * (n - 1) * (n - 2) * (n - 3) / 6;
        string t = s.substr(1, n - 1);
        while (t.size() > 0 && t[0] == '0') t = t.substr(1, t.size() - 1);
        ans += solve(t, 2);
    }

    return ans;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string n;
    int k;
    cin >> n >> k;

    solve(n, k);

    cout << solve(n, k) << "\n";
    return 0;
}