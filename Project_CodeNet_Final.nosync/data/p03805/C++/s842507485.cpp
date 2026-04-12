#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
int n,m;
vector<vector<int>> nei;
int ans=0;
int dfs(int ii,int size,vector<int> dist,int last){
    if(ii==size){
        return 1;
    }
    int ret=0;
    for(int i=0;i<nei[last].size();i++){
        if(dist[nei[last][i]]!=-1){
            continue;
        }
        dist[nei[last][i]]=dist[last]+1;
        ret+=dfs(ii+1,size,dist,nei[last][i]);
        dist[nei[last][i]]=-1;
    }
    return ret;
}

int main(){    
    cin>>n>>m;
    nei.resize(n);
    vector<int> dist(n,-1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }
    dist[0]=0;    
    cout<<dfs(1,n,dist,0)<<endl;
    return 0;
}