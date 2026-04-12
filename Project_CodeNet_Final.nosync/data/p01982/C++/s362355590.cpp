#include <iostream>
#include <vector>
using namespace std;

bool is_uruu(int x, vector<int> A) {
    for (int i = 0; i < A.size(); i++) {
        if (x % A[i] != 0) continue;
        return ((i + 1) % 2 != 0);
    }
    return (A.size() % 2 == 0);
}

int main() {
    int n, l, r;
    while (cin >> n >> l >> r, n + l + r) {
        vector<int> A(n);
        for(int i = 0; i < n; i++) cin >> A[i];

        int ans = 0;
        for (; l <= r; l++) ans += is_uruu(l, A);
        cout << ans << endl;
    }
}

