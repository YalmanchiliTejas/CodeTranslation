#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N;
    string s;
    cin >> N >> s;

    auto c = [](bool b) { return (b ? 'W' : 'S'); };

    auto f = [&](char c1, char c2, char c3, char c4) {
        string ans = "";
        char next  = 'A';
        char last;
        for (auto e : s) {
            if (e == 'o' && next == 'A') {
                ans.push_back(c1);
                next = c2;
                if (c1 == 'S') last = c2;
                else
                    last = (c2 == 'S' ? 'W' : 'S');
            } else if (e == 'x' && next == 'A') {
                ans.push_back(c3);
                next = c4;
                if (c3 == 'S') last = (c4 == 'S' ? 'W' : 'S');
                else
                    last = (c4 == 'S' ? 'S' : 'W');
            } else if (e == 'o' && next == 'S') {
                ans.push_back(next);
                next = (ans[ans.size() - 2] == 'S' ? 'S' : 'W');
            } else if (e == 'x' && next == 'S') {
                ans.push_back(next);
                next = (ans[ans.size() - 2] == 'S' ? 'W' : 'S');
            } else if (e == 'o' && next == 'W') {
                ans.push_back(next);
                next = (ans[ans.size() - 2] == 'S' ? 'W' : 'S');
            } else if (e == 'x' && next == 'W') {
                ans.push_back(next);
                next = (ans[ans.size() - 2] == 'S' ? 'S' : 'W');
            }
        };
        if (next == ans[0] && last == ans[ans.size() - 1]) {
            cout << ans << '\n';
            exit(0);
        }
    };

    for (int i = 0; i < (1 << 4); ++i) {
        char c1 = c(i & (1 << 0));
        char c2 = c(i & (1 << 1));
        char c3 = c(i & (1 << 2));
        char c4 = c(i & (1 << 3));
        f(c1, c2, c3, c4);
    }
    cout << "-1" << '\n';
}
