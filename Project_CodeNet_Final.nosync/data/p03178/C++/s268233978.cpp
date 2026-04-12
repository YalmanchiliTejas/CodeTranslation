#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;

void add_self(int& a,int b){
  a+=b;
  if(a>=mod) a-=mod;
}
int main()
{
    string s;
    int d;
    cin>>s;
    cin>>d;
    vector<vector<int>> dp1(d,vector<int>(2));
    //v[i][0] represent the number of possible digit whose sum is i and is smaller than the given number;
    // 1 represent the equal to case
    int len=s.length();
    dp1[0][0]=1;

    for(int index=0;index<len;index++){
        vector<vector<int>> dp(d,vector<int>(2));
        for(int sum=0;sum<d;sum++){
            for(bool smaller:{true,false}){
                for(int i=0;i<=9;i++){
                    if(s[index]-'0'<i && !smaller) break;
                    /*
                    if(smaller)
                    add_self(dp[(sum+i)%d][0],dp1[sum][0]);
                    else if(!smaller && s[index]-'i'>i)
                    add_self(dp[(sum+i)%d][0],dp1[sum][1]);
                    else
                     add_self(dp[(sum+i)%d][1],dp1[sum][1]);*/
                     add_self(dp[(sum+i)%d][smaller|| i<s[index]-'0'],dp1[sum][smaller]);
                }
            }
        }
     dp1=dp;
    }
    /*
     for(int i=0;i<d;i++){
        for(int j=0;j<2;j++)
            cout<<dp1[i][j]<<" ";
         cout<<"\n";
     }*/
   int ans=(dp1[0][0]+dp1[0][1])%mod;
   ans--;
   if(ans==-1)
    ans=mod-1;
   cout<<ans;
}
