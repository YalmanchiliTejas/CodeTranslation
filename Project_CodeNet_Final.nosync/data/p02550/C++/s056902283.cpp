#include <bits/stdc++.h>

#define debug(s) cout << s << endl
#define debug1(s, t) cout << s << " " << t << endl
#define debug2(s, t, u) cout << s << " " << t << " " << u << endl
#define printvec(v)       \
    for (auto &&i : v)    \
        cout << i << " "; \
    cout << endl
#define rep(n, i) for (int i = 0; i < n; i++)

using namespace std;
using i64 = long long;

int main()
{
    i64 n, x, m;
    cin >> n >> x >> m;

    vector<i64> mod;
    int initix = 0;
    bool flag = true;
    while (flag)
    {
        mod.push_back(x);
        x = (x * x) % m;

        for (int i = 0; i < mod.size(); i++)
        {
            if (mod[i] == x)
            {
                flag = false;
                initix = i;
                break;
            }
        }
    }

    int repsize = mod.size() - initix;    

    int residueix = (n - initix) % repsize;

    i64 repsum = 0;
    for (int i = initix; i < mod.size(); i++)
    {
        repsum += mod[i];
    }

    i64 ans = 0;
    for (int i = 0; i < initix; i++)
    {
        ans += mod[i];
    }

    ans += (n - initix ) / repsize * repsum;

    for (int i = initix; i < initix + residueix; i++)
    {
        ans += mod[i];
    }

    cout << ans << endl;

    // printvec(mod);
    // debug(initix);
    // debug(residueix);

    return 0;
}