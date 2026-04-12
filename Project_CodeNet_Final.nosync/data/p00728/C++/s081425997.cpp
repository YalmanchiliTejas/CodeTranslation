#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = 1LL << 60;
const lint mod = 1000000007;

template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    while (true) {
        int s;
        cin >> s;
        if (s == 0)
            return 0;
        int tot = 0;
        int nax = -1, nin = 10000;
        for (int i = 0; i < s; ++i) {
            int x;
            cin >> x;
            chmax(nax, x);
            chmin(nin, x);
            tot += x;
        }
        cout << (tot - nax - nin) / (s - 2) << "\n";
    }
    return 0;
}
