#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;
#define MOD 1000000007

int N;
long long a[3333];
long long dp[3333][3333];

long long dfs(int l, int r){
    if(l == r) return 0;
    if(dp[l][r]!=1LL<<60) return dp[l][r];

    dp[l+1][r] = dfs(l+1,r);
    dp[l][r-1] = dfs(l,r-1);

    if((N-r-l)%2==0){
        dp[l][r] = max(dp[l+1][r]+a[l], dp[l][r-1]+a[r-1]);
    }else{
        dp[l][r] = min(dp[l+1][r]-a[l], dp[l][r-1]-a[r-1]);
    }
    return dp[l][r];
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> a[i];

    for(int i=0; i<=N; i++)
        for(int j=0; j<=N; j++)
            dp[i][j] = 1LL<<60;

    cout << dfs(0, N) << endl;
    return 0;
}