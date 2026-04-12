#include <bits/stdc++.h>
#include <numeric>
#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define SORT_INV(c) sort((c).begin(), (c).end(), greater<int>())

#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false
#define LL long long
#define Dev 1000000007

// sort(a.begin(), a.end(), std::greater<int>());
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    string s[h];
    rep(i, h)
    {
        cin >> s[i];
    }
    set<int> height;
    set<int> width;
    rep(i, h)
    {
        bool flag = false;
        if (s[i][0] == '.')
        {
            rep(j, w)
            {
                if (s[i][j] == '#')
                    goto LOOPOUT;
            }
            height.insert(i);
        }
    LOOPOUT:;
    }
    rep(j, w)
    {
        bool flag = false;
        if (s[0][j] == '.')
        {
            rep(i, h)
            {
                if (s[i][j] == '#')
                    goto LOOPAUTO;
            }
            width.insert(j);
        }
    LOOPAUTO:;
    }
    rep(i, h)
    {
        if (height.count(i))
            continue;
        rep(j, w)
        {
            if (width.count(j))
                continue;
            else
            {
                cout << s[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}