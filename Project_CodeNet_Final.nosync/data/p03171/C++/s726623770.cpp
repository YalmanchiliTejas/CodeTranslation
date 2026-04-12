#include <iostream>
#include <vector>
using namespace std;

long long dp[3100][3100];

// dp[i][j]dp[i][j] 
// 元の数列から連続する区間 ai,ai+1,…,aj−1ai,ai+1,…,aj−1 を抜き出した状態の局面から出発して
// 双方最善を尽くしたときの X−YX−Y の値


int main(){
    
    int N;
    cin >> N;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    
    for (int i = 0; i < N; i++) dp[i][i] = 0;
    
    for (int len = 1; len <= N; len++){
        
        for (int i = 0; i + len <= N; i++){
            
            int j = i + len;
            
            //  先手番
            if ((N-len) % 2 == 0) dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);
            
            // 後手
            else{
                dp[i][j] = min(dp[i+1][j]-a[i], dp[i][j-1] - a[j-1]);
            }
        }
    }
    
    cout << dp[0][N] << endl;
}
