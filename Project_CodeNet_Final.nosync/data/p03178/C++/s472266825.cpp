/*   Abhijith  */
#include<bits/stdc++.h>
#include<iomanip>
#include<cmath>
#define lld long int
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
    if(sz==0&&sum==0)
    {
        //cout<<sz<<" "<<sum<<" "<<edge<<" "<<"1"<<endl;
        return dp[sz][sum][edge]=1;
    }
    if(sz==0)
    {
        //cout<<sz<<" "<<sum<<" "<<edge<<" "<<"0"<<endl;
        return dp[sz][sum][edge]=0;
    }
    lld lim=9;
    if(edge==1)
        lim = v[n-sz];
    lld ans=0;
    for(lld i=0;i<=lim;i++)
    {
        if(edge==1&&i==lim)
        {
            ans=(ans+cou(sz-1,((sum+i)%d+d)%d,1LL))%mod;
            continue;
        }
        ans=(ans+cou(sz-1,((sum+i)%d+d)%d,0LL))%mod;
    }
   // cout<<sz<<" "<<sum<<" "<<edge<<" "<<ans<<endl;
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
      lld ans=0;
      rep(i,0,v[0]-1)
         ans=(ans+cou(n-1,i%d,0))%mod;
      ans=(ans+cou(n-1,v[0]%d,1))%mod;
      cout<<(ans-1+mod)%mod<<endl;
    return 0;
}
