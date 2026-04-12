#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 50;

long long n, k;
long long ans;
long long len[N_MAX + 2];

long long solve(int n, long long k) {
    if(n == 0)
        return 1;
    if(k == 1)
        return 0;

    long long med = (len[n] / 2 + 1);

    if(k == med)
        return (1LL << n);
    else if(k < med)
        return solve(n - 1, k - 1);
    else
        return (1LL << n) + solve(n - 1, k - 2 - len[n - 1]);
}

int main() {
    cin >> n >> k;

    len[0] = 1;
    for(int i = 1; i <= N_MAX; i++)
        len[i] = 3 + 2 * len[i - 1];

    cout << solve(n, k) << '\n';

    return 0;
}
// BBPPPBPBPPPBB 7776544332100
// BPPPB
