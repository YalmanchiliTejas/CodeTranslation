#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i = 0; i < (n); i++)
typedef long long ll;
// Welcome to my source code!

int main() {
    int n;
    cin >> n;
    int h, ans = 0, top = 0;
    REP(i,n) {
        cin >> h;
        if (h >= top) {
            ans++;
            top = h;
        }
    }
    cout << ans << endl;
}