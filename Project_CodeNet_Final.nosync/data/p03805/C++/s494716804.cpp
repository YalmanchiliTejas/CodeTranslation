#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/* メモリ食い過ぎ注意 */
#define int ll
#define ALL(v) v.begin(), v.end()
#define _REP(i, n) for (int i = 0; i < n; i++)
#define REP(n) _REP(i, n)

/* define const */
const ll INF = (1ll << 60);
const ll MOD = (ll)1e9 + 7;
/* end defineing */

signed main()
{
    int n, m;
    int a[50], b[50];
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i] >> b[i];

    deque<int> dq;
    for (int i = 2; i <= n; i++)
        dq.push_back(i);

    int cnt = 0;
    do
    {
        bool f = true;
        dq.push_front(1);
        for (int i = 1; i < dq.size(); i++)
        {
            int j;
            for (j = 0; j < m; j++)
            {
                if ((a[j] == dq[i - 1] && b[j] == dq[i]) || (a[j] == dq[i] && b[j] == dq[i - 1]))
                {
                    // ok.
                    break;
                }
            }
            if (j == m)
            {
                f = false;
                break;
            }
        }
        if (f)
            cnt++;
        dq.pop_front();
    } while (next_permutation(dq.begin(), dq.end()));

    cout << cnt << endl;
}