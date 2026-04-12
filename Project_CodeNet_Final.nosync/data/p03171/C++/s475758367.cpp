#include <bits/stdc++.h>

using namespace std;
string s;
long long dp[3000][3000][2];

long long a[3001];
long long solve(long long st,long long en,long long t){
    //cout<<st<<" "<<en<<" "<<t<<endl;
    if(st==en){
        if(t){
            dp[st][st][1]=a[st];
            
            return a[st];
            
        }
        else 
        
        {
            dp[st][st][0]=-a[st];
            return -a[st];
            
        }
    }
 long long ma=0;
    if(t){
        
        if(dp[st][en][1]!=1000000000000)
        {
            ma=dp[st][en][1];
            
        }
        else
        
        {
            ma= max(a[st]+solve(st+1,en,0),a[en]+solve(st,en-1,0));
            dp[st][en][1]=ma;
        }
        
    }
    else 
    {
        if(dp[st][en][0]!=1000000000000)
        {
            ma=dp[st][en][0];
            
        }
        else
        
        {
            ma= min(-a[st]+solve(st+1,en,1),-a[en]+solve(st,en-1,1));
            dp[st][en][0]=ma;
        }
    
        
    }
    return ma;
}
int main() {
   long long n;
   cin>>n;
   
   for(long long i=0;i<n;i++){
       cin>>a[i];
       
   }
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           dp[i][j][0]=1000000000000;dp[i][j][1]=1000000000000;
       }
   }
  long long ans;
   ans=solve(0,n-1,1);
   cout<<ans<<endl;
   
}