#include<iostream>
using namespace std;

bool path[9][9] = {};
int n, m;

int solve(int before, bool visit[]){
    bool judge = true;
    for(int i = 1; i <= n; i++){
        if(!visit[i])   judge = false;
    }

    if(judge){
        return 1;
    }

    int ret = 0;

    for(int j = 1; j <= n; j++){
        if(path[before][j] && !visit[j]){
            visit[j] = true;
            ret += solve(j, visit);
            visit[j] = false;
        }
    }

    return ret;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        path[a][b] = path[b][a] = true;
    }

    bool visit[9];
    for(int i = 1; i <= n; i++)  visit[i] = false;
    visit[1] = true;
    
    cout << solve(1, visit) << endl;
    return 0;
}