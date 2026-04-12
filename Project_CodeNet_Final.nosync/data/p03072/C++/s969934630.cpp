#include <iostream>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    int n, h, maxh = 0, ans = 0;
    cin >> n;
    rep(i, n) {
        cin >> h;
        if(maxh <= h) {
            maxh = h;
            ans++;
        }
    } 
    cout << ans << endl;
}