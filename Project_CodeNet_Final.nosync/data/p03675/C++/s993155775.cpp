#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, a[200000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = n - 1; i >= 0; i -= 2) {
        if (i != n - 1) cout << " ";
        cout << a[i];
    }
    for (int i = n % 2; i < n; i += 2) cout << " " << a[i];
    cout << endl;
    return 0;
}