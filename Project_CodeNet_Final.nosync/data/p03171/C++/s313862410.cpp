#include <iostream>
#include <vector>
using namespace std;



int main()
{
    int N;
    cin >> N;
    vector<long long> a(N);
    for( int i = 0; i < N; ++i ) cin >> a[i];


    // dp[i][j]: Taro のターンで数列が a[i]~a[j] のときの X-Y
    long long dp[3000][3000] = {};
    for( int i = 0; i < N; ++i ) dp[i][i] = a[i];
    for( int i = N-2; i >= 0; --i ){
        for( int j = i+1; j < N; ++j ){
            dp[i][j] = max( a[i]-dp[i+1][j], a[j]-dp[i][j-1] );
        }
    }
    cout << dp[0][N-1] << endl;
    
    return 0;
}