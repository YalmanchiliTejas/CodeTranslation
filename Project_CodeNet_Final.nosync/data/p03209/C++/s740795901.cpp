#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<long long> dp, paty;
long long dfs(long long N, long long X){
    long long ans = 0; 
    if(X == 1 && N == 0) return 1;
    else if(X == 1) return 0;
    if(X == dp[N]) return paty[N];
    if(X > dp[N] / 2 + 1) ans += dfs(N - 1, X - dp[N] / 2 - 1) + 1 + paty[N] / 2;
    else if(X == dp[N] / 2 + 1) ans += paty[N] / 2 + 1;
    else ans += dfs(N - 1, X - 1);
    return ans;
}
int main(){
    long long N;
    cin >> N;
    long long X;
    cin >> X;
    dp.resize(N + 1), paty.resize(N + 1);
    dp[0] = 1;
    paty[0] = 1;
    for(int i = 1; i < N + 1; i++){
        dp[i] = dp[i - 1] * 2 + 3;
        paty[i] = paty[i - 1] * 2 + 1;
    }
    cout << dfs(N, X) << endl;
}