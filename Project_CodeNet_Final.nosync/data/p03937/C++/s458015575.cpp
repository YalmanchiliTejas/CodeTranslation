#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
 
const int INF = 1 << 30;
const int INF_NEG = INF * -1;

struct sPoint{
    int x, y, breadth;
};

int H, W;
vector<string> A;
int breadth[20][20];

// #define GBN_DEBUG

int bfs(int startX, int startY)
{
    sPoint start = {startX, startY, 0};
    queue<sPoint> qPoint;
    qPoint.push(start);
    
    while(!qPoint.empty()){
        sPoint c = qPoint.front(); // current point
        qPoint.pop();

    
        if (c.x == W - 1 && c.y == H - 1) // ゴールなら
            return c.breadth; // 現在地の幅を返す
        
        if (c.y + 1 < H && A[c.y + 1][c.x] == '#'){ // 下を探索
            A[c.y + 1][c.x] = 'x';
            breadth[c.y + 1][c.x] = c.breadth + 1;
            sPoint next = {c.x, c.y + 1, c.breadth + 1};
            qPoint.push(next);
        }
        if (c.x + 1 < W && A[c.y][c.x + 1] == '#'){ // 右を探索
            A[c.y][c.x + 1] = 'x';
            breadth[c.y][c.x + 1] = c.breadth + 1;
            sPoint next = {c.x + 1, c.y, c.breadth + 1};
            qPoint.push(next);
        }
    }

    return 0;
}

int main()
{
    cin >> H >> W;
    A.resize(H + 9);
    rep(i, 20) rep(j, 20) breadth[i][j] = -1;
    rep(i, H) cin >> A[i];
    int ret = bfs(0, 0);

    if (!ret){ // ゴールに到達できなかった場合
        puts("Impossible"); return 0;
    }

#ifdef GBN_DEBUG
    cout << ret << endl << endl;
    if (ret){
        rep(i, H) cout << A[i] << endl;
    }
#endif

    // bfs() で通れた場所に 'x' 印
    // 以下で最短経路の道を 'o' に変更
    int x = W - 1, y = H - 1;
    int b = ret;
    while(b >= 0){
        A[y][x] = 'o';
        if (breadth[y - 1][x] == b - 1) --y; // 上か左のどちらかに幅が１つ小さい場所があるはず
        else --x;
        --b;

        if (y < 0) y = 0;
        if (x < 0) x = 0;
    }
    A[0][0] = 'o';
#ifdef GBN_DEBUG
    rep(i, H) cout << A[i] << endl;
#endif

    bool ans = true;
    rep(y, H){
        if (!ans) break;
        rep (x, W){
            if (A[y][x] == 'x' || A[y][x] == '#'){
                ans = false;
                break;
            }
        }
    }

    if (ans) puts("Possible");
    else puts("Impossible");
    return 0;
}
