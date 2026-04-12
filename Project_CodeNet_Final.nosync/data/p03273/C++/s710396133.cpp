#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

int a[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    vector<string> g;
    for (int i = 0; i < h; ++i)
    {
        string s;
        cin >> s;
        bool b = false;
        for (char c : s)
            if (c == '#')
                b = true;
        if (b)
            g.push_back(s);
    }
    h = g.size();
    for (int i = 0; i < w; ++i)
        for (int j = 0; j < h; ++j)
            if (g[j][i] == '#')
                a[i] = 1;

    for (int j = 0; j < h; ++j)
    {
        for (int i = 0; i < w; ++i)
        {
            if (a[i])
                cout << g[j][i];
        }
        cout << '\n';

    }
}
