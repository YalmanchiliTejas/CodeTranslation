
/**
 *    author        : Saurav Paul 
 *    created       : August 15, 2020 12:08 AM
 *    Problem Name  : L - Deque
 *    Problem Limit : 2000 ms , 1024 MB
 *    Problem Url   : https://atcoder.jp/contests/dp/tasks/dp_l
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

void solve(){
    
    int N ;
    cin >> N ;
    vector<int> v(N+1) ;
    for(int i = 1 ; i <= N ; i++) cin >> v[i];

    vector<vector<ll>>dp(N+2,vector<ll>(N+2)) ;

    for(int L = N ; L > 0 ; L--){
        for(int R = L ; R <= N ; R++){
            if(L == R) dp[L][R] = v[L] ;
            else 
                dp[L][R] = max( v[L] - dp[L+1][R] ,  v[R] - dp[L][R-1] ) ;
        }
    }
    
    cout << dp[1][N] << endl ;
}

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    for(int i = 1 ; i <= testcases ; i ++){
        solve();
    }

    return 0 ;
}
