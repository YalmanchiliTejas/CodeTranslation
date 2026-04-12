#include <bits/stdc++.h>

using namespace std;

const int M = 2e5;
int n, arr[M];
long long memo[M][3], big = 2e16;

long long solve(int i, int twos) {
    if (i >= n) {
        if (n & 1) {
            if (twos > 2 || twos < 1)
                return -big;
            return 0;
        }
        if (twos > 1)
            return -big;
        return 0;
    }

    if (twos > 1 + (n & 1))
        return -big;

    long long &r = memo[i][twos];
    if (r == -1)
        r = arr[i] + max(solve(i + 2, twos), solve(i + 3, twos + (i < n - 2)));

    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(memo, -1, sizeof memo);
    cin >> n;
    long long ans = -2e18;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (n % 2 == 0)
        ans = max(solve(0, 0), solve(1, 1));
    else
        ans = max(max(solve(0, 0), solve(1, 1)), solve(2, 2));

    cout << ans << "\n";

    return 0;
}

/*

even at most 1
odd at most 2 and at least 1

1 2 3 4 5 6 7 8 9 10 11

*/