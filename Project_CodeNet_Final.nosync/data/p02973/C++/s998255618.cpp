#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    // cout << setprecision(8) << setiosflags(ios::fixed);

    int n;
    cin >> n;

    multiset<int> memo;
    for (int i = 0, a; i < n; ++i) {
        cin >> a;
        if (memo.lower_bound(a) != memo.begin()) {
            auto it = memo.lower_bound(a);
            --it;
            memo.erase(it);
        }
        memo.insert(a);
    }

    cout << memo.size() << endl;

    return 0;
}
