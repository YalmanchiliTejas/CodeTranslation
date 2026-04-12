#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)
typedef long long ll;

using namespace std;

template <typename T> void output(T, int);
int gcd(int a, int b);

class path {
  public:
    int num;
    int last;
    vector<bool> judge;
    path(int n) {
        num = 1;
        last = 1;
        judge.resize(n + 1);
        judge[1] = true;
    }

    path(const path &origin) {
        num = origin.num;
        last = origin.last;
        judge = origin.judge;
    }

    bool next(int a) {
        if (judge[a]) {
            return false;
        }
        num++;
        last = a;
        judge[a] = true;
        return true;
    }
};

int main() {
    // source
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;
    queue<path> p;
    path a(n);
    p.push(a);

    while (!p.empty()) {
        path t = p.front();
        p.pop();
        if (t.num == n) {
            ans++;
            continue;
        }

        rep(i, g[t.last].size()) {
            path p_temp = t;
            if (p_temp.next(g[t.last][i])) {
                p.push(p_temp);
            }
        }
    }

    cout << ans << endl;
    return 0;
}

template <typename T> void output(T a, int precision) {
    if (precision > 0) {
        cout << setprecision(precision) << a << "\n";
    } else {
        cout << a << "\n";
    }
}

template <typename T> T min(T a, T b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
