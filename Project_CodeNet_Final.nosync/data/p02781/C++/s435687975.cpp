#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long int dp[101][4][2] = {0}, arr[101] = {0};

long long int getsum(int index, int n, int flag, int sum, int k){
    if(index>n){
        return sum==k;
    }
    if(sum==k) return 1;
    if(dp[index][sum][flag]!=-1){
        return dp[index][sum][flag];
    }
    int limit = 0;
    if(flag) limit = arr[index];
    else limit = 9;
    long long int ans = 0;
    for(int i = 0; i <= limit; i++){
       if(i==limit && flag){
           if(i>0) ans += getsum(index + 1, n, 1, sum + 1, k);
           else if(i==0) ans += getsum(index+1, n, 1, sum, k);
       }
       else{
           if(i>0) ans += getsum(index + 1, n, 0, sum + 1, k);
           else if(i==0) ans += getsum(index+1, n, 0, sum, k);
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
        cout << getsum(1, s.size(), 1, 0, k);
        
    return 0;
}