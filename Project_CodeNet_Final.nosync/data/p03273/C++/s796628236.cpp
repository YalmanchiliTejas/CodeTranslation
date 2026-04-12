#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
bool chmax(t &a, u b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> vs;
    vector<int> a;
    vector<int> b;
    rep(i, h)
    {
        string s;
        cin >> s;
        vs.push_back(s);
    }
    rep(i, h)
    {
        rep(j, w)
        {
            if (vs[i][j] == '#')
            {
                a.push_back(i);
                break;
            }
        }
    }
    rep(j, w)
    {
        rep(i, h)
        {
            if (vs[i][j] == '#')
            {
                b.push_back(j);
                break;
            }
        }
    }
    rep(i, a.size())
    {
        rep(j, b.size())
        {
            cout << vs[a[i]][b[j]];
        }
        cout << endl;
    }

    return 0;
}