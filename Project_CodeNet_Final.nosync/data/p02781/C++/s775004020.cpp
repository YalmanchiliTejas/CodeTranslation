#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{

string s;
    int k;
    cin>>s>>k;
   
    // vector<int> num;
    // while(n>0)
    // {
    //     num.pb(n%10);
    //     n/=10;
    // }
    // reverse(num.begin(),num.end());
    int m=s.length();
     vector<vector<int> > dp(k+1,vector<int>(2));
     dp[0][0]=1;
    for(int i=1;i<=m;i++)
    {
         vector<vector<int> > new_dp(k+1,vector<int>(2));
        for(int j=0;j<=k;j++)
        {
            if(s[i-1]!='0')
            {
                if(j<k){
            new_dp[j+1][0]+=dp[j][0];
            new_dp[j+1][1]+=((s[i-1]-'0')-1)*dp[j][0];
           
                }
                 new_dp[j][1]+=dp[j][0];
            
            }
            else new_dp[j][0]+=dp[j][0];

           // 
            if(j<k)
            new_dp[j+1][1]+=9*dp[j][1];
            new_dp[j][1]+=dp[j][1];
        }

        //dp[j][0]=
        dp=new_dp;
       

    }
    // for(auto it: dp)
    // {
    //     cout<<it[0]<<" "<<it[1]<<endl;
    // }
    cout<<dp[k][0]+dp[k][1]<<endl;

}