#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,double> pid;
typedef pair<pii,pid> PP;

int n, a, d, m, k;
const int INF = 1 << 28;

int main() {
    cin >> n >> a >> d >> m;

    vector<int> x(m), y(m), z(m);
    for (int i = 0; i < m; i++) {
        int y_, z_;
        cin >> x[i] >> y_ >> z_;
        y[i] = min(y_, z_);
        z[i] = max(y_, z_);
    }

    cin >> k;

    vector<int> ckk(m+1);
    int ck = k;
    ckk[m] = ck;
    for (int i = m-1; i > -1; i--) {
        if (!x[i] && y[i] <= ck && ck <= z[i]) {
            ck = z[i] - (ck - y[i]);
        }
        ckk[i] = ck;

    }

    int aa = a + (ck - 1) * d;
    for (int i = 0; i < m; i++) {
        if (y[i] <= ckk[i] && ckk[i] <= z[i]) {
            if (x[i] == 1) aa++;
            if (x[i] == 2) aa /= 2;
        }
    }

    cout << aa << endl;

    return 0;
}