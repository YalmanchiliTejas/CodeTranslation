#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int n;
vector<int> arr;
ll dp[3001][3001][2];
ll solve(int st,int en,int move){

    if(st>en) return 0;

    if(dp[st][en][move]!=-1) return dp[st][en][move];
    ll ans;
    if(move==0){
        ans = max(arr[st]-solve(st+1,en,1),arr[en]-solve(st,en-1,1));
    }else{
        ans = max(arr[st]-solve(st+1,en,0),arr[en]-solve(st,en-1,0));
    }

    return dp[st][en][move] = ans;


}
int main() {
    cin>>n;
    arr.resize(n);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    for(int i=0;i<n;i++) cin>>arr[i];

    ll ans; ans = solve(0,n-1,0);

    cout<<ans;

}
