#include<bits/stdc++.h>

using namespace std;

long long int dp[3005][3005];
int points[3000];
long long int pre[30001];

long long int solve(int i, int j){

    if(i == j - 1)
        return max(points[i], points[j]);

    if(dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = max(points[i] + pre[j] - pre[i] - solve(i+1, j), points[j] + pre[j-1] - pre[i-1] - solve(i, j-1));

    return dp[i][j];

}

int main(){

    int N;
    cin >> N;

    for(int i = 0; i < 3001; i++)
        for (int j = 0; j < 3001; j++)
            dp[i][j] = -1;

    for(int i = 1; i <= N; i++){

        cin >> points[i];
        pre[i] = pre[i-1] + points[i];
    }

    solve(1, N);

    cout << 2*dp[1][N] - pre[N] << endl;
    return 0;
}
