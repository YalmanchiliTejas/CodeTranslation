#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 1e9;
vector<vector<int> > g(110, vector<int>(110, INF));
vector<int> bla(110, -1), d(110, 0);
int n, m, k;

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        cin >> d[i];
        bla[--d[i]] = i;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin >> g[i][j];
            g[i][j]--;
        }
    }
    // i 桁目にいる時1, いない時0
    vector<int> dp(1 << m, -1);
    dp[(1 << m) - 1] = 0;
    queue<int> que;
    que.push((1 << m) - 1);
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        if(cur == 0) break;
        for(int i = 0; i < k; i++){
            int bit = 0;
            for(int j = 0; j < m; j++){
                if(cur >> j & 1 && ~bla[g[d[j]][i]]){
                    bit |= 1 << bla[g[d[j]][i]];
                }
            }
            if(dp[bit] == -1){
                dp[bit] = dp[cur] + 1;
                que.push(bit);
            }
        }
    }
    cout << dp[0] << endl;
    return 0;
}

