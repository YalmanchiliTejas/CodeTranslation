#include <bits/stdc++.h>
using namespace std;

pair<bool, string> f(string s, char first, char second)
{
    int n = s.size();
    string ret(n, '0');
    ret[0] = first;
    ret[1] = second;
    for (int i = 1; i <= n; i++)
    {
        int current = i % n;
        int prev = (n + i - 1) % n;
        int next = (n + i + 1) % n;
        if ((ret[current] == 'S' && s[current] == 'o') || (ret[current] == 'W' && s[current] == 'x'))
        {
            if (ret[next] == '0')
            {
                ret[next] = ret[prev];
            }
            else
            {
                if (ret[next] != ret[prev])
                {
                    return make_pair(false, ret);
                }
            }
        }
        else
        {
            if (ret[next] == '0')
            {
                if (ret[prev] == 'S')
                {
                    ret[next] = 'W';
                }
                if (ret[prev] == 'W')
                {
                    ret[next] = 'S';
                }
            }
            else
            {
                if (ret[next] == ret[prev])
                {
                    return make_pair(false, ret);
                }
            }
        }
    }
    return make_pair(true, ret);
}

int main()
{
    int N;
    string s;
    cin >> N >> s;

    pair<bool, string> ret;
    ret = f(s, 'S', 'S');
    if (ret.first)
    {
        cout << ret.second << endl;
        return 0;
    }

    ret = f(s, 'S', 'W');
    if (ret.first)
    {
        cout << ret.second << endl;
        return 0;
    }

    ret = f(s, 'W', 'S');
    if (ret.first)
    {
        cout << ret.second << endl;
        return 0;
    }

    ret = f(s, 'W', 'W');
    if (ret.first)
    {
        cout << ret.second << endl;
        return 0;
    }

    cout << -1 << endl;
}
