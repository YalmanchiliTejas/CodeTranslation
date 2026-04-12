#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n;
    while (cin >> n && n != 0) {
        if (n == 0) return 0;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            ans += a[i];
        }
        cout << ans / (n - 2) << endl;
    }
}

