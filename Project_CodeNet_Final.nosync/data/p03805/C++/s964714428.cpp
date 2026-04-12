#include<iostream>
#include<string>

using namespace std;

int n,m,t = 1;
int g[10][10] = {};

int dfs(int node,int run){
    int ans = 0;
    //cout << node << " " << run << endl;

    for(int i = 1; i<= n;i++){
        if(g[node][i] == 1 && ((run & (1<<(i-1))) == 0)){
            ans += dfs(i,run | (1<<(i-1)));
        }
    }

    if(run == t)return ans + 1;
    else return ans;
}
int main(){
    
    cin >> n >> m;

    t = (t << n)-1;
    for(int i = 0;i < m;i++){
         int a,b;
         cin >> a >> b;
         g[a][b] = 1;
         g[b][a] = 1;
    }
    

    cout << dfs(1,0x01) <<endl;

    return 0;
}