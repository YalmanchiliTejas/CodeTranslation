#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1e9;

class starry_sky_tree {
public:
    starry_sky_tree(int n_)
    : n(expand(n_)), data(n * 2, 0), lazy(n * 2, 0)
    {}

    void add(int l, int r, int val) {
        l += n, r += n;
        const int left = l, right = r;
        while(l != r) {
            if(l & 1) {
                lazy[l] += val;
                data[l++] += val;
            }
            if(r & 1) {
                lazy[--r] += val;
                data[r] += val;
            }
            l /= 2, r /= 2;
        }
        l = left, r = right - 1;
        while(l /= 2, r /= 2) {
            data[l] = min(data[l * 2], data[l * 2 + 1]) + lazy[l];
            data[r] = min(data[r * 2], data[r * 2 + 1]) + lazy[r];
        }
    }

    // min
    int query(int l, int r) const {
        l += n, r += n;
        int res1 = inf, res2 = inf;
        while(l != r) {
            if(l & 1) res1 = min(res1, data[l++]);
            if(r & 1) res2 = min(res2, data[--r]);
            l /= 2, r /= 2;
            res1 += lazy[l - 1];
            res2 += lazy[r];
        }
        --l;
        while(l /= 2, r /= 2) {
            res1 += lazy[l];
            res2 += lazy[r];
        }
        return min(res1, res2);
    }

private:
    int expand(int n) {
        return n == 1 ? n : expand((n + 1) / 2) * 2;
    }

private:
    const int n;
    vector<int> data, lazy;
};

int main() {
    int N, Q;
    string s;
    cin >> N >> Q >> s;

    starry_sky_tree sum(N);
    set<int> right_paren;
    for(int i = 0; i < N; ++i) {
        if(s[i] == '(') {
            sum.add(i, N, 1);
        } else {
            sum.add(i, N, -1);
            right_paren.insert(i);
        }
    }

    while(Q--) {
        int q;
        cin >> q;
        q--;

        int ans = q;
        if(s[q] == '(') {
            sum.add(q, N, -2);
            right_paren.insert(q);
            ans = *right_paren.begin();
            right_paren.erase(ans);
            sum.add(ans, N, 2);
        } else {
            sum.add(q, N, 2);
            int lb = 0, ub = N - 1;
            while(ub - lb > 1) {
                const int mid = (lb + ub) / 2;
                if(sum.query(mid, N) >= 2) {
                    ub = mid;
                } else {
                    lb = mid;
                }
            }
            ans = ub;
            sum.add(ans, N, -2);
            right_paren.erase(q);
            right_paren.insert(ans);
        }
        swap(s[q], s[ans]);

        cout << ans + 1 << endl;
    }
}
