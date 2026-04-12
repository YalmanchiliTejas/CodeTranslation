#include<bits/stdc++.h>
using namespace std;
long long MOD=(long long)(1e9+7);
int main()
{string s;
   long long k;
   cin>>s;
   cin>>k;
   long long dp[s.length()+1][2][k];
   memset(dp,0,2*sizeof(long long)*(s.length()+1)*k);
   dp[s.length()][0][0]=1;
   dp[s.length()][1][0]=1;
   for(long long i=s.length()-1;i>=0;i--)
   {
       for(long long j=0;j<2;j++)
       {
           for(long long rem=0;rem<k;rem++)
           {
               if(j)
               {
                   for(long long digit=0;digit<=s[i]-'0';digit++)
                   {
                       if(digit==s[i]-'0')
                       dp[i][j][rem]+=dp[i+1][1][(rem-digit+MOD*k)%k];
                       else
                       {
                           dp[i][j][rem]+=dp[i+1][0][(rem-digit+MOD*k)%k];
                           
                       }
                       dp[i][j][rem]%=MOD;
                       
                   }
            }
            else
            {
                for(long long digit=0;digit<=9;digit++)
                {
                    dp[i][j][rem]+=dp[i+1][j][(rem-digit+MOD*k)%k];
                    dp[i][j][rem]%=MOD;
                }
            }
            
   }
}}
cout<<(dp[0][1][0]+MOD-1)%MOD;
}