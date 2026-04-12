
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    long long n, x;
    cin >> n >> x;

    long long p_total = 0;
    for (int i = 1; i <= n; ++i) {
        long long p_num = (long long) pow(2, n + 1 - i) - 1;
        long long b_num = (long long) pow(2, n + 1 - i) - 2;
        if (p_num + b_num + 2 < x) {
            p_total += p_num + 1;
            x -= p_num + b_num + 2;
            if (i == n) p_total++;
        } else if (p_num + b_num + 2 == x) {
            // center patty
            p_total += p_num + 1;
            break;
        } else  if (p_num + b_num + 1 == x) {
            p_total += p_num;
            break;
        } else {
            x -= 1;
        }
        if (x <= 0) break;
    }

    cout << p_total << '\n';
    
    return 0;
}
