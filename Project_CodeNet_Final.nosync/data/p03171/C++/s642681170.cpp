#include<iostream>
using namespace std;

long long dp[3005][3005];

long long solution(int n , int* arr , long long sum){
    
    for(int i=0 ; i<n ; i++){
        dp[i][i] = arr[i];
    }

    int i=0;
    int j=1;
    while(j<n){
        dp[i][j] = max(arr[i] , arr[j]);
        i++;
        j++;
    }
    
    for(int k=2 ; k<n ; k++){
        int i=0 ;
        int j=k;
        while(j<n){
            dp[i][j] = max(arr[i] + min(dp[i+1][j-1] , dp[i+2][j]) , arr[j] + min(dp[i][j-2] , dp[i+1][j-1]));
            i++;
            j++;
        }
    }

    // for(int i=0 ; i<n ; i++){
    //     for(int j=0 ; j<n ; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

return (2*dp[0][n-1] - sum);

}



int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    long long sum = 0;
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    cout<<solution(n , arr , sum)<<endl;
}