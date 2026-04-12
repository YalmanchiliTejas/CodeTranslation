#include<bits/stdc++.h>
using namespace std;
vector<int> v(10, 1);
int n, m, a, b, path[10][10], cnt=0;

void solve(int i){
    if(i==n-1){
        ++cnt;
        return;
    }
    if(path[v[i]][v[i+1]]!=-1){
        solve(i+1);
    }
}

int main(void){
    for(int i=0;i<10;++i)v[i] = i+1;
    for(int i=0;i<10;++i) for(int j=0;j<10;++j) path[i][j] = -1;
    cin >> n >> m;
    for(int i=0;i<m;++i){
        cin >> a >> b;
        path[a][b] = 1;
        path[b][a] = 1;
    }
    do{
        if(v[0]!=1) break;
        solve(0);
    }while(next_permutation(v.begin(), v.begin()+n));
    cout << cnt << endl;
}