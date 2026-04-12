#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int64_t s[100'000];

int main()
{
    int n;
    cin >> n;
    rep(i, n)
    {
        cin >> s[i];
    }

    int64_t result = -1e15;
    for (int c = 1; c <= n - 1; c++) {
        int r = (n - 1) % c;
        int a = r;
        int64_t score = 0;
        for (int i = a; i <= n - 1; i += c) {
            score += s[i];
        }
        for (int i = c; i <= n - 1 - r; i += c) {
            score += s[i];
        }

        for (int a = r + c; a <= n - 1; a += c) {
            score -= s[a - c];
            score -= s[n - 1 - (a - c)];
            if (r != 0 || 2 * a - c >= n - 1) {
                result = max(result, score);
            }
        }
    }

    cout << result << endl;
    return 0;
}