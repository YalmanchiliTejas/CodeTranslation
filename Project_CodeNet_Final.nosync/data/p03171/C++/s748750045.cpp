#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<long long>>> dp(3010,vector<vector<long long>>(3010,vector<long long>(2,-1)));
vector<long long> x;
long long n,a;

long long ans(long long start , long long end , long long type){
    if(start == end+1){
        return 0;
    }
    if(dp[start][end][type] != -1){
        return dp[start][end][type];
    }
    long long ret = max(x[start] - ans(start+1,end,1-type) , x[end] - ans(start,end-1,1-type));
    dp[start][end][type] = ret;
    return ret;
}

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i += 1){
        cin >> a;
        x.push_back(a);
    }
    cout << ans(0,n-1,0);
}