#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int N, Q;
    cin >> N >> Q;
    
    int head = 0;
    while (Q--) {
        int q, k;
        cin >> q >> k;
        if (q == 0) {
            cout << (head + k - 1) % N + 1 << endl;
        } else {
            head = (head + k) % N;
        }
    }
    return 0;
}
