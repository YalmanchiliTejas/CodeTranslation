#include <bits/stdc++.h>
#define rep(i,a,b) for (int64_t i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
using namespace std;
typedef long long ll;
int dx[]={1,-1,0,0,1,-1,1,-1};
int dy[]={0,0,1,-1,1,-1,-1,1};

int n,m,ans=0;
vector<vector<int>>s(10,vector<int>());
bool used[10];

void dfs(int now,int sum)
{
    used[now]=1;
    if(sum==n)ans++;
    REP(i,s[now].size())if(used[s[now][i]]==0)dfs(s[now][i],sum+1);
    used[now]=0;
}

int main()
{
    cin>>n>>m;
    REP(i,m){int a,b;cin>>a>>b;a--;b--;s[a].push_back(b);s[b].push_back(a);}
    dfs(0,1);
    cout<<ans<<endl;
}