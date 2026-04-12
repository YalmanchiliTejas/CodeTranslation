#include <bits/stdc++.h>
using namespace std;

// dp[pos][restrcited][count]
int dp[105][2][5];

int solve(string &n, int pos, int restricted, int cnt, int k){
    if(pos == (int)n.size()){
        return cnt == k ? 1 : 0;
    }
    
    if(dp[pos][restricted][cnt] != -1){
        return dp[pos][restricted][cnt];
    }
    
    int res = 0;
    
    if(restricted == 0){
        for(int i = 0; i <= 9; i++){
            if(i == 0){
                res += solve(n, pos + 1, 0, cnt, k);
            }else{
                if(cnt < k){
                    res += solve(n, pos + 1, 0, cnt + 1, k);
                }
            }
        }
    }else{
        int limit = n[pos] - '0';
        for(int i = 0; i <= limit; i++){
            int n_restricted = restricted;
            if(i < limit){
                n_restricted = 0;
            }
            if(i == 0){
                res += solve(n, pos + 1, n_restricted, cnt, k);
            }else{
                if(cnt < k){
                    res += solve(n, pos + 1, n_restricted, cnt + 1, k);
                }
            }
        }
    }
    
    return dp[pos][restricted][cnt] = res;
    
}






int main(){
    
    string n; int k;
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    int res = solve(n, 0, 1, 0, k);
    
    cout << res << endl;
    
}
