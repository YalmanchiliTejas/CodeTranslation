#include<bits/stdc++.h> 
using namespace std; 
#define int long long
const int mod = 1e9 + 7, N = 3001;
vector < int > l(N, 0);

int memo[N][N];

int dp(int i, int j){
    if(memo[i][j] != -1) return memo[i][j];
    if(i == j) return memo[i][j] = l[i];
    return memo[i][j] = max(l[i] - dp(i + 1, j), l[j] - dp(i, j - 1));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i = 0;i < n;++i) cin >> l[i];

    memset(memo, -1, sizeof(memo));

    cout << dp(0, n - 1) << endl;

}