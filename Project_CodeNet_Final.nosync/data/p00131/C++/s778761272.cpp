#include <iostream>
#include <cstdio>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,j) FOR(i,0,j)

const int INF = 1001001001;

int N;
int map[12][12];
bool used[12][12];

int reverse(int x, int y){
    map[y][x] = !map[y][x];
    map[y][x-1] = !map[y][x-1];
    map[y-1][x] = !map[y-1][x];
    map[y][x+1] = !map[y][x+1];
    map[y+1][x] = !map[y+1][x];
}

int main(){
    scanf("%d", &N);

    REP(_, N){
        FOR(i, 1, 11){
            FOR(j, 1, 11){
                scanf("%d", &map[i][j]);
            }
        }

        REP(state, 1<<10){
            memset(used, 0, sizeof(used));

            FOR(i, 1, 11){
                if(state >> (i-1) & 1){
                    used[1][i] = true;
                    reverse(i, 1);
                }
            }

            FOR(i, 2, 11){
                FOR(j, 1, 11){
                    if(map[i-1][j] == 1){
                        used[i][j] = true;
                        reverse(j, i);
                    }
                }
            }

            bool f = false;
            FOR(i, 1, 11){
                f |= map[10][i];
            }

            if(f){
                FOR(i, 1, 11){
                    FOR(j, 1, 11){
                        if(used[i][j]){reverse(j, i);}
                    }
                }
                continue;
            }

            FOR(i, 1, 11){
                FOR(j, 1, 11){
                    printf("%d", used[i][j]);
                    if(j < 10){putchar(' ');}
                    else{puts("");}
                }
            } 
        }
    }
}