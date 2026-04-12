#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int n, h, maximum = 0, ans = 0;
    cin >> n;
    rep(i, n) {
        cin >> h;
        if(h >= maximum) {
            ans++;
            maximum = h;
        }
    }
    cout << ans << endl;
}