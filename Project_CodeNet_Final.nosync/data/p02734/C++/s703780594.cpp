#include<bits/stdc++.h>
using namespace std;

const int M = 998244353;

int main(){
    int n,s;
    cin>>n>>s;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];

    vector<int> dp(s+1);

    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = s - arr[i]; j>=0; j--){
            dp[j+arr[i]]+=dp[j];
            dp[j+arr[i]]%=M;
        }
        if(arr[i]<=s){
            dp[arr[i]]+=i+1;
        }
    
        res += dp[s]%M;
        res%=M;
    }
    cout<<res;
}
