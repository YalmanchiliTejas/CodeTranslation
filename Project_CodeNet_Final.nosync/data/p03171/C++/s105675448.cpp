#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<long long> a;
long long dp[3010][3010];

long long dfs(int l, int r){
    if(dp[l][r] != -1) return dp[l][r];
    if(l + r >= n) return dp[l][r] = 0;
    long long res = 0;
    if((l + r) % 2 == 0){
        res = max(dfs(l + 1, r) + a[l], dfs(l, r + 1) + a[n - r - 1]);
    }else{
        res = min(dfs(l + 1, r), dfs(l, r + 1));
    }
    return dp[l][r] = res;
}

int main(){
    cin >> n;
    a = vector<long long>(n);
    long long sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < 3010; i++){
        for(int j = 0; j < 3010; j++){
            dp[i][j] = -1;
        }
    }
    long long x = dfs(0, 0);
    long long y = sum - x;
    cout << x - y << endl;
    return 0;
}
