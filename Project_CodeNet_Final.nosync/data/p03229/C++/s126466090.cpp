#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int index_left = 1, index_right = n - 2;
    int left = a[0], right = a[n - 1];
    ll ans = right - left;
    for (int i = 2; i < n; i++) {
        int r1 = abs(a[index_left] - left);
        int r2 = abs(a[index_left] - right);
        int r3 = abs(a[index_right] - left);
        int r4 = abs(a[index_right] - right);
        int r_max = max(max(r1, r2), max(r3, r4));
        if (r_max == r1) {
            ans += r1;
            left = a[index_left++];
        } else if (r_max == r2) {
            ans += r2;
            right = a[index_left++];
        } else if (r_max == r3) {
            ans += r3;
            left = a[index_right--];
        } else {
            ans += r4;
            right = a[index_right--];
        }
    }
    cout << ans << endl;
    return 0;
}
