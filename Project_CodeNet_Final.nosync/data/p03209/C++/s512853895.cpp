#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;

i64 bs[51], ps[51];

i64 get_size(int k, i64 x) {
    if (x == 0) return 0;
    if (x >= bs[k]) {
        return ps[k];
    }
    if (x > bs[k] / 2) {
        return (ps[k] / 2 + 1) + get_size(k - 1, x - (bs[k] / 2 + 1));
    }
    return get_size(k - 1, x - 1);
}

int main() {
    int n;
    cin >> n;
    bs[0] = 1, ps[0] = 1;
    for (int i = 1; i <= 50; i++) {
        bs[i] = bs[i - 1] * 2 + 3;
        ps[i] = ps[i - 1] * 2 + 1;
    }

    i64 x;
    cin >> x;
    cout << get_size(n, x) << endl;
}