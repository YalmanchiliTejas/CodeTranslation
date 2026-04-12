#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<bool> sw(h, true), ww(w, true);
    string s[h];
    rep(i, h) cin >> s[i];
    rep(i, h)
    {
        rep(j, w)
        {
            if (s[i][j] == '#')
            {
                sw[i] = false;
                ww[j] = false;
            }
        }
    }
    rep(i, h)
    {
        bool bunish = true;
        rep(j, w)
        {
            if (sw[i] == true || ww[j] == true)
                continue;
            cout << s[i][j];
            bunish = false;
        }
        if (!bunish)
            cout << endl;
    }
    return 0;
}