#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
 
int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int N, M, K; cin >> N >> M >> K;
 
    vector<int> D(N, -1);
    vector<int> v_n(M);  
    int v_count = 0;
    for (int i = 0;i < M;i++) {
        int d; cin >> d; d--; D[d] = v_count;
        v_n[v_count++] = d;
    }

    vector<vector<int>> Graph(N, vector<int>(K));
    for (int i = 0; i < N;i++) {
        for (int j = 0; j < K;j++) {
            cin >> Graph[i][j]; Graph[i][j]--;
        }
    }
 

    vector<int> dp(1 << M,INF);
    dp[(1 << M) - 1] = 0;  
    queue<int> q;
    q.push((1 << M) - 1); 
    while (!q.empty()) {
        int n = q.front(); q.pop();
 
        for (int k = 0;k < K;k++) {
            int n_ = n; 
            int next_n = 0; 
            for (int b = 0; b < M;b++) {
              
                if ((1 << b)&n_) {
                    n_ &= ~(1 << b); 
                    int next_room = Graph[v_n[b]][k]; 
                   
                    if (D[next_room] != -1) {
                        next_n |= (1 << D[next_room]);
                    }
                }
            }
 
            if (dp[next_n] > dp[n] + 1) {
                dp[next_n] = dp[n] + 1;
                q.push(next_n);
            }
        }
    }
    cout << dp[0] << endl;
}