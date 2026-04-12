#include <iostream>
#include <vector>
#define rep(v,n) for(int v=0;v<n;v++)
using namespace std;
int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> map(H);
    vector<bool> h(H), w(W);
    rep(i, H) cin >> map[i];
    rep(y, H) {
        bool wall = false;
        rep(x, W) 
            if (map[y][x] == '#')
                wall = true;
        h[y] = wall;
    }
    rep(x, W) {
        bool wall = false;
        rep(y, H)
            if (map[y][x] == '#')
                wall = true;
        w[x] = wall;
    }
    rep(y, H) {
        if (!h[y]) continue;
        rep(x, W) if (w[x]) cout << map[y][x];
        cout << endl;
    }
    return 0;
}
