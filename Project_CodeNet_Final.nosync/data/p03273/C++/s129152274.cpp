#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    string a[101];
    rep(r, H) cin >> a[r];

    rep(r, H)
    {
        bool f=false;
        rep(c, W) {
            bool f1=true, f2=true;
            rep(r2, H) if (a[r2][c] == '#') f1=false;
            rep(c2, W) if (a[r][c2] == '#') f2=false;
            if (f1 or f2) continue;
            f=true;
            cout << a[r][c];
        }
        if (f) cout << endl;
    }
}
