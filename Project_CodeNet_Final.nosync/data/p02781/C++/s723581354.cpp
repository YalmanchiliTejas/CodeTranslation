#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
string s;
int k;
ll dp[200][4][2];
ll f(int i,int cnt,bool b)
{
    if (i==(int)s.length())
        return(cnt==k);
    if (dp[i][cnt][b]!=-1)
        return dp[i][cnt][b];
    int lmt;
    if (!b)
    {
        lmt=s[i]-'0';
    }
    else
    {
        lmt=9;
    }
    ll res=0;
    for (int j=0;j<=lmt;j++){
        bool t=b;
        int c=cnt;
        if (!b&&j<lmt)
            t=1;
        if (j!=0)
            c++;
        if (c<=k)
            res+=f(i+1,c,t);
    }
    return dp[i][cnt][b]=res;
}
int main()
{
    FASTINOUT;
    cin>>s;
    cin>>k;
    memset(dp,-1,sizeof dp);
    cout<<f(0,0,0);
    return 0;
}