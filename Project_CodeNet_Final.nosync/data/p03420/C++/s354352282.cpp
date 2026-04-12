#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
#define inf 999999999
#define loop(i, a, b) for (int i = (a), i##len = (b); i < i##len; ++i)
#define rep(i, n) loop(i, 0, n)
#define lin long long

lin n, k;

int main(void)
{
    cin >> n >> k;

    if (k == 0)
    {
        lin nn = n * n;
        cout << nn << endl;
        return 0;
    }

    // right-top
    lin result = (n - k + 1) * (n - k) / 2;

    loop(i, k + 1, n + 1)
    {
        int full = (n + 1) / i - 1;
        result += full * (i - k);

        int rest = n - (full + 1) * i + 1;
        if (rest > k)
            result += (rest - k);
    }

    cout << result << endl;

    return 0;
}
