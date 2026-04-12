#include <bits/stdc++.h>
using namespace std;
using Int = long long;
#define PUTS(x) cout << (x) << endl;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define PB push_back
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ((int)(x).size())
int main() {
    Int n;
    cin >> n;
    auto v = vector<Int>(0);
    rep(i, n) {
        Int a;
        cin >> a;
        auto itr = upper_bound(ALL(v), a, greater<Int>());
        if (itr == v.end()) {
            v.PB(a);
        } else {
            auto d = distance(v.begin(), itr);
            v[d] = a;
        }
    }
    PUTS(SZ(v));
}