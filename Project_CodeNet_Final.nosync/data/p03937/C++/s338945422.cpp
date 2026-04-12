#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int h, w;
    cin >> h >> w;
    vector<set<int>> vs(h);
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            char c;
            cin >> c;
            if(c == '#') vs[i].insert(j);
        }
    }
    int r = 0;
    for(int i = 0; i < h; i++)
    {
        int l = *vs[i].begin();
        if(l != r)
        {
            cout << "Impossible" << endl;
            return 0;
        }
        r = *vs[i].rbegin();
    }
    cout << "Possible" << endl;
}


