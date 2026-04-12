#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];

    for (int i = h - 1; i >= 0; i--) {
        bool ok = true;
        rep(j, w) {
            if (a[i][j] != '.') {
                ok = false;
                break;
            }
        }
        if (ok) {
            a.erase(a.begin() + i);
        }
    }

    for (int i = w - 1; i >= 0; i--) {
        bool ok = true;
        rep(j, a.size()) {
            if (a[j][i] != '.') {
                ok = false;
                break;
            }
        }
        if (ok) {
            rep(j, a.size()) {
                a[j].erase(a[j].begin() + i); 
            }
        }
    }

    rep(i, a.size()) {
        put(a[i]);
    }

    return 0;
}