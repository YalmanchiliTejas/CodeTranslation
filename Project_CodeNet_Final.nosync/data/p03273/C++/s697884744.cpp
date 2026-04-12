#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i <(n); i++)
using namespace std;
using ll = long long;

int cnt_i[200], cnt_j[200];
int main()
{
    int h, w;
    cin >> h >> w;
    char mass[h][w];
    rep(i, h)
    rep(j, w)
    {
        cin >> mass[i][j];
        if (mass[i][j] == '#')
        {
            cnt_i[i]++;
            cnt_j[j]++;
        }
    }

    rep(i, h)
    {
        if (cnt_i[i] == 0) continue;

        rep(j, w)
        {
            if (cnt_j[j] == 0) continue;
            cout << mass[i][j];
        }
        cout << endl;
    }
    
    return 0;
}