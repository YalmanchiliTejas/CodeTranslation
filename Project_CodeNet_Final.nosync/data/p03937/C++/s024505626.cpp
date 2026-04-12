#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef vector<string> vss;
struct Solution {
    void solve(std::istream& in, std::ostream& out) {
        ll h, w;
        in >> h >> w;
        vss s(h);
        for (int i = 0; i < h; i++) {
            in >> s[i];
        }
        ll cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cnt += s[i][j] == '#';
            }
        }
        if (cnt == h + w - 1) {
            out << "Possible" << '\n';
        }
        else {
            out << "Impossible" << '\n';
        }
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
