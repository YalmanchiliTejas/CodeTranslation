#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, h, maxim = 0, m;
    cin >> n;
    int res = 0;
    for (int i=0; i<n; i++) {
        cin >> m;
        if (m>=maxim) {
            maxim = m;
            res++;
        }
    }
    cout << res;
    return 0;
}