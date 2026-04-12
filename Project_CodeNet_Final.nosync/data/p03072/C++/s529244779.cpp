#include <iostream>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

int main(void) {
    int n, ans = 1;

    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    
    vector<int> h(n);
    REP(i, n) {
        cin >> h[i];
    }

    int max_h = h[0];
    FOR(i, 1, n) {
        if (max_h <= h[i]) {
            max_h = h[i];
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}