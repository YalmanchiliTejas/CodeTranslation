#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = INT32_MAX;
    for(int AB=0; AB<=max(X, Y)*2; AB+=2) {
        ans = min(ans, A*max(X-AB/2, 0) + B*max(Y-AB/2, 0) + C*AB);
    }
    cout << ans << endl;
    return 0;
}
