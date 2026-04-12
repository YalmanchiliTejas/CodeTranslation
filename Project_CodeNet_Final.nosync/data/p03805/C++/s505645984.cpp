#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool e[8][8]={false};

int dfs(int v,int N,bool vv[8]){
    bool all = true;
    for(int i=0;i<N;i++){
        if(!vv[i]) all=false;
    }
    if(all) return 1;
    int ret=0;
    for(int i=0;i<N;i++){
        //今見ている頂点とつながっていれば探索
        if(e[v][i]==false) continue;
        //すでに訪れていたら探索しない
        if(vv[i]) continue;
        //探す
        vv[i]=true;
        ret+=dfs(i,N,vv);
        vv[i]=false;
    }
    return ret;
}

int main(){
    int  N,M;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        e[a-1][b-1]=true;
        e[b-1][a-1]=true;
    }
    bool vv[8];
    for(int i=0;i<N;i++) vv[i] = false;
    vv[0]=true;
    cout << dfs(0,N,vv) << endl;
    
    return 0;
}
