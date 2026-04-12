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

int N, M;
int matrix[16][16];

int main(){
    std::cin >> N >> M;

    REP(i, N){
        REP(j, N){
            std::cin >> matrix[i][j];
        }
    }

    REP(i, M){
        int o;
        std::cin >> o;

        if(o == 0){
            int r, c, size, angle;
            std::cin >> r >> c >> size >> angle;
            --r; --c;
            angle /= 90;
            REP(_, angle){
                int _matrix[15][15];
                REP(i, size){
                    REP(j, size){
                        _matrix[j][size-i-1] = matrix[r+i][c+j];
                    }
                }

                REP(i, size){
                    REP(j, size){
                        matrix[r+i][c+j] = _matrix[i][j];
                    }
                }
            }
        }else if(o == 1){
            int r, c, size;
            std::cin >> r >> c >> size;
            --r; --c;
            REP(i, size){
                REP(j, size){
                    matrix[r+i][c+j] = !matrix[r+i][c+j];
                }
            }
        }else if(o == 2){
            int r;
            std::cin >> r;
            --r;

            int m_first = matrix[r][0];
            FOR(i, 0, N-1){
                matrix[r][i] = matrix[r][i+1];
            }
            matrix[r][N-1] = m_first;
        }else if(o == 3){
            int r;
            std::cin >> r;
            --r;

            int m_last = matrix[r][N-1];
            for(int i=N-1;i>0;i--){
                matrix[r][i] = matrix[r][i-1];
            }
            matrix[r][0] = m_last;
        }else if(o == 4){
            int r, c;
            std::cin >> r >> c;
            --r; --c;

            int prev_m = matrix[r][c];
            std::queue<P> q;
            q.push(mp(r, c));

            while(!q.empty()){
                P p = q.front(); q.pop();
                
                if(matrix[p.first][p.second] != prev_m){continue;}
                matrix[p.first][p.second] = !prev_m;

                REP(i, 4){
                    int nr = p.first + dx[i], nc = p.second + dy[i];
                    if(0 <= nr && nr < N && 0 <= nc && nc < N && matrix[nr][nc] == prev_m){
                        q.push(mp(nr, nc));
                    }
                }
            }
        }
    }

    REP(i, N){
        REP(j, N){
            if(j == 0){printf("%d", matrix[i][j]);}
            else{printf(" %d", matrix[i][j]);}
        }
        puts("");
    }
}