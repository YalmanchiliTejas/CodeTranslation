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

struct dat{
    int x, y, val;
};

int N;
int A[6010];
int dp[2010][2010];

void init(){
    for(int i = 0; i <= N + 1; i++){
        for(int j = 0; j <= N + 1; j++){
            dp[i][j] = -inf;
        }
    }
    dp[max(A[1], A[2])][min(A[1], A[2])] = 0;
    dp[max(A[1], A[2])][N + 1] = 0;
    dp[min(A[1], A[2])][N + 1] = 0;
    dp[N + 1][N + 1] = 0;
}

void solve(){

    int cor = 0;
    for(int i = 1; i < N; i++){
        int idx = i * 3;

        queue<dat> q;
        //0つ一致
        for(int j = 0; j <= 2; j++){
            int to = idx + j;
            int val1 = A[idx + (j + 1) % 3];
            int val2 = A[idx + (j + 2) % 3];
            //二つ交換
            if(dp[max(val1, val2)][min(val1, val2)] < dp[N + 1][N + 1]){
                q.push(dat{max(val1, val2), min(val1, val2), dp[N + 1][N + 1]});
            }
            //一つ交換
            for(int k = 1; k <= N; k++){
                if(dp[max(k, A[to])][min(k, A[to])] < dp[k][N + 1]){
                    q.push(dat{max(k, A[to]), min(k, A[to]), dp[k][N + 1]});
                }
            }
        }

        //一つ一致
        for(int j = 0; j <= 2; j++){
            int to = idx + j;
            int val1 = A[idx + (j + 1) % 3];
            int val2 = A[idx + (j + 2) % 3];
            if(dp[max(val1, val2)][min(val1, val2)] < dp[A[to]][A[to]] + 1){
                q.push(dat{max(val1, val2), min(val1, val2), dp[A[to]][A[to]] + 1});
            }
        }

        //二つ一致
        for(int j = 0; j <= 2; j++){
            int to = idx + j;
            int val1 = A[idx + (j + 1) % 3];
            int val2 = A[idx + (j + 2) % 3];
            if(val1 != val2) continue;
            for(int k = 1; k <= N; k++){
                if(dp[max(A[to], k)][min(A[to], k)] < dp[max(val1, k)][min(val1, k)] + 1){
                    q.push(dat{max(A[to], k), min(A[to], k), dp[max(val1, k)][min(val1, k)] + 1});
                }
            }
        }

        int z = 0;
        //三つ一致
        if(A[idx] == A[idx + 1] && A[idx + 1] == A[idx + 2]) z++, cor++;

        //更新
        while(!q.empty()){
            dat d = q.front();
            q.pop();

            chmax(dp[d.x][d.y], d.val - z);
            chmax(dp[d.x][N + 1], d.val - z);
            chmax(dp[d.y][N + 1], d.val - z);
            chmax(dp[N + 1][N + 1], d.val - z);
        }
    }

    dp[A[3 * N]][A[3 * N]]++;

    int ans = 0;
    for(int i = 1; i <= N + 1; i++){
        for(int j = 1; j <= N + 1; j++){
            chmax(ans, dp[i][j]);
        }
    }
    ans += cor;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= 3 * N; i++){
        cin >> A[i];
    }

    init();

    solve();

    return 0;
}