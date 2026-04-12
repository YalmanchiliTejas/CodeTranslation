#include<bits/stdc++.h>
using namespace std;

const int M = 1000000007;

// min
class minsegtree {
    const int ex = M;
    int n, s, t;
    vector<int> tr;
    int q(int k, int l, int r) {
        return r <= s || t <= l ? ex : s <= l && r <= t ? tr[k]
            : min(q(k << 1 | 1, l, l + r >> 1), q(k + 1 << 1, l + r >> 1, r));
    }
public:
    minsegtree() {}
    minsegtree(int m) {
        n = 1;
        while (n < m) n <<= 1;
        tr.clear();
        tr.resize((n << 1) - 1, ex);
    }
    void update(int j, const int x) {
        int i = j + n - 1;
        tr[i] = x;
        while (i > 0) {
            i = i - 1 >> 1;
            tr[i] = min(tr[i << 1 | 1], tr[i + 1 << 1]);
        }
    }
    int run(int _s, int _t) {
        s = _s;
        t = _t;
        return q(0, 0, n);
    }
};

// sum
class sumsegtree {
    const int ex = 0;
    int n, s, t;
    vector<long long> tr;
    long long q(int k, int l, int r) {
        return r <= s || t <= l ? ex : s <= l && r <= t ? tr[k]
            : q(k << 1 | 1, l, l + r >> 1) + q(k + 1 << 1, l + r >> 1, r);
    }
public:
    sumsegtree() {}
    sumsegtree(int m) {
        n = 1;
        while (n < m) n <<= 1;
        tr.clear();
        tr.resize((n << 1) - 1, ex);
    }
    void update(int j, const long long x) {
        int i = j + n - 1;
        tr[i] = x;
        while (i > 0) {
            i = i - 1 >> 1;
            tr[i] = tr[i << 1 | 1] + tr[i + 1 << 1];
        }
    }
    long long run(int _s, int _t) {
        s = _s;
        t = _t;
        return q(0, 0, n);
    }
};

long long gett(const vector<int>& x) {
    sumsegtree sg(x.size());
    long long ans = 0;
    for (int i = 0; i < x.size(); ++i) {
        ans += i - sg.run(0, x[i]);
        sg.update(x[i], sg.run(x[i], x[i] + 1) + 1);
    }
    return ans;
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    vector<int> idxs(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        --x[i];
        idxs[x[i]] = i;
    }
    sumsegtree sumsg(n);
    minsegtree minsg(n);
    for (int i = 0; i < n; ++i) {
        sumsg.update(i, 1);
        minsg.update(i, x[i]);
    }
    long long t = gett(x) - k;
    vector<int> ans;
    for (int i = 0; i < n && t > 0; ++i) {
        int ok = 1, ng = n;
        if (sumsg.run(0, n) - 1 <= t)
            ok = n;
        while (ok < ng - 1) {
            int m = (ok + ng) / 2;
            if (sumsg.run(0, m) - 1 <= t)
                ok = m;
            else
                ng = m;
        }
        int mi = minsg.run(0, ok);
        if (mi == M) continue;
        int idx = idxs[mi];
        ans.push_back(mi);
        minsg.update(idx, M);
        sumsg.update(idx, 0);
        x[idx] = M;
        t -= sumsg.run(0, idx);
    }
    for (int i = 0; i < n; ++i)
        if (x[i] != M)
            ans.push_back(x[i]);

    for (int i = 0; i < n; ++i)
        cout << ans[i] + 1 << "\n";

    return 0;
}

