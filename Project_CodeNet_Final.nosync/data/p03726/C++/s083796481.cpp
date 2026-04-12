#include <iostream>
#include <vector>
using namespace std;
const int nmax=100005;
int p[nmax],viz[nmax];
vector<int> v[nmax];
int n,a,b,i;
void dfs(int x)
{
    viz[x]=1;
    for(int i=0;i<v[x].size();i++)
        if(!viz[v[x][i]])
    {
        dfs(v[x][i]);
        if(!(p[v[x][i]]+p[x]))
        {
            p[x]=p[v[x][i]]=1;
        }
    }
}
int main()
{
    cin>>n;
    for(i=1;i<=n-1;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    for(i=1;i<=n;i++)
        if(!p[i])
    {
        cout<<"First";
        return 0;
    }
    cout<<"Second";
    return 0;
}