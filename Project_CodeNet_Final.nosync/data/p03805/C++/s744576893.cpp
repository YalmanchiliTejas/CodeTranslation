#include <bits/stdc++.h>
using namespace std;
int N,M;
int MAP[9][9];
int cnt=0;

void dfs(int i,set<int> s)
{
    s.insert(i);
    if(s.size()==N)
    {
        cnt++;
        return ;
    }
    for(int j=1;j<=N;j++)
    {
        if(s.count(j)==0&&MAP[i][j]!=0)
        {
            dfs(j,s);
            s.erase(j);
        }
    }
    s.erase(i);
}
int main(void)
{
    memset(MAP,0,sizeof(MAP));
    set<int>s;
    s.clear();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    int a,b;
    for(int i=0;i<M;i++)
    {
        cin>>a>>b;
        MAP[a][b]=1;
        MAP[b][a]=1;
    }
    dfs(1,s);
    cout << cnt <<endl;
    return 0;
}
