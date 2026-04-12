#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005];
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n == 0) {
        cout << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << a[n - 1];
    int i;
    for (i = n - 3; i >= 0; i -= 2) {
        cout << " " << a[i];
    }
    if (i == -2) {
        i = 1;
    } else {
        i = 0;
    }
    for (; i < n; i+= 2) {
        cout << " " << a[i];
    }
    cout << endl;
    return 0;
}
