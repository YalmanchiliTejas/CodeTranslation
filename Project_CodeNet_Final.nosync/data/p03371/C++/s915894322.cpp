#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    // ABピザは高々max(2X, 2Y)<2e5なので全探索
    LLONG A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    LLONG ans = 1e12;
    for (int ab = 0; ab <= max(2 * X, 2 * Y); ab += 2)
    {
        LLONG remX = max(X - ab / 2, 0LL);
        LLONG remY = max(Y - ab / 2, 0LL);
        ans = min(ans, remX * A + remY * B + ab * C);
    }
    cout << ans << endl;
}
