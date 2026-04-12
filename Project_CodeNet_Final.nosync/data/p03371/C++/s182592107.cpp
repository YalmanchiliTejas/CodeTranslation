#include <algorithm>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) sort((a).rbegin(), (a).rend())
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define FORSTEP(i, start, end, step) for (int i = start; i < end; i += step)
#define ALL(a) a.begin(), a.end()
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int sum1 = 0, sum2 = 0, sum3 = 0;

    sum1 = A * X + B * Y;

    int c = min(X, Y);
    sum2 += 2 * c * C;
    int diff = X - Y;
    if (diff > 0) {
        sum2 += diff * A;
    } else {
        sum2 -= diff * B;
    }

    sum3 = 2 * C * max(X, Y);

    int ans = min(sum1, min(sum2, sum3));

    cout << ans << endl;

    return 0;
}