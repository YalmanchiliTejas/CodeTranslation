#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define si size()
#define bk back()
#define popb pop_back()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define emp empty()
#define beg begin()
#define en end()
#define ump unordered_map
#define forl(i,a,n) for(int i=a;i<n;i++)
#define rfor(i,n,a) for(int i=n;i>=a;i--)
#define fore(i,a,n) for(int i=a;i<=n;i++)
#define len length()
const ll mod=1e9+7;
int main()
{
   string s;
   cin>>s;
   int d;
   cin>>d;
   vector<vector<ll>>dp(d,vector<ll>(2));
   int n=s.len;
   dp[0][0]=1;

   //dp[i][j]  j=0 number not small already  j=1 number already small
   forl(i,0,n)
   {
       vector<vector<ll>>newdp(d,vector<ll>(2));
       forl(j,0,d)
       {
           forl(k,0,2)
           {
               forl(digit,0,10)
               {
                   if(k==0 && digit>s[i]-'0') break;
                   if(k==1)newdp[(j+digit)%d][k]=(newdp[(j+digit)%d][k]+dp[j][k])%mod;
                   else 
                   {
                       if(digit<s[i]-'0')
                       {
                            newdp[(j+digit)%d][1]=(newdp[(j+digit)%d][1]+dp[j][k])%mod; 
                       }else{
                           newdp[(j+digit)%d][0]=(newdp[(j+digit)%d][0]+dp[j][k])%mod; 
                       }
                   }
               }
           }
       }
       dp=newdp;
   }    
   cout<<(dp[0][0]+dp[0][1]+mod-1)%mod<<endl;

}