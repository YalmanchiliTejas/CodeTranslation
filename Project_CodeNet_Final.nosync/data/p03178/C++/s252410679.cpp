#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
#define MOD ll(1e9+7)
vector<vector<vector<ll>>> memo(1e4+5, vector<vector<ll>> (1e2+5, vector<ll>(2, -1)));

ll dp(vector<int> &v, int i, int vv, int d, int p){
    if(i >= v.size())
        return vv == 0;
    if(memo[i][vv][p] != -1)
        return memo[i][vv][p];
    memo[i][vv][p] = 0;
    for(int j = 0; j < v[i]; j++){
        memo[i][vv][p] = (memo[i][vv][p] + dp(v, i+1, (vv+j)%d, d, 0)) % MOD;
    }
    if(p){
        memo[i][vv][p] = (memo[i][vv][p] + dp(v, i+1, (vv+v[i])%d, d, 1)) % MOD;
    }else{
        for(int j = v[i]; j < 10; j++){
            memo[i][vv][p] = (memo[i][vv][p] + dp(v, i+1, (vv+j)%d, d, 0)) % MOD;
        }   
    }   
    return memo[i][vv][p];
}

signed main() { 
    cin.tie(0);
    cin.sync_with_stdio();
    string s;
    int d; 
    cin>>s>>d;
    vector<int> v(s.size());
    for(int i = 0; i < s.size(); i++){
        v[i] = s[i]-'0';
    }
    cout<<(dp(v, 0, 0, d, 1)+MOD-1)%MOD;
}
