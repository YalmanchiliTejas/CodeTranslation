#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
const int inf = 1 << 30;
const ll linf = 1e18;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}


int N;
ll A[200010];
ll dp[3][200010];
bool flag[3][200010];

ll ans = -linf;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
        dp[0][i] = -linf;
        dp[1][i] = -linf;
        dp[2][i] = -linf;
    }
    flag[0][1] = true;
    flag[1][2] = true;
    flag[2][3] = true;
    dp[0][1] = 0;
    dp[1][2] = 0;
    dp[2][3] = 0;
    for(int i = 1; i <= N; i++){
        if(flag[0][i]){
            dp[0][i] += A[i];
            chmax(dp[0][i + 2], dp[0][i]);
            chmax(dp[1][i + 3], dp[0][i]);
            chmax(dp[2][i + 4], dp[0][i]);
            flag[0][i + 2] = true;
            flag[1][i + 3] = true;
            flag[2][i + 4] = true;
        }
        if(flag[1][i]){
            dp[1][i] += A[i];
            chmax(dp[1][i + 2], dp[1][i]);
            chmax(dp[2][i + 3], dp[1][i]);
            flag[1][i + 2] = true;
            flag[2][i + 3] = true;

        }
        if(flag[2][i]){
            dp[2][i] += A[i];
            chmax(dp[2][i + 2], dp[2][i]);
            flag[2][i + 2] = true;
        }
    }

    if(N % 2 == 1){
        chmax(ans, dp[2][N]);
        chmax(ans, dp[1][N - 1]);
        chmax(ans, dp[0][N - 2]);
    }else{
        chmax(ans, dp[1][N]);
        chmax(ans, dp[0][N - 1]);
    }
    cout << ans << endl;
    return 0;
}