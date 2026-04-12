#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

string n;
i32 k, l;

i64 com(i64 m, i64 r) {
    if (r < 0 || r > m) return 0;
    if (r == 0) return 1;
    return m * com(m-1, r-1) / r;
}

i64 solve(i32 i, i32 j, bool less) {
    if (j == 0) return 1;
    if (i == l) return 0;

    if (less) return com(l-i, j) * pow(9, j);
    if (n[i] == '0') return solve(i+1, j, false);
    return solve(i+1, j, true) + solve(i+1, j-1, true) * (n[i] - '1') + solve(i+1, j-1, false);
}

int main() {
    cin >> n;
    cin >> k;
    l = n.size();

    cout << solve(0, k, false) << endl;
}
