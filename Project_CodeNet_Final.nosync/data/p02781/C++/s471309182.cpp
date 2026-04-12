#include <bits/stdc++.h>
//F6編譯，右上三角形執行，ctrl+c強制停止執行  F5開啟exe
#define ll long long
#define maxn 10005
#define mod 1000000007
using namespace std;

typedef pair<int, int> P;

int n;
string s;
int k;
ll ans = 0;

int main()
{
    cin >> s;
    cin >> k;
    n = s.length();
    if (k == 1)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (i > 0)
                ans += 9;
            else
                ans += s[i] - '0';
        }
        printf("%lld\n", ans);
    }
    else if (k == 2)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (j > 0)
                    ans += 81;
                else
                {
                    ans += (s[j] - '1') * 9;
                    bool ok = 0;
                    for (int w = 1; w < i; w++)
                        if (s[w] > '0')
                            ok = 1;
                    if (ok)
                        ans += 9;
                    else
                        ans += s[i] - '0';
                }
            }
        }
        printf("%lld\n", ans);
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                for (int w = j - 1; w >= 0; w--)
                {
                    if (w > 0)
                        ans += 9ll * 9 * 9;
                    else
                    {
                        ans += (s[w] - '1') * 9ll * 9;
                        bool ok = 0;
                        for (int z = 1; z < j; z++)
                            if (s[z] > '0')
                                ok = 1;
                        if (ok)
                            ans += 81ll;
                        else
                        {
                            if (s[j] == '0')
                                continue;
                            ans += (s[j] - '1') * 9ll;
                            for (int z = j + 1; z < i; z++)
                                if (s[z] > '0')
                                    ok = 1;
                            if (ok)
                                ans += 9ll;
                            else
                                ans += (ll)(s[i] - '0');
                        }
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}
