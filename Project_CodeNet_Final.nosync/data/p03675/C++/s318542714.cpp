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
    int n; cin >> n;
    deque<int> deq;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (i & 1) deq.push_front(a);
        else deq.push_back(a);
    }
    
    if (n & 1) reverse(deq.begin(), deq.end());
    for (auto e : deq) cout << e << '\n';
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}