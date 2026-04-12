#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
using pii = pair<int, int>;
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };

int N;
// vector<int> A;
int A[6020];
void input(){
    fast_io();
    cin >> N;
    // A.resize(3*N);
    for (int i = 0; i < 3*N; i++)
    {
        cin >> A[i];
    }
}

inline void chmax(int &a, const int& b){if(a<b) a=b;}

int solve(){
    // vector<vector<int> > dp(N+1,vector<int>(N+1,-1e6));
    int dp[2010][2010];
    for (int i = 0; i <= N+1; i++)
    {
        for (int j = 0; j <= N+1; j++)
        {
            dp[i][j] = (int)(-1e6);
        }
        
    }
    
    dp[A[0]][A[1]] = 0;
    dp[A[1]][A[0]] = 0;
    int dp_max = 0;
    int add_all = 0;
    // vector<int> dp_maxk(N+1,-1e6);
    int dp_maxk[2010];
    for (int i = 0; i <= N+1; i++)
    {
        dp_maxk[i] = (int)(-1e6);
    }
    
    // memset(dp_maxk,-(int)1e6, sizeof(dp_maxk));
    dp_maxk[A[0]] = 0;
    dp_maxk[A[1]] = 0;
    for(int i = 1; i < N; i++){
        if(A[3*i-1]==A[3*i] && A[3*i]==A[3*i+1])
        {
            // 全部一致
            add_all++;
        }
        else if(A[3*i-1]==A[3*i] || A[3*i]==A[3*i+1] || A[3*i+1]==A[3*i-1])
        {
            // 二つ一致
            int p, q;
            if(A[3*i-1]==A[3*i]){
                p = A[3*i-1];
                q = A[3*i+1];
            }
            else if(A[3*i]==A[3*i+1]){
                p = A[3*i];
                q = A[3*i-1];
            }
            else if(A[3*i+1]==A[3*i-1]){
                p = A[3*i+1];
                q = A[3*i];
            }

            int dqq = dp[q][q] + 1; 
            int dpk[2010];
            for (int k = 1; k <= N; k++)
            {
                dpk[k] = dp[p][k] + 1;
            }

            for (int k = 1; k <= N; k++)
            {
                chmax(dp[k][q], dp_maxk[k]);
                chmax(dp[q][k], dp_maxk[k]);
                chmax(dp[k][p], dp_maxk[k]);
                chmax(dp[p][k], dp_maxk[k]);
            }

            chmax(dp[p][p], dp_max);
            chmax(dp[p][q], dp_max);
            chmax(dp[q][p], dp_max);
            chmax(dp_maxk[p], dp_max);
            chmax(dp_maxk[q], dp_max);

            for (int k = 1; k <= N; k++)
            {
                chmax(dp[k][q], dpk[k]);
                chmax(dp[q][k], dpk[k]);
                chmax(dp_max, dpk[k]);
                chmax(dp_maxk[k], dpk[k]);
                chmax(dp_maxk[q], dpk[k]);
            }
            
            chmax(dp[p][p], dqq);
            chmax(dp_max, dqq);
            chmax(dp_maxk[p], dqq);

        }
        else
        {
            // 全部ばらばら
            int p, q, r;
            p = A[3*i-1];
            q = A[3*i];
            r = A[3*i+1];
            int dpp = dp[p][p] + 1;
            int dqq = dp[q][q] + 1;
            int drr = dp[r][r] + 1;

            for(int k = 1; k<=N; k++){
                chmax(dp[p][k], dp_maxk[k]);
                chmax(dp[q][k], dp_maxk[k]);
                chmax(dp[r][k], dp_maxk[k]);
                chmax(dp[k][p], dp_maxk[k]);
                chmax(dp[k][q], dp_maxk[k]);
                chmax(dp[k][r], dp_maxk[k]);
            }
            
            chmax(dp[p][q], dp_max);
            chmax(dp[p][r], dp_max);
            chmax(dp[q][p], dp_max);
            chmax(dp[q][r], dp_max);
            chmax(dp[r][q], dp_max);
            chmax(dp[r][p], dp_max);
            chmax(dp_maxk[p], dp_max);
            chmax(dp_maxk[q], dp_max);
            chmax(dp_maxk[r], dp_max);

            
            chmax(dp[q][r], dpp);
            chmax(dp[r][q], dpp);
            chmax(dp_max, dpp);
            chmax(dp_maxk[r], dpp);
            chmax(dp_maxk[q], dpp);

            chmax(dp[p][r], dqq);
            chmax(dp[r][p], dqq);
            chmax(dp_max,   dqq);
            chmax(dp_maxk[r], dqq);
            chmax(dp_maxk[p], dqq);

            chmax(dp[p][q], drr);
            chmax(dp[q][p], drr);
            chmax(dp_max, drr);
            chmax(dp_maxk[p], drr);
            chmax(dp_maxk[q], drr);
        }
    }
    int ans = dp_max;
    int last = A[3*N-1];
    chmax(ans, dp[last][last] + 1);
    cout << (ans + add_all) << "\n";
    return 0;
} 

int main()
{
    input();
    solve();
    return 0;
}