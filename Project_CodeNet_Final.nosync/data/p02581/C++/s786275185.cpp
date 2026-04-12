#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main(){
    int N;
    cin >> N;
    vector<int> A(3*N+1, 0);
    for (int i = 1; i <= 3*N; i++) cin >> A[i];
    vector<vector<int>> dp(N+1, vector<int>(N+1, -1e8));
    dp[A[1]][A[2]] = 0;
    dp[A[2]][A[1]] = 0;
    
    int geta = 0;
    queue<pair<pair<int, int>, int>> renew;
    vector<int> onemax(N+1, -1e8);
    onemax[A[1]] = 0;
    onemax[A[2]] = 0;
    int nowmax = 0;
    for (int i = 1; i <= N-1; i++) {
        int c = min(A[3*i], min(A[3*i+1], A[3*i+2]));
        int e = max(A[3*i], max(A[3*i+1], A[3*i+2]));
        int d = A[3*i]+A[3*i+1]+A[3*i+2]-c-e;
        
        if (c == d && d == e) {
            geta++;
            continue;
        }else if (c == d || d == e) {
            if (d == e) swap(c, e);
            
            for (int i = 1; i <= N; i++) {
                renew.push({{e, i}, dp[c][i]+1});
            }
            renew.push({{c, c}, nowmax});
            renew.push({{c, c}, dp[e][e]+1});
            renew.push({{c, e}, nowmax});
            for (int i = 1; i <= N; i++) {
                renew.push({{c, i}, onemax[i]});
                renew.push({{e, i}, onemax[i]});
            }
        }else {
            renew.push({{d, e}, max(dp[c][c]+1, nowmax)});
            renew.push({{c, e}, max(dp[d][d]+1, nowmax)});
            renew.push({{c, d}, max(dp[e][e]+1, nowmax)});
            for (int i = 1; i <= N; i++) {
                renew.push({{c, i}, onemax[i]});
                renew.push({{d, i}, onemax[i]});
                renew.push({{e, i}, onemax[i]});
            }
        }
        while (!renew.empty()) {
            auto p = renew.front();
            int a = p.first.first, b = p.first.second;
            int v = p.second;
            renew.pop();
            onemax[a] = max(onemax[a], v);
            onemax[b] = max(onemax[b], v);
            nowmax = max(nowmax, v);
            dp[a][b] = max(dp[a][b], v);
            dp[b][a] = max(dp[b][a], v);
        }
    }
    cout << max(nowmax, dp[A[3*N]][A[3*N]]+1)+geta << endl;
	return 0;
}
