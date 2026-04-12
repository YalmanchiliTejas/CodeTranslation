#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> gr(n);
    for(int i = 0; i < n; i++)
    cin >> gr[i];
    vector<vector<char>> grid(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            grid[i].emplace_back(gr[i][j]);
        }
    }
    set<int> k,l;
    for(int i = 0; i < n; i++){
        bool white = 1;
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '#')
            white = 0;
        }
        if(white)
        k.insert(i);
    }
    for(int i = 0; i < m; i++){
        bool white = 1;
        for(int j = 0; j < n; j++){
            if(grid[j][i] == '#')
            white = 0;
        }
        if(white)
        l.insert(i);
    }
    for(int i = 0; i < n; i++){
        int cnt =0;
        for(int j = 0; j < m; j++){
            if(!l.count(j) && !k.count(i)){
            cout << grid[i][j];
            cnt++;
            }
        }
        if(cnt)
        cout << endl;
    }
}