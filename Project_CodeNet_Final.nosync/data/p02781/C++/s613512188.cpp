#pragma GCC optimize(2)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 10, M = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

int n, m;
string s;

bool check(string t)
{
    if (t.size() == s.size())
    {
        if (t <= s)
        {
            //cout << t << endl;
            return 1;
        }
        return 0;
    }
    //cout << t << endl;
    return 1;
}

int main()
{
    cin >> s;
    int k;
    cin >> k;
    ll ans = 0;
    int len = s.size();
    if (k == 1)
    {
        int first = s[0] - '0';
        for (int i = 1; i < 10; i++)
        {
            if (i <= first)
                ans += len;
            else
            {
                ans += len - 1;
            }
        }
    }
    if (k == 2)
    {
        for (int i = 1; i < len; i++)
        {
            for (int j = 1; j < 10; j++)
            {
                for (int k = 1; k < 10; k++)
                {
                    string t = to_string(j);
                    for (int u = 1; u < i; u++)
                        t += '0';
                    t += k + '0';
                    if(i != len - 1)
                        ans++;
                    else if (check(t))
                        ans++;
                    for (int u = i + 1; u < len; u++)
                    {
                        t += '0';
                        if(u != len - 1)
                            ans++;
                        else if (check(t))
                            ans++;
                    }
                }
            }
        }
    }
    if (k == 3)
    {
        for (int i = 1; i < len - 1; i++)
        {
            for (int j = 1; j < 10; j++)
            {
                for (int k = 1; k < 10; k++)
                {
                    string t = to_string(j);
                    for (int u = 1; u < i; u++)
                        t += '0';
                    t += k + '0';
                    string str = t;
                    for (int u = 1; u < 10; u++)
                    {
                        string tmp = str;
                        tmp += u + '0';
                        if(i != len - 2)
                            ans++;
                        else if (check(tmp))
                            ans++;
                        for (int v = i + 2; v < len; v++)
                        {
                            tmp += '0';
                            if(v != len - 1)
                                ans++;
                            else if (check(tmp))
                                ans++;
                        }
                    }
                    for (int u = i + 1; u < len - 1; u++)
                    {
                        str += '0';
                        string tmp = str;
                        for (int v = 1; v < 10; v++)
                        {
                            string tp = tmp;
                            tp += v + '0';
                            if(u != len - 2)
                                ans++;
                            else if (check(tp))
                                ans++;
                            for (int v = u + 2; v < len; v++)
                            {
                                tp += '0';
                                if(v != len - 1)
                                    ans++;
                                else if (check(tp))
                                    ans++;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
