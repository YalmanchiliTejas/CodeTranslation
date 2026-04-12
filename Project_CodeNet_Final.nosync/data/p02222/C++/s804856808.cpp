#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int dp[110000];
Int dep[110000];
Int dpr[110000];

Int far(Int x, Int y){
    if(dep[x] < dep[y])return dp[y];
    else return dpr[x];
}

vector<Int> edge[110000];
void dfs(Int x, Int last = -1){
    dp[x] = 0;
    for(auto to:edge[x]){
        if(to == last)continue;
        dep[to] = dep[x] + 1;
        dfs(to, x);
        dp[x] = max(dp[x], dp[to] + 1);
    }
}

void dfs2(Int x, Int last = -1){
    vector<int> vec;
    vec.push_back(0);
    if(last != -1)vec.push_back(dpr[x] + 1);
    for(auto to:edge[x]){
        if(to == last)continue;
        vec.push_back(dp[to] + 1);
    }
    sort(vec.rbegin(), vec.rend());
    for(auto to:edge[x]){
        if(to == last)continue;
        if(vec[0] == dp[to] + 1) dpr[to] = vec[1];
        else dpr[to] = vec[0];
        dfs2(to, x);
    }
}

int main(){
    Int n, u, v;
    cin >> n;
    for(int i = 0;i < n-1;i++){
        cin >> u >> v;u--,v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(0);
    dfs2(0);
    Int triangle = 0;
    for(int i = 0;i < n;i++){
        if(edge[i].size() <= 2)continue;
        vector<int> vec;
        for(auto to:edge[i]){
            vec.push_back(far(i, to)+1);
        }
        sort(vec.rbegin(), vec.rend());
        Int a = vec[0], b = vec[1], c = vec[2];
        bool done = false;
        if(a == b && b == c)triangle = max(triangle, a + b - 1);
        else triangle = max(triangle, max(a+c, b+c));
        
    }
    for(int i = 1;i <= n;i++){
        if(i <= 2 || i > triangle)cout << 1;
        else cout << 0;
    }cout << endl;
    return 0;
}
