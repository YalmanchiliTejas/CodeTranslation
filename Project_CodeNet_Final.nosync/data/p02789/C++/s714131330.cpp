#include <bits/stdc++.h>
#define rep(i, n)                                                              \
    for (int64_t i = 0; i < (int64_t)(n); i++)                                 \
        ;
using namespace std;
using vi = vector<int64_t>;
using vvi = vector<vi>;
using namespace std;
int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t n, m;
    cin >> n >> m;
    if (n == m) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
