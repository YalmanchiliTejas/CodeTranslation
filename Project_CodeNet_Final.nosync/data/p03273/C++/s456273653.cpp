#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)




int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    char a[h][w];
    rep(i, h) rep(j, w) cin >> a[i][j];

    rep(i, h) rep(j, w){
        if(a[i][j]=='#')
            break;
        if(j+1==w)
            rep(k, w) a[i][k] = 'x';
    }
    rep(i, w) rep(j, h)
    {
        if (a[j][i] == '#')
            break;
        if (j + 1 == h)
            rep(k, h) a[k][i] = 'x';
    }
    bool q = false;
    rep(i,h){
        rep(j, w) 
            if (a[i][j] != 'x') {
                cout << a[i][j];
                q = true;
            }
        if(q)cout << endl;
        q = false;
    }
        return 0;
}