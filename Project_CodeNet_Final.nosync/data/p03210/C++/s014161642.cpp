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

//------------------------- Libraries -------------------------//

//--------------------------- Solve ---------------------------//

void solve() {
    int x; cin >> x;
    if (x == 7 || x == 5 || x == 3) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}