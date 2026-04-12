#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    int h, w;
    cin >> h >> w;
    vector<string> v(h);
    rep(i, h) cin >> v[i];
    vector<bool> tate(h, true), yoko(w, true);
    rep(i, h) rep(j, w) if (v[i][j] == '#') tate[i] = false, yoko[j] = false;
    vector<string> ans;
    rep(i, h)
    {
        string s;
        rep(j, w) if (!tate[i] && !yoko[j]) s.push_back(v[i][j]);
        if (s.size() != 0)
            ans.push_back(s);
    }
    for (auto i : ans)
        cout << i << endl;
}
