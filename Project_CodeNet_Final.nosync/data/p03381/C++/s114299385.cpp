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
    int N; cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];

    vector<int> v = X;
    sort(v.begin(), v.end());

    int a = v[N/2-1], b = v[N/2];
    
    int ans;
    for (int i = 0; i < N; i++) {
        if (X[i] >= b) ans = a;
        if (X[i] <= a) ans = b;
        cout << ans << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}