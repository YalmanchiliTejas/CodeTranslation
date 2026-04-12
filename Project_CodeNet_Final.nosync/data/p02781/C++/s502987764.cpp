#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ZERO = 0;
const int Inf = 1000000000;
const ll INF= 1e18;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int dp[110][4][2];

int main() {
    string S;
    cin >> S;
    int K;
    cin >> K;
    int M = S.size();
    dp[0][0][0] = 1;
    for(int i = 0;i < M;i++) {
        for(int j = 0;j < 4;j++) {
            for(int k = 0;k < 2;k++) {
                int x = S.at(i) - '0';
                for(int l = 0;l < 10;l++) {
                    int ni = i + 1;
                    int nj = j;
                    int nk = k;
                    if(l != 0) {
                        nj++;
                    }
                    if(nj > K) {
                        continue;
                    }
                    if(k == 0) {
                        if(l > x) {
                            continue;
                        }
                        else if(l < x){
                            nk = 1;
                        }
                    }
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[M][K][0] + dp[M][K][1] << endl;
}