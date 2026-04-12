#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int MAX_N = 51;
const int MAX_WH = 2 * 1e6;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int W, H, n;
int X1[MAX_N], X2[MAX_N], Y1[MAX_N], Y2[MAX_N];

// 塗りつぶし用
bool fld[MAX_N * 6][MAX_N * 6];

// x1, x2を座標圧縮し，座標圧縮した際の幅を返す
int compress(int *x1, int *x2, int w)
{
    vector<int> xs;

    xs.push_back(-1);
    xs.push_back(w + 1);
    for (int i = 0; i < n; i++) {
        for (int d = -1; d <= 1; d++) {
            int tx1 = x1[i] + d;
            int tx2 = x2[i] + d;

            if (0 <= tx1 && tx1 <= w)
                xs.push_back(tx1);
            if (0 <= tx2 && tx2 <= w)
                xs.push_back(tx2);
        }
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    for (int i = 0; i < n; i++) {
        x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
        x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }

    return xs.size();
}

void solve()
{
    // 座標圧縮
    W = compress(X1, X2, W);
    H = compress(Y1, Y2, H);

    // 四角形で塗りつぶし
    memset(fld, 0, sizeof(fld));
    for (int i = 0; i < n; i++) {
        for (int x = X1[i]; x <= X2[i]; x++)
            fld[Y1[i]][x] = fld[Y2[i]][x] = true;

        for (int y = Y2[i]; y <= Y1[i]; y++)
            fld[y][X1[i]] = fld[y][X2[i]] = true;
    }

    // 領域を数える
    int ans = 0;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (fld[y][x])
                continue;
            ans++;

            // 幅優先探索
            queue<pair<int, int> > que;
            que.push(make_pair(x, y));

            while (!que.empty()) {
                int sx = que.front().first;
                int sy = que.front().second;
                que.pop();

                for (int i = 0; i < 4; i++) {
                    int tx = sx + dx[i];
                    int ty = sy + dy[i];

                    if (tx < 0 || W <= tx || ty < 0 || H <= ty)
                        continue;
                    if (fld[ty][tx])
                        continue;
                    que.push(make_pair(tx, ty));
                    fld[ty][tx] = true;
                }
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];

            /*
              11   111　左のような矩形を右のように変形するために座標を2倍
              11   101
                   111
             */
            X1[i] *= 2;
            X2[i] *= 2;
            Y1[i] *= 2;
            Y2[i] *= 2;
        }

        W = H = MAX_WH;
        solve();
    }

    return 0;
}