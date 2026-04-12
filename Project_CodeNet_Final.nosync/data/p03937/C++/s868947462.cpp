#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ALL(a) (a).begin(), (a).end()
const ll mod = 1e9 + 7;

int main()
{
    int h, w, ans = 0;
    cin >> h >> w;
    vector<string> A(h);
    rep(i, h) cin >> A[i];
    rep(i, h) rep(j, w)
    {
        if (A[i][j] == '#')
            ans++;
    }
    if (ans == h + w - 1)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}