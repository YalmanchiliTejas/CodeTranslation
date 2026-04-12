#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const int inv2 = (mod + 1) / 2;
typedef long long ll;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
pair < int, int > solve(vector < int > h) {

    if (h.empty()) return make_pair(1, 2);     //// ???
    if (h.size() == 1) return make_pair(pw(2, h[0]), pw(2, h[0]));
    int mn = h[0];
    for (int i = 0; i < h.size(); i++) {
        if (h[i] == 1) {
            vector < int > nh1, nh2;
            for (int j = 0; j < i; j++) nh1.push_back(h[j]);
            for (int j = i + 1; j < h.size(); j++) nh2.push_back(h[j]);
            pair < int, int > f1 = solve(nh1);
            pair < int, int > f2 = solve(nh2);
            return make_pair(mult(2, mult(f1.first, f2.first)), mult(mult(f1.second, f2.second), inv2));
        }
        mn = min(h[i], mn);
    }
    vector < int > small;
    small.push_back(-1);
    for (int i = 0; i < h.size(); i++) {
        if (h[i] == mn) small.push_back(i);
    }
    small.push_back(h.size());
    vector < pair < int, int > > all;
    for (int j = 0; j + 1 < small.size(); j++) {
        vector < int > nh;
        if (small[j] + 1 == small[j + 1]) continue;
        for (int i = small[j] + 1; i < small[j + 1]; i++) {
            nh.push_back(h[i] - mn + 1);
        }
        all.push_back(solve(nh));
    }
    if (small.size() == h.size() + 2) {
        return make_pair(sub(sum(pw(2, mn), pw(2, h.size())), 2) ,pw(2, mn));
    }
    int num = small.size() - 2;
    int f2 = 1;
    for (int i = 0; i < all.size(); i++) {
        f2 = mult(f2, mult(all[i].second, inv2));
    }
    int final2 = mult(f2, pw(2, mn));
    int f1 = 1;
    for (int i = 0; i < all.size(); i++){
        f1 = mult(f1, all[i].first);
    }
    f1 = mult(f1, pw(2, num));
    f1 = sub(f1, mult(2, f2));
    f1 = sum(f1, final2);
    return make_pair(f1, final2);
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    int n;
    vector < int > h;
    cin >> n;
    h.resize(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    cout << solve(h).first;
    return 0;
}
