#include <bits/stdc++.h>
#define INF (int)1e9
#define endl "\n"
#define ll long long
#define ull unsigned long long

using namespace std;
string a;

int main()
{
    cin >> a;
    int k;
    cin >> k;

    string b;
    b = a;
    b.assign(a.size(), '0');
    int ans = 0;
    if (k == 1)
    {
        for (int i = 0; i < a.size(); i++)
        {
            for (char x = '1'; x <= '9'; x++)
            {
                b[i] = x;
                ans += b <= a;
                b[i] = '0';
            }
        }
    }
    else if (k == 2)
    {
        for (int i = 0; i < a.size(); i++)
        {
            for (int x = '1'; x <= '9'; x++)
            {
                b[i] = x;
                for (int j = i + 1; j < a.size(); j++)
                {
                    for (char y = '1'; y <= '9'; y++)
                    {
                        b[j] = y;
                        ans += b <= a;
                        b[j] = '0';
                    }
                }
                b[i] = '0';
            }
        }
    }
    else
    {
        for (int i = 0; i < a.size(); i++)
        {
            for (int x = '1'; x <= '9'; x++)
            {
                b[i] = x;
                for (int j = i + 1; j < a.size(); j++)
                {
                    for (char y = '1'; y <= '9'; y++)
                    {
                        b[j] = y;
                        for (int k = j + 1; k < a.size(); k++)
                        {
                            for (char z = '1'; z <= '9'; z++)
                            {
                                b[k] = z;
                                ans += b <= a;
                                b[k] = '0';
                            }
                        }
                        b[j] = '0';
                    }
                }
                b[i] = '0';
            }
        }
    }

    cout << ans << endl;
}