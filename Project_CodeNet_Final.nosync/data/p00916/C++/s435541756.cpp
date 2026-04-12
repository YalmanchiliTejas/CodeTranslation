#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

bool in_range(int x, int W){
    return x >= 0 && x < W;
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
    int N;
    while(cin >> N && N){
        vector<int> l(N), t(N), r(N), b(N);
        set<int> s;
        REP(i, N){
            cin >> l[i] >> t[i] >> r[i] >> b[i];
            for(int d = -1; d <= 1; d++){
                s.insert(l[i] * 2 + d);
                s.insert(t[i] * 2 + d);
                s.insert(r[i] * 2 + d);
                s.insert(b[i] * 2 + d);
            }
        }
        map<int, int> index;
        for(int si : s){
            int t = index.size();
            index[si] = t;
        }
        bool used[50 * 15][50 * 15] = {};
        REP(i, N) {
            int lx = index[2 * l[i]], rx = index[2 * r[i]];
            int ly = index[2 * b[i]], ry = index[2 * t[i]];
            //printf("[%d, %d] x [%d, %d]\n", lx, rx, ly, ry);
            for(int y = ly; y <= ry; y++){
                used[y][lx] = used[y][rx] = true;
            }
            for(int x = lx; x <= rx; x++){
                used[ly][x] = used[ry][x] = true;
            }
        }
        /*
        REP(y, index.size()) {
            REP(x, index.size()) cout << used[y][x];
            cout << endl;
        }
        */
        int answer = 0;
        for(int sy = 0; sy < index.size(); sy++){
            for(int sx = 0; sx < index.size(); sx++){
                if(!used[sy][sx]){
                    answer++;
                    queue<int> qx, qy;
                    qx.push(sx); qy.push(sy);
                    used[sy][sx] = true;
                    while(!qx.empty()){
                        int x = qx.front(), y = qy.front();
                        qx.pop(); qy.pop();
                        REP(r, 4){
                            int nx = x + dx[r], ny = y + dy[r];
                            if(in_range(nx, index.size()) && in_range(ny, index.size()) && !used[ny][nx]){
                                used[ny][nx] = true;
                                qx.push(nx); qy.push(ny);
                            }
                        }
                    }
                }
            }
        }
        cout << answer << endl;
    }
    return 0;
}