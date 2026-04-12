#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n + 1, -1);
    b[0] = MAX_INT;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int l = 0;
        int r = n;
        while (r > l + 1) {
            int m = (l + r) / 2;
            if (b[m] >= a[i]) {
                l = m;
            } else {
                r = m;
            }
        }
        b[l + 1] = a[i];
        res = max(res, l + 1);
    }
    cout << res << "\n";    

    return 0;
}