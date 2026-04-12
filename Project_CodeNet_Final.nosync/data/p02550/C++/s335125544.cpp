/**
 *    author:  FromDihPout
 *    created: 2020-09-19
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n, x, m;
    cin >> n >> x >> m;
    
    vector<int> seen(m);
    long long sum = 0, move = 1;
    while (move <= n && seen[x] == 0) {
        sum += x;
        seen[x] = move;
        x *= x;
        x %= m;
        move++;
    }
    if (move == n) {
        cout << sum << '\n';
        return 0;
    }
    
    long long cycle_len = move - seen[x], rem = n - move + 1;
    long long extra_sum = 0, cycle_sum = 0;
    for (int i = 0; i < cycle_len; i++) {
        if (i < rem % cycle_len) {
            extra_sum += x;
        }
        cycle_sum += x;
        x *= x;
        x %= m;
    }
    
    sum += (rem / cycle_len) * cycle_sum + extra_sum;
    cout << sum << '\n';
    return 0;
}