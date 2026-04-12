#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<string.h>
#include<queue>
#include<math.h>
#include<set>
#include<unordered_set>
#include<limits.h>
using namespace std;

typedef unsigned long long ll;

vector<vector<int> >vec;
vector<bool>visited;
ll ans=0;
void dfs(int a){
    visited[a]=true;
    bool ok=1;
    for(int i=0;i<visited.size();i++){
        if(visited[i]==false){
            ok=0;
        }
    }
    if(ok){
        ans++;
    }
    for(int i=0;i<vec[a].size();i++){
        if(!visited[vec[a][i]]){
            dfs(vec[a][i]);
        }
    }
    visited[a]=false;
}



int main(){
    int n,m;
    cin>>n>>m;
    vec.resize(n);
    visited.resize(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}
