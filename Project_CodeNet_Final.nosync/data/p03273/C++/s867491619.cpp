#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];

    vector<int> ck_w(w, 1), ck_h(h, 1);

    rep(i, w)
    {
        bool ck = true;
        rep(j, h)
        {

            if (a[j][i] == '#')
            {
                ck = false;
            }
        }
        if (ck)
        {
            ck_w[i] = 0;
        }
    }

    rep(i, h)
    {
        bool ck = true;
        rep(j, w)
        {

            if (a[i][j] == '#')
            {
                ck = false;
            }
        }
        if (ck)
        {
            ck_h[i] = 0;
        }
    }

    rep(i, h)
    {
        rep(j, w)
        {
            if (ck_h[i] && ck_w[j])
            {
                cout << a[i][j];
            }
        }
        if (ck_h[i])
        {
            cout << '\n';
        }
    }
    // cout << '\n';
    return 0;
}
