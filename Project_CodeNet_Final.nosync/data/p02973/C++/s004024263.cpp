#include <bits/stdc++.h>

using namespace std;

void to_permutation(vector<int>& xs) {
    int n = (int)xs.size();
    vector<pair<int, int>> ys(n);
    for (int i = 0; i < n; ++i) {
        ys[i] = make_pair(xs[i], -i);
    }
    sort(ys.begin(), ys.end());
    for (int i = 0; i < n; ++i) {
        xs[-ys[i].second] = i;
    }
}

struct Fenwick {
    int n;
    vector<int> xs;
    Fenwick(int n): n(n), xs(n+1) {}
    void set(int p, int c) { // a[p] = max(a[p], c)
        while (p <= n) {
            xs[p] = max(xs[p], c);
            p += p&(-p);
        }
    }
    int get_max(int p) { // return max(a[1], a[2], ..., a[p])
        int hi = 0;
        while (p > 0) {
            hi = max(xs[p], hi);
            p -= p&(-p);
        }
        return hi;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> xs(n);
    for (int& x : xs) {
        cin >> x;
    }
    to_permutation(xs);
    Fenwick f(n);
    for (int i = n-1; i >= 0; --i) {
        int length = 1 + f.get_max(xs[i]);
        f.set(xs[i]+1, length);
    }
    cout << f.get_max(n) << endl;
    return 0;
}
