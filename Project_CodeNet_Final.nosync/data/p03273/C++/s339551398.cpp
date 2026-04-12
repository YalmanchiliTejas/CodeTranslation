#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> d(h, vector<char>(w));
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> d[i][j];
        }
    }
    set<int> l;
    set<int> r;
    
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(d[i][j] == '#')
            {
                l.insert(i);
                r.insert(j);
            }
        }
    }
    for(int i = 0; i < h; i++)
    {
        if(l.find(i) != l.end())
        {
            for(int j = 0; j < w; j++)
            {
                if(r.find(j) != r.end())
                {
                    cout << d[i][j];
                }
            }
            cout << endl;
        }
    }
}
