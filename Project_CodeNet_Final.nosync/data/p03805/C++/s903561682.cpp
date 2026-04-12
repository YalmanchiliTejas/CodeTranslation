#include<bits/stdc++.h>
using namespace std;
int n,m;
void dfs(int i, vector<bool> &checked, bool c[10][10], int &ans){
    int t = 0;
    for (int j = 0; j < n; j++)
    {
        if(checked[j]) t++;
    }
    if(t == n) ans ++;
    else{
        for (int j; j < n; j++)
        {
            if(c[i][j] == true && !checked[j]){
                checked[j] = true;
                dfs(j,checked,c,ans);
                checked[j] = false;
            }
        }
        
    }
    
}

int main(){
    cin>> n >> m;
    vector<bool> checked(n,false);
    bool c[10][10] = {false};
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;
        c[x][y] = true;
        c[y][x] = true;
    }
    checked[0] = true;
    int ans = 0;
    dfs(0,checked,c,ans);

    cout << ans << endl;
}