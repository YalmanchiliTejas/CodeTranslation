#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
typedef long long ll;

int main(int argc, const char * argv[]) {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    
    if (2 * C >= A + B) {
        cout << X * A + Y * B << endl;
        return 0;
    }
    
    int Z = max(X, Y);
    int tmp = 2 * C * Z;
    int ans = tmp;
    int X_count = Z;
    int Y_count = Z;
    for (int i = Z - 1; i >= 0; i--) {
        tmp -= 2 * C;
        X_count -= 1;
        Y_count -= 1;
        if (X_count < X) {
            X_count += 1;
            tmp += A;
        }
        if (Y_count < Y) {
            Y_count += 1;
            tmp += B;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    
    return 0;
}

