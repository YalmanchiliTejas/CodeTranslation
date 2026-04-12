

#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<regex>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
typedef int long long ll;
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m;
int miti[52][52];
int dk[52];
stack<int> s;
int ans=0;
bool  visited[8];

int  dfs(int v){
   
    bool av=true;
    rep(i,n){
        if(visited[i]==false){av=false;}
    }
    
    if(av){return 1;}
    int ret=0;
    for(int i=0;i<n;i++){
        
        if(miti[v][i]==false)continue;
        if(visited[i]==true)continue;
        visited[i]=true;
        ret+=dfs(i);
        visited[i]=false;
        
        
        
    }
    return ret;
    
    
   
}


int main(){
  
    cin>>n>>m;
    
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        miti[a-1][b-1]=1;
        miti[b-1][a-1]=1;
    }

    rep(i,8){visited[i]=false;}
    visited[0]=true;
    cout<<dfs(0)<<endl;
    
    return 0;
}
