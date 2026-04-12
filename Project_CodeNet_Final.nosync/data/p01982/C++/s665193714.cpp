#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, l, r;
    while (cin >> n >> l >> r, n) {
        int cnt = 0;
        vector<int> a(n);
        for (int &ai: a) cin >> ai;
        for (int x = l; x <= r; x++) {
            int idx = n;
            for (int i = 0; i < n; i++) if (x % a[i] == 0) { idx = i; break; }
            if (idx % 2 == 0) cnt += 1;
        }
        cout << cnt << endl;
    }
    return 0;
}
