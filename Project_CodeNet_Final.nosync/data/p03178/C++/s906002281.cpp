#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define endl "\n"     
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N=1e4+5;
const int mod=1e9+7;

int a[N],d,n;
int cache[N][101][2];

void work()
{
     string str;
     cin>>str;
     cin>>d;
     for(int i=0;i<str.size();i++)
          a[i+1]=(str[i]-'0');
     n=str.size();     
}

int dp(int pos,int m,bool ch)
{
     if(pos==n+1)
     {
          if(m==0)
               return 1;
          return 0;     
     }
     int &ans=cache[pos][m][ch];
     if(ans!=-1)    
          return ans;
     ans=0;
     if(ch==0)
     {
          for(int i=0;i<=a[pos];i++)
          {
               ans+=dp(pos+1,(m+i)%d,(i==a[pos]?0:1));
               ans%=mod;
          }
     }
     else
     {
          for(int i=0;i<=9;i++)
          {
                ans+=dp(pos+1,(m+i)%d,1);
                ans%=mod;
          }
     }
     return ans;
}

int32_t main()
{
     IOS;
     memset(cache,-1,sizeof cache);
     work();
     int ans=dp(1,0,0);
     ans--;
     ans+=mod;
     ans%=mod;
     cout<<ans;
}
