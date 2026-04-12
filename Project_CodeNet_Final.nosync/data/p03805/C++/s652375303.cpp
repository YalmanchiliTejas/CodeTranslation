#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
vector<ll> to[10];
//理論的には巡回セールスマン問題でやっているはずなのでしっかりできるようにしておこう
//DPで到着済みを表す配列とはまた異なる配列が必要。

vector<ll> done(10); //0だと訪れていない.1だと訪れたのできては行けない。
int n, m;
int dp(int u, int h) //閉回路の場合は親だけではないので、親情報はいらない・
{
    if (h == n - 1) //現在n-1歩目の時、たどり着いたとして1を返す。
    {
        return 1;
    }
    int res = 0;
    for (int x : to[u]) //木の要素
    {
        if (done[x] == 1)
        {
            continue;
        }
        done[x] = 1; //訪れたとして、
        res += dp(x, h + 1);
        //これだけではループを回したときに訪れたことになってしまう説があるので、うまく変更したいところ
        done[x] = 0; //訪れていないことにする。
    }
    return res;
}
int main()
{

    cin >> n >> m;
    vector<ll> a(m);
    vector<ll> b(m);
    rep(i, m)
    {
        int a, b;

        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    done[0] = 1;
    cout << dp(0, 0); //0からスタートして全部行くパターン(距離がn-1個になるパターン,今現在0歩)
}