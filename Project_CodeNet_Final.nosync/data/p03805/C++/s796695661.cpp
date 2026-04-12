#include<bits/stdc++.h>
using namespace std;
#define SORT(x) sort(x.begin(),x.end())
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
vector<vector<int>> v(50);
int n,m;
int ans=0;
vector<bool> pass(10,false);
void dfs(int k){
    bool flag=true;
    pass[k]=true;
    rep(i,n){
        if(!pass[i]){
            flag=false;break;
        }
    }
    if(flag){
        ans++;pass[k]=false;return ;
    }
    else{
        rep(i,v[k].size()){
            if(!pass[v[k][i]]){
                dfs(v[k][i]);
            }
        }
    }
    pass[k]=false;
    //dfsから戻るときに通った記憶をリセットしてく
}

int main(){
    cin>>n>>m;
    rep(i,m){
        int a,b;
        cin>>a>>b;a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    dfs(0);
    cout<<ans<<endl;
    return 0;
}