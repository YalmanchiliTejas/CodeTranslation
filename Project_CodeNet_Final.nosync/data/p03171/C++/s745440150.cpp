#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mx=3002;
ll dp[mx][mx];
//bool vis[mx][mx];
ll arr[mx];

ll solve(int L,int R){
    if(dp[L][R]!=0){
        return dp[L][R];
    }
    if(L==R){
        dp[L][R]=arr[L];
        return dp[L][R];
    }

    dp[L][R]=max(arr[L]-solve(L+1,R),arr[R]-solve(L,R-1));
    return dp[L][R];
}


int main(){
    int n;
    cin>>n;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        cout<<solve(1,n);

}
