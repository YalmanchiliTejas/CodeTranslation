#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define repd(i, n) for (ll i = (ll)(n)-1; i >= 0; i--)
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;
using Graph = vector<vector<int>>; // グラフ型
using pint = pair<int, int>;

int N, M;
bool G[8][8]; // 2<= N <= 8

int main()
{
    cin >> N >> M;
    rep(i, M)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a][b] = G[b][a] = true;
    }

    vector<int> P(N);
    rep(i, N)
    {
        P[i] = i;
    }
    int ans = 0;

    // 順列の全探索
    do
    {
        if (P[0] != 0)
        {
            break; // 1始点じゃないとダメ
        }

        bool ok = true;
        rep(i, N - 1)
        {
            int from = P[i];
            int to = P[i + 1];
            if (!G[from][to])
            {
                ok = false;
            }
        }
        if (ok)
        {
            ans++;
        }
    } while (next_permutation(P.begin(), P.end()));
    cout << ans << endl;
}