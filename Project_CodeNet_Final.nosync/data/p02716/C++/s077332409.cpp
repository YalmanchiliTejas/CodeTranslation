#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<vector>
#include<set>

/*0 1 2 3 4 5 6 7*/
using namespace std;

int slove(){
    int n;
    long long res = 0;
    cin>>n;
    vector<long long> arr(n+1,0);
    vector<long long> dp(n+1,0);
    
    for(int i = 1; i <= n; ++i){
        cin>>arr[i];
    }
    long long left = arr[1];
    for(int i = 2; i <= n; ++i){
        if(i%2 == 1){
            dp[i] = max(dp[i-2] + arr[i],dp[i-1]);
            left += arr[i];
        }else{
            dp[i] = max(dp[i-2] + arr[i],left);
        }
    }

    cout<<dp[n]<<endl;

    return 0;
}

int main(){
    slove();
    return 0;
}