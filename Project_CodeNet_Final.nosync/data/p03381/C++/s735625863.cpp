#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(c) begin(c), end(c)
#define dump(x) cerr << __LINE__ << ":\t" #x " = " << (x) << endl

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(c) begin(c), end(c)
#define dump(x) cerr << __LINE__ << ":\t" #x " = " << (x) << endl

int main () {
    int n;
    while (cin >> n) {
        vector<int> a(n);
        rep(i, n) {
            cin >> a[i];
        }
        auto b = a;
        sort(all(b));
        // 1 2 3 4 5 6
        // 1 2 3 3 4 5

        int m1 = b[n / 2 - 1];
        int m2 = b[n / 2];
        rep(i, n) {
            if (a[i] <= m1) {
                cout << m2;
            } else {
                cout << m1;
            }
            cout << ' ';
        }
        cout << endl;
    }
}
