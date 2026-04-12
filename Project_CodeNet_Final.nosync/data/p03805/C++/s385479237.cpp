#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>

#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)
typedef long long ll;
using namespace std;
vector<vector<int>> dp;
vector<vector<bool>> edges;
#define TMP 9

ll memo(int a, int p, int end){
    if(dp[a][p] != -1){
        return dp[a][p];
    }
    if(p == end){
        return dp[a][p] = 1;
    }
    ll ans = 0;
    rep(i, edges.size()){
        bitset<TMP> pb = (p);
        if(edges[a][i] && !(pb[i])){
            pb.set(i);
            int p_n = pb.to_ulong();
            ans += memo(i, p_n, end);
        }
    }
    return (dp[a][p] = ans);
}


int main(){
    int N, M;
    cin >> N >> M;
    int size = (1 << (N));
    dp = vector<vector<int>>(N, vector<int>(size, -1));
    edges = vector<vector<bool>>(N, vector<bool>(N, false));
    rep(i, M){
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        edges[a][b] = edges[b][a] = true;
    }

    ll ans = memo(0, 1, size - 1);

    cout << ans << endl;
    return 0;
}
