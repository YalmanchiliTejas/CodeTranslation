#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;
//for (int i = 0; i < N; i++){}

long long N, M;
bool vis[8];
int graph[8][8];
int cnt = 0;
int res = 0;

int dfs(int x){
    if(vis[x] == true) return 0;
    cnt++;
    if(cnt == N){
        res++;
        cnt--;
        return 0;
    }

    vis[x] = true;

    for(int i=0;i<N;i++){
        if(graph[x][i] == 1){
            dfs(i);
        }
    }
    vis[x] = false;
    cnt--;
}

int main() {
	cin >> N >> M;

    int a[M], b[M];
    int x, y;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++){
        cin >> x >> y;
        graph[x-1][y-1] = 1;
        graph[y-1][x-1] = 1;
    }
    dfs(0);
    cout << res << endl;
}