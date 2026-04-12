#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int h, w;
    cin >> h >> w;
    int cnt = 0;
    vector<vector<char>> d(h, vector<char>(w));
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> d[i][j];
            if(d[i][j] == '#') cnt++;
        }
    }

    int x = 0, y = 0;
    int ans = d[x][y] == '#';
    while(true)
    {
        bool flag = false;
        if(x < h-1 && d[x+1][y] == '#')
        {
            flag = true;
            x++;
            ans++;
        }
        else if(y < w-1 && d[x][y+1] == '#')
        {
            flag = true;
            y++;
            ans++;
        }
        if(!flag) break;
    }
    if(ans == cnt) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}
