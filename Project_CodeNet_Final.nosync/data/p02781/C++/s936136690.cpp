#include<bits/stdc++.h>
#define inf 1000000007
#define ll long long
using namespace std;
string a;
int k;
ll dp[1000009][4];
ll dfs(int pos,int pre,bool limit)
{
    if(pos==-1)
        return pre==k?1:0;
    if(pre>k)
        return 0;
    if(!limit&&dp[pos][k-pre]!=-1)
        return dp[pos][k-pre];
    int up=limit?a[pos]-'0':9;
    ll ans=0;
    for(int i=0; i<=up; i++)
        ans+=dfs(pos-1,pre+(i?1:0),limit&&i==up);
    if(!limit)
        dp[pos][k-pre]=ans;
    return ans;
}
int main()
{
    cin>>a>>k;
    reverse(a.begin(),a.end());
    if(!k)
    {
        printf("0");
        return 0;
    }
    for(int i=0; i<1000009; i++)
        for(int j=0; j<4; j++)
            dp[i][j]=-1;
    printf("%lld",dfs(a.length()-1,0,true));
    return 0;
}
