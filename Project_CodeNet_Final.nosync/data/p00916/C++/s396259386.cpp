#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using P = pair<int, int>;

int main() {
    int n;
    while(cin >> n, n) {
        vector<int> xs, ys;
        vector<int> x1(4*n), x2(4*n), y1(4*n), y2(4*n);
        for(int i=0; i<n; ++i) {
            int l, t, r, b;
            cin >> l >> t >> r >> b;
            l *= 2; t *= 2; r *= 2; b *= 2;
            x1[i*4] = l, x2[i*4] = r, y1[i*4] = t, y2[i*4] = t;
            x1[i*4+1] = l, x2[i*4+1] = l, y1[i*4+1] = b, y2[i*4+1] = t;
            x1[i*4+2] = r, x2[i*4+2] = r, y1[i*4+2] = b, y2[i*4+2] = t;
            x1[i*4+3] = l, x2[i*4+3] = r, y1[i*4+3] = b, y2[i*4+3] = b;
            for(int j=-1; j<=1; ++j) {
                xs.push_back(l+j);
                xs.push_back(r+j);
                ys.push_back(t+j);
                ys.push_back(b+j);
            }
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        for(int i=0; i<4*n; ++i) {
            x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
            x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
            y1[i] = find(ys.begin(), ys.end(), y1[i]) - ys.begin();
            y2[i] = find(ys.begin(), ys.end(), y2[i]) - ys.begin();
        }
        int res = 0;
        vector<vector<bool>> fld(ys.size(), vector<bool>(xs.size(), false));
        for(int i=0; i<4*n; ++i) {
            for(int y=y1[i]; y<=y2[i]; ++y) {
                for(int x=x1[i]; x<=x2[i]; ++x) {
                    fld[y][x] = true;
                }
            }
        }
        for(int i=0; i<ys.size(); ++i) {
            for(int j=0; j<xs.size(); ++j) {
                if(fld[i][j]) {
                    continue;
                }
                fld[i][j] = true;
                res++;
                queue<P> que;
                que.push(make_pair(i, j));
                while(!que.empty()) {
                    P p = que.front(); que.pop();
                    int sy = p.first, sx = p.second;
                    int dy[4] = {0, -1, 0, 1},
                        dx[4] = {1, 0, -1, 0};
                    for(int k=0; k<4; ++k) {
                        int ty = sy + dy[k], tx = sx + dx[k];
                        if(ty < 0 || ys.size() <= ty || tx < 0 || xs.size() <= tx) {
                            continue;
                        }
                        if(fld[ty][tx]) {
                            continue;
                        }
                        que.push(make_pair(ty, tx));
                        fld[ty][tx] = true;
                    }
                }
            }
        }
        cout << res << endl;
    }
}
