#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mx=3002;
ll dp[mx][mx];
//bool vis[mx][mx];
ll arr[mx];
ll solve(ll n){

    for(ll L=n;L>0;L--){
        for(ll R=L;R<=n;R++){
            if(L==R){
                dp[L][R]=arr[L];
            }else{
                dp[L][R]=max(arr[L]-dp[L+1][R],arr[R]-dp[L][R-1]);
            }
        }
    }
    return dp[1][n];

}


int main(){
    int n;
    cin>>n;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        cout<<solve(n);

}
