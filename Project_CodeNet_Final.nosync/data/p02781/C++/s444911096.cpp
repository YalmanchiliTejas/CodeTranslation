#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

string S;
int K, N;
int dp[110][2][4];

void dfs(vector<int>& v, int last, int rest){
    if(rest == 0){

    }
    for(int i = last; i < N; i++){

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S >> K;
    N = S.length();
    dp[0][1][0] = 1;
    for(int i = 0; i < N; i++){
        int num = S[i] - '0';
        if(num == 0){
            for(int j = 0; j <= K; j++){
                dp[i + 1][1][j] += dp[i][1][j];
            }
        }else{
            for(int j = 0; j < K; j++){
                dp[i + 1][1][j + 1] += dp[i][1][j];
            }
            for(int j = 0; j < K; j++){
                dp[i + 1][0][j + 1] += dp[i][1][j] * (num - 1);
            }
            for(int j = 0; j <= K; j++){
                dp[i + 1][0][j] += dp[i][1][j];
            }
        }
        for(int j = 0; j <= K; j++){
            dp[i + 1][0][j] += dp[i][0][j];
        }
        for(int j = 0; j < K; j++){
            dp[i + 1][0][j + 1] += dp[i][0][j] * 9;
        }
    }
    cout << dp[N][0][K] + dp[N][1][K] << endl;
    return 0;
}