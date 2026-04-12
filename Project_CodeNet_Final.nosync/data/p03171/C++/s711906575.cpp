#include<bits/stdc++.h>
#define sf1(n) scanf("%d",&n)
#define sf2(n,q) scanf("%d %d",&n,&q)
#define f first
#define ss second
#define pb push_back
#define lli long long
#define mem(ar,false) memset(ar,false,sizeof(ar))
#define mpr make_pair
#define endl "\n"
#define mod 1000000007
#define inf 9000000000000000000LL

using namespace std;
lli dp[3002][3002];
lli ar[3002];
lli br[3002][3002];
int n;
lli func(int i,int j,int f)
{
    if(i>j)
        return dp[i][j] = 0LL;
    if(dp[i][j]!=-1)
        return dp[i][j];
 //   cout << i << " " << j << endl;
    lli x = 0;
    lli y = 0;
    lli d1=ar[i]+func(i+1,j,1),d2=ar[j]+func(i,j-1,1);

    x = max(d1,d2);
  //  cout << "d1 " << d1  << endl;
  //  cout << "d2 " << d2 << endl;
    if(f==0)
    {
        if(d1>d2)
        {
            return d1 - br[i+1][j];
        }
        else if(d1<d2)
        {
            return d2-br[i][j-1];
        }
        else
        {
            return d1-max(br[i][j-1],br[i+1][j]);
        }
    }
    br[i][j] = x;
    if(d1>d2)
    {
        return dp[i][j] = br[i+1][j];
    }
    else if(d1<d2)
    {
        return dp[i][j] = br[i][j-1];
    }
    else
    {
        return dp[i][j] = max(br[i][j-1],br[i+1][j]);
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mem(dp,-1);
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> ar[i];
    }

    lli ans = func(0,n-1,0);
    cout << ans << endl;

    return 0;

}
