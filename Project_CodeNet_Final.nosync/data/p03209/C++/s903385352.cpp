#include <iostream>
#include <string>
#include <utility>
#include <map>

using namespace std;

map<pair<int, long long>, long long> dp;
pair<long long, long long> cnt[51];

long long dfs(int n, long long x){
    auto status = make_pair(n, x);
    if(dp.count(status)) return dp[status];
    if(x <= 1) return dp[status] = x == 1 && n == 0;
    if(cnt[n].first - 1 <= x) return cnt[n].second;
    x--;
    long long res = 0;
    if(cnt[n - 1].first - 1 <= x){
        res += cnt[n - 1].second;
    }else{
        return dfs(n - 1, x);
    }
    x -= cnt[n - 1].first;
    if(x){
        res++;
        x--;
    }
    return dp[status] = res + dfs(n - 1, x);
}

int main(){
    int n;
    long long x;
    cin >> n >> x;
    cnt[0] = make_pair(1ll, 1ll);
    for(int i = 1; i <= 50; i++){
        cnt[i] = make_pair(2 * cnt[i - 1].first + 3, 2 * cnt[i - 1].second + 1);
    }
    long long ans = dfs(n, x);
    cout << ans << "\n";
}
