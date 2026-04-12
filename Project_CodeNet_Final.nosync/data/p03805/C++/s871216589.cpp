#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans;
vector<int> vec[9];
void dfs(int now,int bit){
    if(bit==((1<<(n+1))-1)){
        ans++;
    }
    for(int i=0;i<vec[now].size();i++){
        if(!(bit&(1<<vec[now][i]))){
            dfs(vec[now][i],bit|(1<<vec[now][i]));
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    vec[0].push_back(1);
    dfs(0,1);
    cout<<ans<<endl;
    return 0;
}