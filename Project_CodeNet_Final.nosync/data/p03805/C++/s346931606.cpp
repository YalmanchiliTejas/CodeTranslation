#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<bool> d(8,false);
int dfs(int n,int a,vector<vector<int>> A,int K){
    if(n==K) return 1;
    d[a]=true;
    int ret=0;
    for(int i=0;i<A[a].size();i++){
        int v=A[a][i];
        if(!d[v]) ret+= dfs(n+1,v,A,K);
    }
    d[a]=false;
    return ret;
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> to(N);
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    cout << dfs(1,0,to,N);
}