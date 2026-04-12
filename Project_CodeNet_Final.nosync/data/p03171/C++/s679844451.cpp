#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> arr(n+1,0);
    //for(int i=1;i<=n;i++) cin>>arr[i];
    vector<long long int> dp(n+1,0);
    int turn=((n-1)%2);
    for(int i=n;i>0;i--){
        cin>>arr[i];
        for(int j=i;j<=n;j++){
            if((i+j)%2==0){
                if(turn==0){
                    dp[j]=max(dp[j]+arr[i],dp[j-1]+arr[j]);
                }
                else{
                    dp[j]=min(dp[j]-arr[i],dp[j-1]-arr[j]);
                }
            }
            else{
                if(turn==1){
                    dp[j]=max(dp[j]+arr[i],dp[j-1]+arr[j]);
                }
                else{
                    dp[j]=min(dp[j]-arr[i],dp[j-1]-arr[j]);
                }
            }
        }
    }
    cout<<dp[n]<<"\n";
}