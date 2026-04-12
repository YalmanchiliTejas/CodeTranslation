#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int N;
vector<pii> B;
vector<int> X;

struct BIT {
    vector<pii> tree;
    void init() {
        tree = vector<pii>(4*N, pii(1e9, 0));
    }
    void upd(int idx, pii val, int l, int r, int n) {
        if(idx < l || r < idx) return;
        if(l == r) {
            tree[n] = val;
            return;
        }
        int m = (l + r)>>1;
        upd(idx, val, l, m, 2*n);
        upd(idx, val, m + 1, r, 2*n + 1);
        tree[n] = min(tree[2*n], tree[2*n + 1]);
    }
    pii quer(int a, int b, int l, int r, int n) {
        if(b < l || r < a) return pii(1e9, 0);
        if(a <= l && r <= b) return tree[n];
        int m = (l + r)>>1;
        pii L = quer(a, b, l, m, 2*n);
        pii R = quer(a, b, m + 1, r, 2*n + 1);
        return min(L, R);
    }
} mn, mx, tmp;

int main() {
    scanf("%d", &N);
    B.resize(N);
    mn.init();
    mx.init();
    tmp.init();
    int mnmx = 1e18;
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &B[i].first, &B[i].second);
        X.push_back(B[i].first);
        X.push_back(B[i].second);
        if(B[i].first >= B[i].second) swap(B[i].first, B[i].second);
        mn.upd(i, pii(-B[i].first, i), 0, N - 1, 1);
        mx.upd(i, pii(B[i].second, i), 0, N - 1, 1);
        tmp.upd(i, pii(B[i].first, i), 0, N - 1, 1);
        mnmx = min(mnmx, B[i].second);
    }
    sort(X.begin(), X.end());
    X.resize(unique(X.begin(), X.end()) - X.begin());
    long long ans = 1e18;
    int remx = 0, remn = 1e9;
    for(int i = 0; i < X.size(); i++) {
        if(X[i] > mnmx) break;
        int rmn = X[i], rmx;
        int bmn, bmx = X.back();

        while(tmp.tree[1].first < rmn) {
            pii t = tmp.tree[1];
            tmp.upd(t.second, pii(1e9, 0), 0, N - 1, 1);
            mn.upd(t.second, pii(1e9, 0), 0, N - 1, 1);
            mx.upd(t.second, pii(1e9, 0), 0, N - 1, 1);
            remn = min(remn, B[t.second].first);
            remx = max(remx, B[t.second].second);
        }

        rmx = max(-mn.tree[1].first, remx);
        bmn = min(mx.tree[1].first, remn);
        ans = min(ans, (long long)(rmx - rmn)*(bmx - bmn));
    }
    printf("%lld", ans);
}
