//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

string S;
LL K;

LL ans = 0;

void solve(){
    int N = S.size();//桁数
    vector<vector<vector<LL>>> dp;
    dp = vector<vector<vector<LL>>>(N+1,vector<vector<LL>>(K+1,vector<LL>(2,0)));
    //dp[i][j][k]:
    //上からi桁目まで決めて、j個の非0を使う
    //k:0 そこまでの桁はNと一致
    //k:1 そこまでの桁ですでにN以下なことが確定
    //そのときの条件を満たす数値の個数
    dp[0][0][0] = 1;//なにも桁を決めていない状態で、0でない数字が0個、そこまでの桁が一致
    //配るイメージのDP
    for(int i=0;i<N;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<2;k++){
                int nd = S[i]-'0';
                for(int d=0;d<10;d++){
                    int ni = i+1;//i桁目まで決めて、
                    int nj = j;//j個の非0を使う
                    int nk = k;
                    if(d!=0) nj++;//nj個の非0を使う
                    if(nj>K) continue;//非0の数はK個が最大
                    if(k==0){//上からi桁目までの桁がNと一致するとき
                        if(d > nd) continue;
                        if(d < nd) nk = 1;
                    }
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }
    ans = dp[N][K][0] + dp[N][K][1];
}
 
int main(){
    cin >> S >> K;
 
    solve();

    cout << ans << endl;
    return 0;
}