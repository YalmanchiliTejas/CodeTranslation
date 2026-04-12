#include <cassert>
#include <iostream>
using namespace std;

long long A[51], P[51];

long long solve(int n, long long x) {
    if (x == 0) return 0;
    if (n == 0) return 1;
    if (1 + A[n-1] >= x) return solve(n-1, x-1);
    long long ans = P[n-1];
    x -= 1 + A[n-1];
    if (x == 0) return ans;
    ans++; x--;
    ans += solve(n-1, x);
    return ans;
}

int main(int argc, char** argv) {
    long long n, x; cin >> n >> x;
    A[0] = 1; P[0] = 1;
    for (int i = 1; i <= n; i++) {
        A[i] = 3 + 2 * A[i-1];
        P[i] = 1 + 2 * P[i-1];
    }
    cout << solve(n, x) << endl;
}
