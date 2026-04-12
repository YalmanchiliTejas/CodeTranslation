#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    
    int ans = 2000000000;
    rep(ab, 2 * max(X, Y) + 1) {
        int a = max(0, X - ab / 2);
        int b = max(0, Y - ab / 2);
        ans = min(ans, A * a + B * b + C * ab);
    }
    cout << ans << endl;
    return 0;
}
