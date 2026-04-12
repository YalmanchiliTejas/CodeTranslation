#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,dp[50],L,cnt,ok;
bool ch(void){
    for(int i=0;i<n;i++){
        if(dp[i]>=n)return false;
    }
    return true;
}
void act1(void){
    sort(dp,dp+n);
    L=min(dp[0],dp[n-1]-n+1);
    //cout<<'1'<<" "<<dp[n-1]<<" "<<L<<endl;
    cnt+=n*L;
    for(int i=0;i<n;i++)dp[i]-=L;
    return ;
}
void act2(void){
    sort(dp,dp+n);
    L=dp[n-1]/n;
    if(L==0)ok=0;
    //cout<<'2'<<" "<<dp[n-1]<<" "<<L<<endl;
    cnt+=L;
    dp[n-1]=dp[n-1]%n;
    for(int i=0;i<n-1;i++)dp[i]+=L;
    return ;
}
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>dp[i];
        //cout<<dp[i]<<endl;
    }
    while(1){
        if(ch())break;
        act1();
        ok=1;
        while(ok==1){
        if(ch())break;
        act2();
        }
    }
    cout<<cnt<<endl;
    //for(int i=0;i<n;i++)cout<<dp[i]<<endl;
}
