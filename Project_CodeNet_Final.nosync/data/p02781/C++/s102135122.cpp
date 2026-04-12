#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back

i64 dp[110][2][110];

int main(){
    string N; 
    int K;
    cin >> N >> K;

    int len = N.size();
    vector<int> n(len);
    rep(i, len) n[i] = (N[i] - '0');
    dp[0][0][0] = 1;

    for(int i = 0; i < len; i++){
        for(int smaller = 0; smaller < 2; smaller++){
            for(int j = 0; j < 110; j++){
                for(int x = 0; x <= (smaller ? 9 : n[i]); x++){
                    dp[i + 1][smaller || x < n[i]][j + (x != 0)] += dp[i][smaller][j];
                }
            }
        }
    }

    cout << dp[len][0][K] + dp[len][1][K] << endl;
}