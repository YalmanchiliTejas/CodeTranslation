#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1000000007;

ll dp[200][10][2][4];
int n, K;
string number;

ll fun( int pos, int digit, int isStart, int k ){
    ///cout << pos << " " << digit << k << endl;
    if( k == K ){
        return 1;
    }
    if( pos == n ){
        return 0;
    }
    if( dp[pos][digit][isStart][k] != -1 ){
        return dp[pos][digit][isStart][k];
    }
    int l = 0, r = (isStart)?number[pos]-'0':9;
    ll ans = 0;
    for( int i = 0; i <= r; i++ ){
        int newK = k;
        int newStart = isStart;
        if( i == number[pos]-'0' ){
            newStart = isStart;
        }else{
            newStart = 0;
        }
        if( i != 0 ){
            newK++;
        }
        ans += fun( pos+1, i,newStart, newK );
    }
    return dp[pos][digit][isStart][k] = ans;
}

int main(){
    while( cin >> number >> K ){
        n = number.size();
        memset( dp, -1, sizeof dp );
        cout << fun( 0, 0,1, 0 ) << endl;
    }
}
