#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
struct Solution {
    void solve(std::istream& in, std::ostream& out) {
        ll x, y, z;
        in >> x >> y >> z;
        ll ans = 1;
        while (true) {
            if (y * ans + z * (ans + 1) > x) {
                break;
            }
            ans++;
        }
        ans--;
        out << ans << '\n';
    }
};
void solve(std::istream& in, std::ostream& out) {
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}
#include <fstream>
#include <iostream>
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    istream& in = cin;
    ostream& out = cout;
    solve(in, out);
    return 0;
}
