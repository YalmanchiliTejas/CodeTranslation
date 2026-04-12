#include <bits/stdc++.h>
using namespace std;

/* define const */

/* finish defineing const */

int n, m;
long cnt = 0;
int a[100] = {};
int b[100] = {};
pair<int, int> p[100];

bool allt(bool *b)
{
    bool f = true;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == false)
        {
            f = false;
        }
    }
    return f;
}

void solve(int a, bool *b)
{
    bool tmp[10];
    for (int i = 1; i <= n; i++)
    {
        tmp[i] = b[i];
    }
    // コピー
    tmp[a] = true;

    if (allt(tmp))
    {
        cnt++;
        return;
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            if (p[i].first == a)
            {
                if (tmp[p[i].second] == false)
                {
                    // tmp[p[i].second] = true;
                    solve(p[i].second, tmp);
                }
                else
                {
                    //  continue;
                }
            }
            else if (p[i].second == a)
            {
                if (tmp[p[i].first] == false)
                {
                    // tmp[p[i].first] = true;
                    solve(p[i].first, tmp);
                }
                else
                {
                    // continue;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
        p[i] = make_pair(a[i], b[i]);
    }
 //   sort(p, p + m);
    bool b[10] = {false, true};
    solve(1, b);

    cout << cnt << endl;
}
