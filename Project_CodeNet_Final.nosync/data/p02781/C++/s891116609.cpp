#include <iostream>
#include "bits/stdc++.h"
#define ll long long int 
using namespace std;
ll dfs(ll pos,ll n, bool flag,string s,ll count,vector<vector<vector<ll>>>& dp,ll k){
        if(pos >= n) return(count == k);
        if( count > k) return 0;
        if(dp[pos][count][flag] != -1) return dp[pos][count][flag];
        ll limit=9;
        if(flag ) limit = s[pos]-'0';
        ll res=0;
        for(ll i=0;i<=limit;i++){
            if(!flag || i < limit){
                if(i != 0) res+=dfs(pos+1,n,0,s,count+1,dp,k);
                else res+=dfs(pos+1,n,0,s,count,dp,k);
            }
            else{
               if(i != 0) res+=dfs(pos+1,n,1,s,count+1,dp,k);
                else res+=dfs(pos+1,n,1,s,count,dp,k);
            }
        }
        return dp[pos][count][flag]=res;
    }
int main()
{
        ll n,k;
        string s;
        cin>>s>>k;
        vector<vector<vector<ll>>> dp(s.size(),vector<vector<ll>>(162,vector<ll>(2,-1)));
        cout<<dfs(0,s.size(),1,s,0,dp,k)<<endl;
    return 0;
}