#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int before = 0, after[n];
    fill(after, after + n, 0);
    after[1] = 1;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (after[a] || after[b])
            swap(after[a], after[b]);
        if (before == a || before == b) {
            before = (before == a) ? b : a;
        }
        if (0 < before) after[before - 1] = 1;
        if (before < n - 1) after[before + 1] = 1;
    }
    after[before] = 1;
    int res = accumulate(after, after + n, 0);
    cout << res << endl;
    return 0;
}
