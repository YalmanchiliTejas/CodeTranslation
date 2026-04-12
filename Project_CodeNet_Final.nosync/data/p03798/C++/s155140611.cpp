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

    auto f = [&](char c1, char c2) {
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
                ans.push_back(c1);
                next = c2;
                if (c1 == 'S') last = (c2 == 'S' ? 'W' : 'S');
                else
                    last = (c2 == 'S' ? 'S' : 'W');
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

    f('S', 'S');
    f('S', 'W');
    f('W', 'S');
    f('W', 'W');
    
    cout << "-1" << '\n';
}
