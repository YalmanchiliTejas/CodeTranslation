#include <bits/stdc++.h>
using namespace std;

void chmax(int& a, int b){
    a = max(a, b);
}

int main(){
    int N;
    cin >> N;
    vector<int> A(3*N);
    for(int i=0; i<3*N; i++) cin >> A[i], A[i]--;

    vector<vector<int>> dp(N, vector<int>(N, -1e9));
    dp[A[0]][A[1]] = dp[A[1]][A[0]] = 0;
    int fix = 0, mx = 0;
    vector<int> mxr(N, -1e9);
    mxr[A[0]] = mxr[A[1]] = 0;

    for(int t=0; t<N-1; t++){
        vector<int> vs;
        for(int k=0; k<3; k++) vs.push_back(A[3*t+2+k]);
        sort(vs.begin(), vs.end());
        if(vs[0] == vs[2]){
            fix++;
            continue;
        }

        vector<tuple<int, int, int>> upd;
        
        if(vs[0] == vs[1] || vs[1] == vs[2]){
            int v2 = vs[1], v1;
            for(int v : vs) if(v != v2) v1 = v;
            for(int j=0; j<N; j++) upd.emplace_back(dp[v2][j]+1, v1, j);
        }

        for(int k=0; k<3; k++){
            int v = vs[k], a = vs[(k+1)%3], b = vs[(k+2)%3];
            upd.emplace_back(dp[v][v]+1, a, b);
            upd.emplace_back(mx, v, a);
            upd.emplace_back(mx, v, b);
            for(int i=0; i<N; i++) upd.emplace_back(mxr[i], v, i);                        
        }

        for(auto& [d, a, b] : upd){
            chmax(dp[a][b], d);
            chmax(dp[b][a], d);
            chmax(mx, d);
            chmax(mxr[a], d);
            chmax(mxr[b], d);
        }
    }

    int L = A.back();
    int ans = max(mx, dp[L][L]+1) + fix;
    cout << ans << endl;
    return 0;
}
