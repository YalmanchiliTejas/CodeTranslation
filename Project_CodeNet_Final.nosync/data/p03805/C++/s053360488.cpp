#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;
using namespace std;
typedef pair<int,int> P;
vector<int>G[9];
int n,m;
int cnt=0;
bool visit[9]={};
void dfs(int s){
    visit[s]=true;
    for(int i=0;i<G[s].size();i++){
        if(visit[G[s][i]]==false){
            dfs(G[s][i]);
            visit[G[s][i]]=false;
        }
    }
    bool all=true;
    for(int i=1;i<=n;i++){
        if(visit[i]==false)all=false;
    }
    if(all)cnt++;
}
int main(void){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1);
    cout<<cnt<<endl;
    return 0;
}
