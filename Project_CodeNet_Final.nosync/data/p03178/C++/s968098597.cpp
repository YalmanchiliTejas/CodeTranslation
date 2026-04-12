/*   Abhijith  */
#include<bits/stdc++.h>
#include<iomanip>
#include<cmath>
#define lld long long int
#define ld long double
#define mod 1000000007
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b)	for(lld i=a;i<=b;i++)
#define repr(i,a,b) for(lld i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define	endl '\n'
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vector<lld> v(100001,0);
lld n,d;
vector<vector<vector<lld> > > dp(10001,vector<vector<lld> >(100,vector<lld>(2,-1)));
lld cou(lld sz,lld sum,lld edge)
{
    if(dp[sz][sum][edge]!=-1)
        return dp[sz][sum][edge];
    if(sz==0)
        return (sum==0);
    lld lim=9,ans=0,nedge;
    if(edge==1)
        lim = v[n-sz];
    for(lld i=0;i<=lim;i++)
    {
        nedge=0;
        if((i==lim)&&(edge==1))
            nedge=1;
        ans=(ans+cou(sz-1,(sum+i)%d,nedge))%mod;
    }
    return dp[sz][sum][edge]=ans;
}
int main()
{
      ios;
      string k;
      cin>>k;
      cin>>d;
      n=k.size();
      rep(i,0,n-1)
      {
          v[i]=(k[i]-'0');
      }
      lld ans = cou(n,0,1);
      cout<<(dp[n][0][1]-1+mod)%mod<<endl;
    return 0;
}
