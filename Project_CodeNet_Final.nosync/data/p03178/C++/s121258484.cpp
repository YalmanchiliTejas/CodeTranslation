#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long int dp[100001][101][2] = {0}, arr[100001] = {0};

long long int getsum(int index, int n, int flag, int sum, int k){
    if(index>n){
        if(sum==0) return 1;
        return 0;
    }

    if(dp[index][sum][flag]!=-1){
        return dp[index][sum][flag];
    }
    int limit = 0;
    if(flag) limit = arr[index];
    else limit = 9;
    long long int ans = 0;
    for(int i = 0; i <= limit; i++){
       if(i==limit && flag){
            ans = (ans+(getsum(index + 1, n, 1, (sum + i)%k, k)%mod))%mod;
       }
       else{
           ans = (ans+(getsum(index + 1, n, 0, (sum + i)%k, k)%mod))%mod;
       }
    }
    return dp[index][sum][flag] = ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k;
    string s;
    cin >> s >> k;
    
        memset(dp, -1, sizeof(dp));
        for(int i = 1; i <= s.size(); i++){
            arr[i] = s[i-1]-'0';
        }
        cout << (getsum(1, s.size(), 1, 0, k)-1+mod)%mod;
        
    return 0;
}