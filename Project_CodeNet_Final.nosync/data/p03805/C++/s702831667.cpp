#include <iostream>
#include <cmath>
#include <vector>
#define rep(i,n) for(int i=0;i<(n);++i)

using namespace std;
typedef long long ll;

typedef vector<vector<int> > Graph;

bool flag;




void dfs(Graph& g,int x,vector<int>& vec,int& count,int& ans){
    
    vec[x]=1;
    
    ++count;
    //cout<<"first:"<<count<<endl;
    /*rep(i,vec.size())cout<<vec[i]<<" ";
    cout<<endl;*/
    if(count==vec.size())++ans;
    
    for(int i=0;i<g[x].size();++i){
        int y=g[x][i];
        if(vec[y]==1)continue;
        dfs(g,y,vec,count,ans);
    }
  
    --count;
    //cout<<"second:"<<count<<endl;
    vec[x]=0;
    /*rep(i,vec.size())cout<<vec[i]<<" ";
       cout<<endl;*/
    
}





int main(){
    
    int N,M;
    cin>>N>>M;
    
    Graph g;
    vector<int> vec;
    int count=0;
    int ans=0;
    g.resize(N);
    vec.assign(N,false);
    
    for(int i=0;i!=M;++i){
        int a,b;
        cin>>a>>b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
   /* rep(i,N)rep(j,g[i].size())cout<<g[i][j]<<" ";
    cout<<endl;
    */
    
    dfs(g,0,vec,count,ans);
    
    cout<<ans<<endl;
 

}