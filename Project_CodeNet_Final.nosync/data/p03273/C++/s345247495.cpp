#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> F(h);
    rep(i, h) cin >> F[i];
    //削除される行と列のインデックスを記録
    set<int> G, R;
    //行チェック
    rep(i, h)
    {
        int ok = 1;
        rep(j, w)
        {
            if (F[i][j] == '#')
                ok = 0;
        }
        if (ok)
            G.insert(i);
    }
    //列チェック
    rep(j, w)
    {
        int ok = 1;
        rep(i, h)
        {
            if (F[i][j] == '#')
                ok = 0;
        }
        if (ok)
            R.insert(j);
    }
    //再構成
    rep(i, h)
    {
        if (G.count(i))
            continue;
        rep(j, w)
        {
            if (R.count(j))
                continue;
            cout << F[i][j];
        }
        cout << endl;
    }
}