#include <bits/stdc++.h>
using namespace std;
 
using tpl = tuple<char, int>;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

pll dp[51]; // パンの総数, パティ総数
pll dfs(int level){
    pll res = pll(0, 0);
    if(dp[level].first != -1) return dp[level];
    if(level == 0 ) {
        res = pll(0, 1);
    }
    else{
        ll pan = 2 + 2 * dfs(level - 1).first;
        ll paty = 1 + 2 * dfs(level - 1).second;
        res = pll(pan, paty);
    }
    return dp[level] = res;
}

ll rec(int level, ll x){
    ll next_barger_sum = dfs(level - 1).first + dfs(level - 1).second;
    if(level == 0){
        return 1;
    }
    if(x == 1) {
        return 0;
    }
    if(x <= next_barger_sum + 1) {
        return rec(level - 1, x - 1);
    }
    else if(x == next_barger_sum + 2) {
        return dfs(level - 1).second + 1;
    }
    else if(x <= next_barger_sum * 2 + 2) {
        return dfs(level - 1).second + rec(level - 1, x - (2 + next_barger_sum)) + 1;
    }
    else{
        return dfs(level).second;
    }
}


int main(){

    ll N, X;
    cin >> N >> X;
    for(int i = 0; i <= N; i++) dp[i] = pii(-1,-1);
    cout << rec(N, X) << endl;

    return 0;
}
