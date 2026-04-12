#include <bits/stdc++.h>
using namespace std;

int arr[10050];
int rans = 0;
const long long mod = 1e9+7;
const int N_MAX = 10005;
const int D_MAX = 100;
int dp[N_MAX][D_MAX][2];

long long d;

int go (int n, int pos , long long sum, bool flag){
    
    if(dp[pos][sum][flag] != -1){
        return dp[pos][sum][flag] % mod;
    }
    
    if( pos > n ){
        // cout<<sum<<endl;
        if(/*sum!=0 &&*/ sum % d == 0){
           return 1;
        }
        return 0;
    }
    
    int limit = 9;
    if(flag == false){
        limit = arr[pos];
    }
    
    long long ans = 0;
    
    for( int i = 0 ; i <= limit ; i++ ) {
        if(flag || i < limit)
        dp[pos][sum][flag] = ans = ( ans % mod +  (go (n, pos + 1, (sum + i) % d, true) % mod) ) % mod;
        else
        dp[pos][sum][flag] = ans = ( ans % mod +  (go (n, pos + 1, (sum + i) % d, false) % mod) ) % mod;

    }
    
    return dp[pos][sum][flag] = ans % mod;
    
}


int main() {
        string s;
        cin >> s >> d;
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i < s.size() ; i++){
            arr [i + 1] = s.at(i) - '0';
        }
        cout << ( ( go(s.size(), 1, 0, 0) % mod  - 1 ) + mod ) % mod<<endl ;
        // cout<<rans;
    return 0;
}


