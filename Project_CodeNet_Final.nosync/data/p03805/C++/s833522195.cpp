#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    int n, m;
    cin >> n >> m;
    int p[n][n];
    rep(i, n) rep(j, n) p[i][j] = 0;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        p[a][b] = 1;
        p[b][a] = 1;
    }

    vector<int> v(n);
    iota(ALL(v), 0);
    int cnt = 0;
    do
    {
        if (v[0] == 0)
        {
            bool flag = 0;
            rep(i, n - 1)
            {
                if (p[v[i]][v[i + 1]] == 0)
                    flag = 1;
            }
            if (!flag)
                cnt++;
        }
    } while (next_permutation(ALL(v)));

    OP(cnt);

    return 0;
}