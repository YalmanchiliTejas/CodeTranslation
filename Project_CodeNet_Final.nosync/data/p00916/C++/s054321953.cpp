#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,j) FOR(i,0,j)
#define mp std::make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> P;
typedef std::pair<int,P> State;

const int INF = 1001001001;

// S N E W(南北東西)
const int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

std::vector<int> X1, X2, Y1, Y2;
ll map[500][500];
int W, H;

int compress(std::vector<int> &v1, std::vector<int> &v2){
    std::vector<int> v;

    REP(i, (int)v1.size()){
        FOR(j, -1, 2){
            int s = v1[i] + j, t = v2[i] + j;
            // if(0 <= s && s <= 1000000){
                v.push_back(s);
            // }
            // if(0 <= t && t <= 1000000){
                v.push_back(t);
            //}
        }
    }

    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    REP(i, (int)v1.size()){
        v1[i] = std::find(v.begin(), v.end(), v1[i]) - v.begin();
        v2[i] = std::find(v.begin(), v.end(), v2[i]) - v.begin();
    }

    return (int)v.size();
}

void dfs(int x, int y, ll v){
    map[y][x] = -1;

    REP(i, 4){
        int nx = x + dx[i], ny = y + dy[i];
        if(0 <= nx && nx < W && 0 <= ny && ny < H &&
           map[ny][nx] == v){
            dfs(nx, ny, v);
        }
    }
}

int main(){
    int N;
    while(std::cin >> N, N){
        X1.clear(); X2.clear(); Y1.clear(); Y2.clear();

        REP(i, N){
            int l, t, r, b;
            std::cin >> l >> t >> r >> b;

            X1.push_back(l);
            X2.push_back(r);
            Y1.push_back(b);
            Y2.push_back(t);
        }

        W = compress(X1, X2);
        H = compress(Y1, Y2);

        std::fill(map[0], map[0]+500*500, 0LL);
        REP(i, N){
            FOR(y, Y1[i], Y2[i]){
                FOR(x, X1[i], X2[i]){
                    map[y][x] += 1LL << i;
                }
            }
        }

        // REP(y, H){
        //     REP(x, W){
        //         printf("%3lld ", map[y][x]);
        //     }
        //     puts("");
        // }

        int t = 0;
        FOR(y, 0, H){
            FOR(x, 0, W){
                if(map[y][x] >= 0){
                    dfs(x, y, map[y][x]);
                    t += 1;
                }
            }
        }
    
        std::cout << t << std::endl;
    }
}