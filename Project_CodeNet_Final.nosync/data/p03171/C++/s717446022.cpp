#include "bits/stdc++.h"
using namespace std;
int Array[3005];
long long Prefix[3005] , dp[3005][3005];

void ConstructDP( int N ){
    int i , j;

    for( i = 1 ; i <= N ; ++i )
        dp[i][i] = Array[i];
    
    for( i = 2 ; i <= N ; ++i ){
        for( j = 1 ; j <= N - i + 1 ; ++j ){
            dp[j][j + i - 1] = Array[j] + Prefix[j + i - 1] - Prefix[j] - dp[j + 1][j + i - 1];
            dp[j][j + i - 1] = max( dp[j][j + i - 1] , Array[j + i - 1] + Prefix[j + i - 2] - Prefix[j - 1] - dp[j][j + i - 2] );
        }
    }
}

int main(){
    int N , i;
    scanf( "%d" , &N );

    for( i = 1 ; i <= N ; ++i ){
        scanf( "%d" , Array + i );
        Prefix[i] = Prefix[i - 1] + Array[i];
    }
    
    ConstructDP( N );
    printf( "%lld\n" , 2 * dp[1][N] - Prefix[N] );
    return 0;
}