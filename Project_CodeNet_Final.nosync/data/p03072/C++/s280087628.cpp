#include <bits/stdc++.h>
using namespace std;
#define inf 999999999
#define loop(i, a, b) for (int i = (a), i##len = (b); i < i##len; ++i)
#define rep(i, n) loop(i, 0, n)
#define lin long long
#define lfl long double

int main(void)
{
    int n, h[100];

    cin >> n;
    rep(i,n)
    {
        cin >> h[i];
    }

    int res = 0;
    rep(i,n)
    {
        bool b = true;
        loop(j,0,i)
        {
            if(h[i]<h[j])
            {
                b = false;
                break;
            }
        }
        if(b)
            res++;
    }

    cout << res << endl;
    return 0;
}
