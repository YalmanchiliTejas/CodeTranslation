#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    int ofs = 0;
    while (q--) {
        int op, k; cin >> op >> k;
        if (op == 0) cout << (ofs + k - 1) % n + 1 << endl;
        if (op == 1) ofs = (ofs + k) % n;
    }
    return 0;
}

