#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using P = pair<int, int>;
using P3 = pair<int,P>;
using PP = pair<P, P>;
constexpr int INF = 1<<29;
constexpr ll MOD = ll(1e9)+7;
constexpr int di[] = {0,1,0,-1};
constexpr int dj[] = {1,0,-1,0};


int main(){
    string n;
    int k;
    cin >> n >> k;
    ll dp[105][2][5]{};
    dp[0][0][0] = 1;
    for(int i=0;i<int(n.size());i++){
        int D = n[i]-'0';
        for(int j=0;j<2;j++){
            for(int k=0;k<=3;k++){
                for(int d=0;d<=(j?9:D);d++){
                    dp[i+1][j||(d<D)][min(k+(d!=0),4)] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[n.size()][0][k] + dp[n.size()][1][k] << endl;
    return 0;
}

