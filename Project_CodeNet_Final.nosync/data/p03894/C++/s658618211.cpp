// ※※※ 解答不能 ※※※
// tourist氏.
// https://atcoder.jp/contests/cf16-relay-open/submissions/8966086
#include <bits/stdc++.h>
using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){
    int n, tt;
    scanf("%d %d", &n, &tt);
    vector<vector<int>> can(n, vector<int>(2, 0));
    can[0][0] = 1;
    can[1][1] = 1;
    while(tt--){
        int x, y;
        scanf("%d %d", &x, &y);
        --x; --y;
        swap(can[x], can[y]);
        for(int z : {x, y, x - 1, x + 1, y - 1, y + 1}){
            if(z >= 0 && z < n && can[z][0]){
                if(z - 1 >= 0) can[z - 1][1] = 1;
                if(z + 1 < n) can[z + 1][1] = 1;
            }
        }
    }
    int ans = 0;
    rep(i, n) ans += can[i][0] | can[i][1];
    printf("%d\n", ans);
    return 0;
}