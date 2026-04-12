#include <bits/stdc++.h>

using namespace std;

#define reps(i, n, m) for (int i = (int) (n); i < (int) (m); i++)
#define rep(i, n) reps(i, 0, (n))
#define ALL(v) (v).begin(), (v).end()

int main() {
    int n; cin >> n;
    rep(i, 1 << n) {
        cout << i << ":";
        int c = 0;
        int j = i;
        while (j) {
            if (j & 1) cout << " " << c;
            c++; j >>= 1;
        }
        cout << endl;
    }
}
