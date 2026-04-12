//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

//----------------------- Print Function ----------------------//

inline void print() {
    cout << '\n';
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest) {
    cout << first << ' ';
    print(rest...);
}

template <typename T>
void print(const T &a) {
    for (auto e : a) cout << e << ' ';
    cout << '\n';
}

//------------------------- Libraries -------------------------//

//--------------------------- Solve ---------------------------//

void solve() {
    long long N, X, M; cin >> N >> X >> M;
 
    bool flag = false;

    set<int> se;
    int x = X;
    for (int i = 0; i < M; i++) {
        se.insert(x);
        x = ((long long)x*x) % M;
        if (se.find(x) != se.end()) {
            flag = true;
            break;
        }
    }

    int xx = x, cnt = 0;
    long long sum = 0;
    for (int i = 0; i < M; i++) {
        cnt++;
        sum += xx;
        xx = ((long long)xx*xx) % M;
        if (xx == x) {
            break;
        }
    }

    long long ans = 0;
    xx = X;
    for (int i = 0; i < M; i++) {
        ans += xx;
        xx = ((long long)xx*xx) % M;
        if (xx == x) {
            N -= i+1;
            break;
        }
    }

    ans += sum * (N/cnt);

    if (flag) {
        int m = N % cnt;
        for (int i = 0; i < m; i++) {
            ans += x;
            x = ((long long)x*x) % M;
        }
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}