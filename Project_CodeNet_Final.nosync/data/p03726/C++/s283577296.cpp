#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 200000;
vector <int> bi[N];
int ok;
int dfs(int t, int f = 0)
{
    int c = 0;
    for (int i = 0; i < bi[t].size(); ++ i)
        if (bi[t][i] != f)
        {
            int w = dfs(bi[t][i], t);
            if (w == 0) c ++;
        }
    if (c <= 1) return c;
    else ok = 1;
    return -1;
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; ++ i)
    {
        int a, b;
        cin >> a >> b;
        bi[a].push_back(b);
        bi[b].push_back(a);
    }
    ok = 0;
    if (dfs(1) == 0) ok = 1;
    if (ok) cout << "First" << endl;
    else cout << "Second" << endl;
}
