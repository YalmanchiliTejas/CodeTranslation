#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MN = 200010;

int N;
pii P[MN];
ll ans;

int Xn;
vector<int> X;
map<int, int> dx;

struct Fenwick {
    vector<int> tree;
    void init() {
        tree = vector<int>(Xn + 1, 0);
    }
    void upd(int idx, int val) {
        for(int i = idx + 1; i <= Xn; i += (i & -i)) tree[i] += val;
    }
    int kquer(int k) {
        int ret = 0;
        for(int i = 20; i >= 0; i--) {
            if(ret + (1 << i) > Xn) continue;
            if(tree[ ret + (1 << i) ] < k) {
                k -= tree[ ret + (1 << i) ];
                ret += (1 << i);
            }
        }
        return ret;
    }
} fw;

vector<pii> E[MN << 1];

int main() {
    scanf("%d", &N);

    int mn1 = 1e9;
    int mn2 = 1e9;
    int mx1 = -1e9;
    int mx2 = -1e9;
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &P[i].first, &P[i].second);
        if(P[i].first > P[i].second) swap(P[i].first, P[i].second);
        mn1 = min(mn1, P[i].first);
        mx1 = max(mx1, P[i].first);
        mn2 = min(mn2, P[i].second);
        mx2 = max(mx2, P[i].second);

        X.push_back(P[i].first);
        X.push_back(P[i].second);
    }

    ans = 1LL * (mx1 - mn1) * (mx2 - mn2);

    sort(X.begin(), X.end());
    X.resize(unique(X.begin(), X.end()) - X.begin());
    Xn = X.size();
    for(int i = 0; i < Xn; i++) dx[X[i]] = i;
    for(int i = 0; i < N; i++) {
        P[i].first = dx[ P[i].first ];
        P[i].second = dx[ P[i].second ];

        E[ P[i].first ].push_back({ P[i].first, 1 });
        E[ P[i].first ].push_back({ P[i].second, -1 });
        E[ P[i].second ].push_back({ P[i].second, 1 });
    }

    fw.init();
    for(int i = Xn - 1; i >= 0; i--) {
        for(int j = 0; j < E[i].size(); j++) {
            fw.upd(E[i][j].first, E[i][j].second);
        }
        int x = fw.kquer(N);
        if(x == Xn) continue;

        //cout << i << ' ' << X[i] << ' ' << X[x] << endl;

        ans = min(ans, 1LL * (mx2 - mn1) * (X[x] - X[i]));
    }
    printf("%lld", ans);
}
