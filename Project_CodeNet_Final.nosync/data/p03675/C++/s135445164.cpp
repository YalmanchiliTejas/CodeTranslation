#include <iostream>
#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int b[n];
    int p = 0;
    int flag = 0;
    int left = 0;
    int right = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (flag == 0) {
            b[left++] = a[i];
            flag = 1;
        } else {
            b[right--] = a[i];
            flag = 0;
        }
    }

    cout << b[0];
    for (int i = 1; i < n; i++) {
        cout << " " << b[i];
    }
    cout << endl;

    return 0;
}
