#pragma region Macros
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
#pragma endregion

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i=0; i<4; i++) {
        string ani;
        if (i == 0) ani = "SS";
        else if (i == 1) ani = "WW";
        else if (i == 2) ani = "SW";
        else ani = "WS";
        for (int j=1; j<n-1; j++) {
            char pre = *(ani.end() - 2);
            if (s.at(j) == 'o') {
                if (ani.back() == 'S') {
                    ani.push_back(pre);
                } else {
                    if (pre == 'S') ani.push_back('W');
                    else ani.push_back('S');
                }
            } else {
                if (ani.back() == 'S') {
                    if (pre == 'S') ani.push_back('W');
                    else ani.push_back('S');
                } else {
                    ani.push_back(pre);
                }
            }
        }
        bool ok = true;
        if (ani.front() == 'S') {
            if (s.front() == 'o' && ani.at(1) != ani.back()) ok = false;
            if (s.front() == 'x' && ani.at(1) == ani.back()) ok = false;
        } else {
            if (s.front() == 'o' && ani.at(1) == ani.back()) ok = false;
            if (s.front() == 'x' && ani.at(1) != ani.back()) ok = false;
        }
        if (ani.back() == 'S') {
            if (s.back() == 'o' && *(ani.end()-2) != ani.front()) ok = false;
            if (s.back() == 'x' && *(ani.end()-2) == ani.front()) ok = false;
        } else {
            if (s.back() == 'o' && *(ani.end()-2) == ani.front()) ok = false;
            if (s.back() == 'x' && *(ani.end()-2) != ani.front()) ok = false;
        }

        if (ok) {
            cout << ani << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
