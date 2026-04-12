#include <iostream>
#include <vector>
#include <string>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    string n;   cin >> n;
    int K;  cin >> K;
    vector<vector<vector<int> > >dp(n.size()+1, vector<vector<int> >(5, vector<int>(2)));
    dp[0][0][0] = 1;
    for(int i = 0; i < n.size(); i++){
        int d = n[i] - '0';
        for(int j = 0; j <= K; j++){
            rep(k, 2)   rep(c, 10){
                if(k == 0 && c > d) continue;
                dp[i+1][j + (c != 0)][k || (c < d)] += dp[i][j][k];
            }
        }
    }
    cout << dp[n.size()][K][0] + dp[n.size()][K][1] << endl;
}

