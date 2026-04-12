#include <bits/stdc++.h>
using namespace std;
int n;
long long a[3009],dp[3009][3009],o;
long long bt(int st,int sz)
{
    if(sz==-1)return 0;
    if(dp[st][sz]!=0)return dp[st][sz];
    /*if(sz==0)
    {
        if(!o)
        dp[st][sz]=a[st];
        else dp[st][sz]=a[st]*(-1);
        return dp[st][sz];
    }*/
    long long &ret=dp[st][sz];
    if(sz%2==o)
    {
        ret=max(a[st]+bt(st+1,sz-1),a[st+sz]+bt(st,sz-1));
    }
    else
    {
        ret=min(bt(st+1,sz-1)+(-1)*a[st],bt(st,sz-1)+a[st+sz]*(-1));
    }
    return ret;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    if(n%2)o=0;
    else o=1;
    cout<<bt(0,n-1)<<"\n";
}

