#include <iostream>
using namespace std;
int count = 0;
int n,m;
int connect[20][20];
void dfs(int x, int k, int use[]){
    if(x==0) count++;
    for(int i = 0; i < n; i++){
        if(!use[i] & connect[k][i] == 1) {
      //      cout << i;
            use[i] = 1;
            dfs(x - 1, i, use);
            use[i] = 0;
        }
    }
    //cout << "\n";
}


int main(void){
    cin >> n >> m;
    int use[n];
    
    for(int i = 0; i < n; i++){
        use[i] = 0;
        for(int j = 0; j < n; j++){
            connect[i][j] = 0;
        }
    }
    use[0] = 1;
    for(int i = 0; i < n; i++)connect[n][i] = 1;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        connect[a-1][b-1] = 1;
        connect[b-1][a-1] = 1;
    }
    dfs(n-1, 0, use);
    cout << count << "\n";
    return 0;
}
