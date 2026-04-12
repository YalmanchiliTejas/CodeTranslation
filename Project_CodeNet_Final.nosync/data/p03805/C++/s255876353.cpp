#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int a[8][8];

int main(void)
{
    int n, m;
    cin >> n >> m;
    
    rep(i, m){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        a[x][y] = 1;
        a[y][x] = 1;
    }

    vector<int> p(n);
    rep(i, n) p.at(i) = i + 1;

    int ans = 0;

    do{
        bool flag = true;
        if(p[0] != 1) continue;
        rep(i, n - 1)
        {
            if(a[p[i] - 1][p[i+1] - 1] == 0)
            {
                flag = false;
            }
        }
        if(flag) ans++;
    }while(next_permutation(p.begin(), p.end()));

    cout << ans << endl;
    return 0;
}