#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

// dp[i][j][f] = index iまでにd(i)個選んだときの最大値
// f==0 index i は選ばない f==1 index i を選ぶ
// d(0) = i/2
// d(1) = i/2 + 1
 
long long dp[200010][2][2];
constexpr long long INF = -10000000000000;


int main(){
    int N,a;
    cin >> N;

    vector<int> As;

    for(int i=0;i<N;++i){
        dp[i][0][0] = INF;
        dp[i][0][1] = INF;
        dp[i][1][0] = INF;
        dp[i][1][1] = INF;
    }
    
    for(int i=0;i<N;++i){
        cin >> a;
        As.push_back(a);
    }
    
    for(int i=0;i<N;++i){
        if(N%2==0){
            if(i==0){
                dp[i][0][0] = 0;
                dp[i][1][1] = As[0];
            }else if(i%2==0){
                dp[i][0][0] = max( dp[i-1][1][0], dp[i-1][1][1]);
                // dp[i][0][1]
                // dp[i][1][0] 
                dp[i][1][1] = dp[i-1][1][0] + As[i];                
            }else{
                // dp[i][0][0]
                // dp[i][0][1]
                dp[i][1][0] = dp[i-1][1][1];
                dp[i][1][1] = dp[i-1][0][0] + As[i]; 
            }
        }else{
            if(i==0){
                dp[i][0][0] = 0;
                dp[i][1][1] = As[0];
            }else if(i%2==0){
                dp[i][0][0] = max( dp[i-1][1][0], dp[i-1][1][1]);
                dp[i][0][1] = dp[i-1][0][0] + As[i];
                // dp[i][1][0] 
                dp[i][1][1] = dp[i-1][1][0] + As[i];                
            }else{
                dp[i][0][0] = max( dp[i-1][0][0], dp[i-1][0][1] );
                // dp[i][0][1] 
                dp[i][1][0] = dp[i-1][1][1];
                dp[i][1][1] = dp[i-1][0][0] + As[i];
            }
        }
    }

    if(N%2==0){
        cout << max( dp[N-1][1][0], dp[N-1][1][1]) << endl;
    }else{
        cout << max( dp[N-1][0][0], dp[N-1][0][1]) << endl;
    }

    // for(int i=0;i<N;++i){
    //     printf("dp[%d][0] = %lld, dp[%d][1] = %lld\n", i, dp[i][0], i, dp[i][1]);
    // }
    
    return 0;
}
