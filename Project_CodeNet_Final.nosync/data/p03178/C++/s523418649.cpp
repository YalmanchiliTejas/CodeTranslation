#include <bits/stdc++.h>
using namespace std;
vector<int> nos;
int N, M = 1e9+7, dp[10000][100], D;
int solve(int ind, int csum, int lmt){
    if (ind==N)
        return csum==0;
    if (!lmt && dp[ind][csum]!=-1)
        return dp[ind][csum];
    int ans = 0, till = (lmt? nos[ind]: 9);
    for (int i=0; i<=till; i++){
        ans += solve(ind+1, (csum+i)%D, (lmt && i==till));
        if (ans>=M)
            ans -= M;
    }
    if (!lmt)
        dp[ind][csum] = ans;
    return ans;
}
int main(){
    memset(dp, -1, sizeof(dp));
    string S;
    cin >> S >> D;
    N = S.size();
    nos.resize(N);
    for (int i=0; i<N; i++)
        nos[i] = S[i]-'0';
    cout << (solve(0, 0, 1)-1+M)%M << "\n";
}