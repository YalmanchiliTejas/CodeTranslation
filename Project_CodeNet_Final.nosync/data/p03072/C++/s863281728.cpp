#include <iostream>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
    int n, h;
    cin >> n;
    int ans = 0, mx = 0;
    rep(i,n) {
        cin >> h;
        if (mx <= h) {
            mx = h;
            ans++;
        }
    }
    cout << ans << endl;
}