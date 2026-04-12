#include <bits/stdc++.h>
using namespace std;

int dfs(int const &curr, vector<vector<int> > const &edges, map<int,bool> visited)
{
    int visits=0;
    for(auto &i: visited)
    {
        visits+=i.second;
    }
    //cout<<curr<<" "<<visits<<" "<<edges.size()<<endl;
    if(visits==edges.size())
    return 1;

    int ret=0;

    for(auto &i: edges[curr])
    {
        if(!visited[i])
        {
            visited[i]=true;
            ret+=dfs(i, edges, visited);
            visited[i]=false;
        }
    }
    
    return ret;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    vector<vector<int> > edges(N); 
    int x,y;
    for(int i=0 ; i<M ; ++i)
    {
        cin>>x>>y;
        --x;
        --y;
        edges[y].push_back(x);
        edges[x].push_back(y);
    }
    map<int, bool> visited;
    visited[0]=true;
    cout<<dfs(0, edges, visited)<<endl;
    
    return 0;
}