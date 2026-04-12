#include <bits/stdc++.h>
using namespace std;

int n, m;
char c[10][10];
bool bio[10][10];

void dfs(int x, int y){
    bio[x][y] = true;

    if(x < n && c[x + 1][y] == '#'){
        dfs(x + 1, y);
        return;
    }

    if(y < m && c[x][y + 1] == '#'){
        dfs(x, y + 1);
        return;
    }
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c[i][j];
        }
    }

    dfs(1, 1);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(c[i][j] == '#' && !bio[i][j]){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    cout << "Possible" << endl;

    return 0;
}
