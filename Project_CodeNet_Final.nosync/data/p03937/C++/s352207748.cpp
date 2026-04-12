#include <bits/stdc++.h>
using namespace std;

int h, w;
string s[8];
int cnt;
int main()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == '#')
            {
                cnt++;
            }
        }
    }
    if (cnt == h + w - 1)
    {
        cout << "Possible" << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }
}