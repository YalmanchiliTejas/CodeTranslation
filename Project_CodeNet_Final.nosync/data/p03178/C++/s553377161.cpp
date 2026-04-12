#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;
#define MOD 1000000007

long long dp[10001][101][2];

long long add(long long &x, long long y){
    x = (x+y)%MOD;
}

int main(){
    string K;
    cin >> K;
    int D;
    cin >> D;
    int N = K.size();

    dp[0][0][0] = 1;
    for(int i=0; i<N; i++){
        int x = K[i]-'0';
        for(int j=0; j<D; j++)
            dp[i+1][(j+x)%D][0] = dp[i][j][0];
        for(int j=0; j<D; j++){
            for(int k=0; k<x; k++)
                add(dp[i+1][(j+k)%D][1], dp[i][j][0]);
            for(int k=0; k<10; k++)
                add(dp[i+1][(j+k)%D][1], dp[i][j][1]);
        }
    }
    cout << ((dp[N][0][0] + dp[N][0][1])%MOD +(MOD-1))%MOD << endl;
    return 0;
}