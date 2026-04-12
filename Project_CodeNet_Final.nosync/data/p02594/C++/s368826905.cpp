//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

//----------------------- Print Function ----------------------//

inline void print() {
    cout << endl;
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest) {
    cout << first << ' ';
    print(rest...);
}

template <typename T>
void print(const vector<T> &v) {
    for (auto e : v) cout << e << ' ';
    cout << endl;
}

//------------------------- Libraries -------------------------//

//--------------------------- Solve ---------------------------//

void solve() {
    int x; cin >> x;
    cout << (x >= 30 ? "Yes" : "No") << '\n';
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}