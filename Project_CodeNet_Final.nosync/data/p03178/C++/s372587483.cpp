#include<bits/stdc++.h>
#define mod 1000000007
#define N 10001
#define D 100
using namespace std;
int dp[N][D][2],d; 
string k;
int solve(int idx,int rem,bool tight){
    if(idx==0){
        if(rem==0){
            dp[idx][rem][tight]=1;
            return dp[idx][rem][tight];
        }
        dp[idx][rem][tight]=0;
        return dp[idx][rem][tight];
    }
    if(dp[idx][rem][tight]!=-1)return dp[idx][rem][tight];
    int lim = tight==0?9:k[idx-1]-'0';
    int ans=0;
    for(int i=0;i<=lim;i++){
        bool curTight = tight;
        if(i<(k[idx-1]-'0'))curTight=0;
        ans = (ans+solve(idx-1,(rem+i)%d,curTight))%mod;
    }   
    dp[idx][rem][tight] = ans;
    return dp[idx][rem][tight];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>k>>d;
    reverse(k.begin(),k.end());  
    for(int i=0;i<k.size()+1;i++){
        for(int j=0;j<d;j++){
            for(int m=0;m<2;m++){
                dp[i][j][m]=-1;
            }
        }
    }
    int ans = (solve(k.size(),0,1)-1+mod)%mod;
    cout<<ans<<"\n";
    return 0;
}