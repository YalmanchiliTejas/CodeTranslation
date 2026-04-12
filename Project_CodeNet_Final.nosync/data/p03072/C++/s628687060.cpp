#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    auto ok = [&](int from, int v) {
        bool check = true;
        for (int j = from; j >= 0; j--) {
            check &= (vec[j] <= v);
        }
        return check;
    };
    int res = 1;
    for (int i = 1; i < n; i++) {
      res += ok(i - 1, vec[i]);
    }
    cout << res << '\n';
    return 0;
}
