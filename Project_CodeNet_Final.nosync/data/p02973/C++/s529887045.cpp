#include <bits/stdc++.h>
//F6編譯，右上三角形執行，ctrl+c強制停止執行  F5開啟exe
#define ll long long
#define maxn 200005
#define mod 998244353
using namespace std;

typedef pair<int, int> P;

int n;
deque<int> dq;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int now;
        scanf("%d", &now);
        bool ok = 0;
        int k;
        if (!dq.empty())
        {
            k = lower_bound(dq.begin(), dq.end(), now) - dq.begin();
            if (k - 1 >= 0)
                ok = 1;
        }
        if (!ok)
            dq.push_front(now);
        else
        {
            dq[k - 1] = now;
        }
    }
    printf("%d", dq.size());

    return 0;
}
