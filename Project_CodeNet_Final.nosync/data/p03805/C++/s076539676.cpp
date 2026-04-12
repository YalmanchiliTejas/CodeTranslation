#include<bits/stdc++.h>
using namespace std;
vector <vector <int  > > graph(100);
int ans[100]={0};
int n,m;
void rec(int i,int visi, vector <bool > visited)
{
    visi++;
    visited[i]=true;
    //cout<<i<<endl;
    if(visi==n)
    {
        ans[i]++;
        return;
    }
    for(int j=0;j<graph[i].size();j++)
        if(!visited[graph[i][j]])rec(graph[i][j],visi,visited);
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int out=0;
        vector <bool > visited(100,false);
        for(int i=1;i<=n;i++){ans[i]=0;visited[i]=false;}
        rec(1,0,visited);
        int flag=0;
        for(int i=1;i<=n;i++)if(ans[i]>0)flag=1;
        int temp=0;
        if(flag)
        for(int i=1;i<=n;i++)
        {
           // cout<<ans[i]<<" ";
            temp+=ans[i];
        }
        if(temp>out)out=temp;
        //cout<<endl;
    cout<<out<<endl;
}
