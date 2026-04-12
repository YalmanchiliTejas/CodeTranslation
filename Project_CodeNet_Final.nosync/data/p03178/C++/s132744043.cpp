#include <bits/stdc++.h> 
using namespace std;
#define ll long long 
#define f(i, a, b) for(ll i=a;i<b;i++)
#define fi(i, a, b) for(ll i=b-1;i>=a;i--)
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define ml map<ll,ll> 
#define pll pair<ll,ll>

const ll M = (ll)(1e9+7);

void solve()
{
   string k;
   int d;
   cin>>k>>d;
   vector<vl> dp(d,vl(2,0));
   int in = k[0]-'0';
   f(i,0,in+1)
   {
      int state = (i<in);
      dp[i%d][state]++;
   }
   f(i,1,k.length())
   {
      vector<vl> dp2(d,vl(2,0));
      f(sum,0,d)
      {
         f(state,0,2)
         {
            f(j,0,10)
            {
               if(j>k[i]-'0' && state==0)break;

               dp2[(sum+j)%d][state|| (j<k[i]-'0')]+=(dp[sum][state]);
               dp2[(sum+j)%d][state|| (j<k[i]-'0')]%=M;
            }
         }
      }
      dp = dp2;
   }
   cout<<(dp[0][0] + dp[0][1]-1+M)%M;
}

int main()
{
   ll t;
   t=1;
//    cin>>t;
   while (t--)
   {
       solve();
   }  
}