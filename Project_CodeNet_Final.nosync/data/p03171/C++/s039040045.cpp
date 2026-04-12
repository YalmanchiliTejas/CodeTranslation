#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    const int N = 3000;
    static ll opt[N+2][N+1][2];
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= n; j++) {
            if(i <= j) {
                opt[i][j][0] = max(a[i] + opt[i + 1][j][1], a[j] + opt[i][j - 1][1]);
                opt[i][j][1] = min(opt[i + 1][j][0] - a[i], opt[i][j - 1][0] - a[j]);
            }
        }
    }
    cout << opt[1][n][0] << endl;
    return 0;
}
