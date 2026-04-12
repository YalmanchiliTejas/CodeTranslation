#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[10000][2][5];
string s;
int n,k;
ll f(int len,bool tight,int cnt)
{
    if(cnt>k) return 0;
    if(len==n) return (cnt==k);
    if(dp[len][tight][cnt]!=-1) return dp[len][tight][cnt];
    ll ans=0;
    for(int i=0;i<10;i++)
    {
        if(tight && i>(s[len]-'0')) break;
        ans+=f(len+1,tight&(s[len]-'0'==i),cnt+(i!=0));
    }
    return dp[len][tight][cnt]=ans;
    
}

int main()
{
    cin>>s>>k;
    n=s.length();
    memset(dp,-1,sizeof(dp));
    ll ans=f(0,1,0);
    cout<<ans<<endl;
}