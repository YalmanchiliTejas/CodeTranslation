#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100010;

int n, ans[Nmax], q;

bool viz[Nmax];

int main()
{
    int pi = 1, x, y;
    cin >> n >> q;
    ans[1] = 1;
    while(q --)
    {
        if(!viz[pi] && ans[pi])
        {
            if(pi - 1 >= 1)
            {
                ans[pi - 1] = 1;
                viz[pi - 1] = true;
            }
            if(pi + 1 <= n)
            {
                ans[pi + 1] = 1;
                viz[pi + 1] = true;
            }
        }
        cin >> x >> y;
        if(pi == x)
            pi = y;
        else if(pi == y)
            pi = x;
        swap(ans[x], ans[y]);
        swap(viz[x], viz[y]);
        if(!viz[pi] && ans[pi])
        {
            if(pi - 1 >= 1)
            {
                ans[pi - 1] = 1;
                viz[pi - 1] = true;
            }
            if(pi + 1 <= n)
            {
                ans[pi + 1] = 1;
                viz[pi + 1] = true;
            }
        }
    }
    int sum = 0;
    for(int i = 1 ; i <= n ; i++)
        sum += ans[i];
    cout << sum << "\n";
    return 0;
}
