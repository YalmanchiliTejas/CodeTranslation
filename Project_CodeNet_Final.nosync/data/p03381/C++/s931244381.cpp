#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, x[200000], y[200000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
        y[i] = x[i];
    }
    sort(y, y + n);
    int ans1 = y[n/2-1], ans2=y[n/2];
    for (int i = 0; i < n; i++) {
        if (x[i] <= ans1) cout << ans2 << endl;
        else cout << ans1 << endl;
    }
    
    return 0;
}