#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b, ans = 0;
    cin >> n >> m;
    vector<vector<bool>> v(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v.at(a - 1).at(b - 1) = true;
        v.at(b - 1).at(a - 1) = true;
    }
    vector<int> casee(n - 1);
    for (int i = 0; i < n - 1; i++) {
        casee.at(i) = i;
    }

    bool each;
    do {
        each = true;
        if (!v.at(0).at(casee.at(0) + 1)) each = false;
        else {
            for (int i = 0; i < n - 2; i++) {
                if (v.at(casee.at(i) + 1).at(casee.at(i + 1) + 1)) continue;
                else  {
                    each = false;
                    break;
                }
            }
        }
        if (each) {
            ans++;
        }
    } while (next_permutation(begin(casee), end(casee)));
    cout << ans << endl;
}