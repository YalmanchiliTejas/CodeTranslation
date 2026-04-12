#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

constexpr i64 INF = 1e12;

int n;
vector<i64> v;
i64 dp[3003][3003]={0};

i64 dfs(int left, int right){
    if(left + right == n)return 0;
    if(dp[left][right] != INF)
            return dp[left][right];

    i64 res;
    if((left+right)%2 == 0){
        res = dfs(left+1, right) + v[left];
        res = max(res, dfs(left, right+1) + v[v.size()-right-1]);
    }else{
        res = dfs(left+1, right) - v[left];
        res = min(res, dfs(left, right+1) - v[v.size()-right-1]);
    }
    dp[left][right] = res;
    return res;
}

int main(){
    cin >> n;
    for(int i=0;i<n;++i){
        i64 tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j){
            dp[i][j] = INF;
        }
    }

    cout << dfs(0, 0) << endl;

    return 0;
}
