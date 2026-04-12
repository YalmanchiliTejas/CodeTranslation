#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int ll
#define pb push_back
#define setbits(x)          __builtin_popcountll(x)
#define endl "\n"
typedef long long ll;
int dp[101][4][2];
int find(string str,int tight,int cnt,int n,int pos,int g)
{  if(pos==n)
{
    if(cnt==g)
    {
        return 1;
    }
    else
        return 0;
}
if(cnt>g)
    return 0;
if(dp[pos][cnt][tight]!=-1)
    return dp[pos][cnt][tight];

    int x=str[pos]-'0';
    if(tight==0)
        x=9;
        int val=0;
for(int i=0;i<=x;i++)
{if(i==0)
{
    val+=find(str,tight&(str[pos]==i+'0'),cnt,n,pos+1,g);
}
else
   val+=find(str,tight&(str[pos]==i+'0'),cnt+1,n,pos+1,g);
}
dp[pos][cnt][tight]=val;
return val;

}
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string str;
cin>>str;
int k;
cin>>k;
for(int i=0;i<101;i++)
{
    for(int j=0;j<4;j++)
    {
        for(int k=0;k<2;k++)
            dp[i][j][k]=-1;
    }
}
int n=str.size();


int ans=find(str,1,0,n,0,k);

cout<<ans<<endl;
    return 0;
}
