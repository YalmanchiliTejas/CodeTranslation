#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
ll A[200000];
ll dp[200001][3];
const ll INF = 1e+17;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    if(N%2 == 0){
        dp[0][0] = A[0];
        dp[0][1] = 0;
        for(int i = 1; i < N; i++){
            if(i%2 == 0){
                dp[i][0] = dp[i-1][0]+A[i];
                dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
            }else{
                dp[i][0] = dp[i-1][0];
                dp[i][1] = max(dp[i-1][0], dp[i-1][1]+A[i]);
            }
        }
        cout << max(dp[N-1][0], dp[N-1][1]) << endl;
    }else{
        dp[0][0] = A[0];
        dp[0][1] = 0;
        dp[0][2] = -INF;
        for(int i = 1; i < N; i++){
            if(i%2 == 0){
                dp[i][0] = dp[i-1][0]+A[i];
                dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
                dp[i][2] = max(dp[i-1][2]+A[i], dp[i-1][1]);
            }else{
                dp[i][0] = dp[i-1][0];
                dp[i][1] = max(dp[i-1][0], dp[i-1][1]+A[i]);
                dp[i][2] = max(dp[i-1][2], dp[i-1][1]);
            }
        }
        cout << max({dp[N-1][0], dp[N-1][1], dp[N-1][2]}) << endl;
    }
}