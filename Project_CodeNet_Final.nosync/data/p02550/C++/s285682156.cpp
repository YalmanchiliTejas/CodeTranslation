#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, x, m;
    cin >> n >> x >> m;

    vector<int> mod_kind(m, -1);

    long long buf = x, first, finish;

    vector<int> S;
    mod_kind[buf] = 0;
    S.push_back(buf);
    for (int i = 1; i <= 2 * m; i++)
    {
        buf *= buf;
        buf %= m;

        if(mod_kind[buf] == -1)
        {
            mod_kind[buf] = i;
            S.push_back(buf);
        }
        else
        {
            first = mod_kind[buf];
            finish = i - 1;
            break;
        }
    }

    long long ans = 0;
    if(n >= first)
    {
        for (int i = 0; i < first; i++)
        {
            ans += S[i];
        }
        n -= first;

        buf = 0;
        for (int i = first; i <= finish; i++)
        {
            buf += S[i];
        }
        
        ans += buf * (n / (finish - first + 1));

        for (int i = 0; i < (n % (finish - first + 1)); i++)
        {
            ans += S[first + i];
        }
        
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            ans += S[i];
        }
    }
    
    cout << ans << endl;
}