#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string.h>
#include <iomanip>
using namespace std;
#define int long long
#define ull unsigned long long
#define F first
#define S second
#define nl "\n"
#define ld long double
#define div 1000000007
#define pi 3.14159265358979323846
#define pb push_back
int a[150];
int k;
int dp[150][5][2];

int f(int pos,int n,int cnt,bool flag)
{
    if(cnt>k)
        return dp[pos][cnt][flag]=0;
    if(pos==n)
    {
        if(cnt==k)
            return dp[pos][cnt][flag]=1;
        else
            return dp[pos][cnt][flag]=0;
    }
    if(dp[pos][cnt][flag]!=-1)
        return dp[pos][cnt][flag];
    int limit=9;
    if(flag==false)
        limit=a[pos];
    int res=0;
    for(int i=0;i<=limit;i++)
    {
        int ncnt=cnt;
        if(i!=0)
            ncnt++;
        if(flag || i<limit)
            res+=f(pos+1,n,ncnt,true);
        else
            res+=f(pos+1,n,ncnt,false);
    }
    return dp[pos][cnt][flag]=res;
}

void solve()
{
    string s;cin>>s;
    cin>>k;
    for(int i=0;i<s.length();i++)
        a[i]=s[i]-'0';
    int n=s.length();
    memset(dp,-1,sizeof(dp));
    int ans=f(0,n,0,0);
    cout<<ans<<nl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
