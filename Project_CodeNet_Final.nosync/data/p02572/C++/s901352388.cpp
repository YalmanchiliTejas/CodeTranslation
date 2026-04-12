#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

const unsigned long long M = 1000000007;

bitset<30> b;

unsigned long long inv2() {
    b = M-2;
    unsigned long long p = 2;
    unsigned long long ans = 1;
    for (int i = 0; i < b.size(); i++) {
        if (b.test(i)) {
            ans = (ans * p) % M;
        }
        p = (p * p) % M;
    }
    return ans;
}

int main() {
    int n;
    unsigned long long ans = 0;
    unsigned long long c;
    unsigned long long d = 0;
    unsigned long long j = inv2();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        ans = (ans + c) % M;
        d = (d + (c * c) % M) % M;
    }
    ans = ((((ans * ans) % M + M - d) % M) * j) % M;
    cout << ans << endl;
    return 0;
}
