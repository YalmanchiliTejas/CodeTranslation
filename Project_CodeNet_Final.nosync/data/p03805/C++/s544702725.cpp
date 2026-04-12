#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> v[10];
bool used[10];
int ans;
int N,M;

void dfs (int x, int cnt) {
    if( used[x] ) return;
    used[x] = true;
    int l = v[x].size();
    for(int i=0; i<l; i++) {
        dfs(v[x][i], cnt+1);
    }
    used[x] = false;
    if( N-1 == cnt ) ans++;
    return ;
}

int main (){
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0);
    cout << ans << endl;
    return 0;
}
