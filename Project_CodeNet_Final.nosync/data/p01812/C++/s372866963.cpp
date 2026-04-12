#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
#include <map>
#include <list>
#include <bitset>
#define debug(x) cout << #x << ": " << (x) << endl
using namespace std;

const double PI  = 3.141592653589793238463;
const int INF = 1000000007;

using ull = unsigned long long;
using ll = long long;

using Int = int;
using Double = double;

using P = pair<Int, Int>;
using V = vector<Int>;
using M = vector<V>;

int move(int now, int path, int m, V& ds, M& vss, V& ds_index){
    int next = 0;
    for(int r = 0; r < m; r++){
        if(now & (1 << r)){
            int d = ds_index[vss[ds[r]][path]];
            if(d != -1){
                next |= 1 << d;
            }
        }
    }
    return next;
}

int solve(int n, int m, int k, V& ds, M& vss){
    V ds_index(n, -1);
    for(int i = 0; i < m; i++){
        ds_index[ds[i]] = i;
    }
    V dp(1 << m, -1);
    dp[(1 << m) - 1] = 0;
    queue<int> rs;
    rs.push((1 << m) - 1);
    while(!rs.empty()){
        int now = rs.front();
        rs.pop();
        for(int i = 0; i < k; i++){
            int next = move(now, i, m, ds, vss, ds_index);
            if(dp[next] == -1){
                dp[next] = dp[now] + 1;
                rs.push(next);
            }
            if(next == 0){
                return dp[next];
            }
        }
    }
    return -1;
}


int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    V ds(m);
    for(int i = 0; i < m; i++){
        cin >> ds[i];
        ds[i]--;
    }
    M vss(n, V(k));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin >> vss[i][j];
            vss[i][j]--;
        }
    }

    cout << solve(n, m, k, ds, vss) << "\n";

    return 0;
}