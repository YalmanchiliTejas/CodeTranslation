#include<bits/stdc++.h>
using namespace std;
struct point{
    long long int first,second;
};
int main(){
    int n;
    cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //DP[i][j] gives maximum value chhosen by player A and B if()subarray{i.....j] isconsidered;
    point dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j].first=0;
            dp[i][j].second=0;
        }
    }
    for(int l=1;l<=n;l++){
        for(int i=0;i<n-l+1;i++){
            int j = i+(l-1);
            if(i==j){
                dp[i][j].first = arr[i];
                dp[i][j].second = 0;
            }
            else{
                if(arr[i]+dp[i+1][j].second>arr[j]+dp[i][j-1].second){
                    dp[i][j].first = arr[i]+dp[i+1][j].second;
                    dp[i][j].second = dp[i+1][j].first;
                }
                else{
                    dp[i][j].first = arr[j]+dp[i][j-1].second;
                    dp[i][j].second = dp[i][j-1].first;
                    
                }
            }
        }
    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            cout<<dp[i][j].first<<" "<<dp[i][j].second<<"   ";
//        }
//        cout<<endl;
//    }
    long long int ans=0;
    ans = dp[0][n-1].first-dp[0][n-1].second;
    cout<<ans;
    return 0;
}
