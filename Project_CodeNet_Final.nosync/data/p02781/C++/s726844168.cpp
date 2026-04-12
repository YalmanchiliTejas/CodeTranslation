#include <bits/stdc++.h>

#define ed cout << "\n";
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define ffor(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(i, n) ffor(i, 0, n)
#define All(obj) (obj).begin(), (obj).end()
#define INF ((ll)1e9 + 7)
#define c(a) cout << a << "\n";
using namespace std;
const int N = 100005;

int main()
{
    speed;
    cout << fixed << setprecision(6);
    /*start*/
    string n;
    int k;
    ll dp[101][2][5];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    cin >> n >> k;
    rep(i, n.size()) //最大で100回(nの桁数)回る
    {
        int a = n[i] - '0'; //char->int
        rep(smaller, 2)
        { /*調べてる桁のすぐ上の桁が
            ギリギリ(上限と同じ数字)の時0(false)
            この時は調べている桁の数字までを数える
            １なら0~9どの数字でもこの桁に入ることができる
            下の(smaller?9:a)はそれを表している
            1なら0~9で回し,0なら0~aで回す*/

            rep(j, k + 1) //jはi桁までに0が出た個数最大で３(kと同じ)

            {
                rep(d, (smaller ? 9 : a) + 1)
                {
                    if (d != 0)
                        dp[i + 1][smaller || (d < a)][j + 1] += dp[i][smaller][j];
                    else
                        dp[i + 1][smaller || (d < a)][j] += dp[i][smaller][j];
                }
            }
        }
    }
    c(dp[n.size()][0][k] + dp[n.size()][1][k]);

    return 0;
}