#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long LL;
typedef unsigned long UL;

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    vector<string> in(h);

    REP(i, h)
    {
        in[i].resize(w);
        cin >> in[i];
    }

    in.erase(remove_if(in.begin(), in.end(), [=](string str) {bool ans = true; REP(i, w) if (str[i] != '.') ans = false; return ans; }), in.end());

    bool eraseable;
    vector<int> erase(0);
    for (int i = 0; i < in[0].size(); ++i)
    {
        eraseable = true;
        for (int j = 0; j < in.size(); ++j)
        {
            if (in[j][i] != '.') eraseable = false;
        }

        if (eraseable) erase.emplace_back(i);
    }

    for (auto& v : erase)
    {
        for (auto& x : in)
        {
            x.erase(x.begin() + v);
        }
        for (auto& y : erase) y -= 1;
    }

    for (const auto& v : in)
    {
        cout << v << endl;
    }

    cout << endl;

    return 0;
}