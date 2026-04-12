#include <bits/stdc++.h>
using namespace std;

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define f           first
#define s          second
#define sz(x)       (int)x.size()
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rep0(a,n)  for(int i=0;i<n;i++)cin>>a[i]
#define si(x)       cin>>x
#define sii(x,y)    cin>>x>>y
#define siii(x,y,z) cin>>x>>y>>z
#define ahell   998244353
#define hell 1000000007
#define N1 100001
#define fl 1.0000000000
//#define mod 998244353
#define cntbit(a) __builtin_popcountl(a)
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int dp[10003][101][3];

void func(string s,int d)
{

 int i,j,k,n=s.size();
 for(i=0;i<s[0]-'0';i++)
 {
    dp[0][(i)%d][0]++;
 }

 dp[0][(s[0]-'0')%d][1]=1;

 for(i=1;i<n;i++)
 {

    for(j=0;j<d;j++)
    {
        for(k=0;k<=9;k++)
        {
            dp[i][(j+k)%d][0]+=(dp[i-1][j][0]);
            dp[i][(j+k)%d][0]%=hell;

        }
    }

    //dp[i-1][s[i]-'1'][1]

    // non-edge

    for(j=0;j<d;j++)
    {
        for(k=0;k<(s[i]-'0');k++)
        {
            dp[i][(j+k)%d][0]+=(dp[i-1][j][1]);
            dp[i][(j+k)%d][0]%=hell;

        }
     // for edge

        dp[i][(j+k)%d][1]+=(dp[i-1][j][1]);
         dp[i][(j+k)%d][1]%=hell;
    }
 }

 int ans=dp[n-1][0][0]+dp[n-1][0][1]-1;
 ans=(ans+hell)%hell;
 cout<<ans;
}
main()
{
  ios
int n,m,i;
int j;
int u,v,q;
int test=1;
//si(test);

while(test--)
{
string s;
int d;
cin>>s;
cin>>d;
func(s,d);
}

}
