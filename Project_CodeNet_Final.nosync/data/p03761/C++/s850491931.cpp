#include <bits/stdc++.h>
using namespace std;
int a[51][27];
int ans[27];
#define inf 1000
int main(void)
{
    memset(a,0,sizeof(a));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string x;
    fill(ans,ans+26,inf);
    for(int i=0;i<n;i++)
    {
        cin>>x;
        for(int j=0;j<x.length();j++)
        {
            a[i][x[j]-'a']++;
        }
    }
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[i]=min(ans[i],a[j][i]);
        }
    }
    string res;
    for(int i=0;i<26;i++)
    {
        string z(ans[i],char('a'+i));
        res+=z;
    }
    cout << res <<endl;
    return 0;
}
