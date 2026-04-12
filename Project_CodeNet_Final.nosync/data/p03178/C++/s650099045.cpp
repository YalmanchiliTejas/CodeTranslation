#pragma GCC optimize("O3")

#pragma GCC optimize ("unroll-loops")

#pragma GCC optimize("-Ofast")

#include <bits/stdc++.h>

using namespace std;

 

typedef int in;

#define int long long

#define pb push_back

#define f first

#define s second

#define double long double

 

const int MAX=2e5+10;

const int MAX2=2e5+4;

const int MAAX=2e18;

const int MOD=1e9+7;

string s;

int dp[10005][105][2];

int d;

int fun(int idx,int cur,bool gr)

{

 

    if(idx==s.size())

        return !cur;

    int &ret=dp[idx][cur][gr];

    if(ret!=-1)

    {

     return ret;

    }

    ret=0;

   if(gr)

   {

      for(int i=0;i<(s[idx]-'0');i++)

      {

          ret+=fun(idx+1,(cur+i)%(d),0);

          ret%=MOD;

 

      }

      ret+=fun(idx+1,(cur+(s[idx]-'0'))%(d),1);

   ret%=MOD;

   }

   else

   {

       for(int i=0;i<10;i++)

       {

           ret+=fun(idx+1,(cur+i)%(d),0);

           ret%=MOD;

 

       }

   }

   ret%=MOD;

   return ret;

}

 

in main()

{

    memset(dp,-1,sizeof dp);

   cin>>s;

   cin>>d;

        int ans=fun(0,0,1)-1;

        ans%=MOD;

if(ans<0) ans=MOD+ans;

   cout<<ans<<endl;

   return 0;

}