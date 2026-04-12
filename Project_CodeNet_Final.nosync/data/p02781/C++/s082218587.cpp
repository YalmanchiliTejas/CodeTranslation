#include<cstdio>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<functional>
#include<map>
#include<set>
#include<cstring>
#include<string>
#include<stack>
#include<math.h>
#include<stdlib.h>
#include <iomanip>
using namespace std;
#define int long long
//#define double long double
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii > pip;
typedef pair<pii, pii > piipii;
typedef pair<double, double> pdd;
typedef pair<int, char> pic;
typedef priority_queue<pii, vector<pii>, greater<pii> > RPQ;
#define all(vec) vec.begin(), vec.end()
#define mk make_pair
#define INF (1 << 30)
#define INFL (1ll << 60)
#define mod 1000000007
#define se second
#define fi first

string N;
int K;
int dp[110][10][2];

int intpow(int a, int b){
    if(b == 0)return 1;
    if(b == 1)return a;
    if(b % 2 == 0){
        int tmp = intpow(a, b / 2);
        return tmp * tmp;
    }
    else {
        return a * intpow(a, b - 1);
    }
}

int digitN(int k){
    //return (N % intpow(10, k + 1)) / intpow(10, k);
    k = N.size() - k;
    return N.c_str()[k] - '0';
}

int dfs(int a, int b, bool isMax){
    if(~dp[a][b][isMax]){
        return dp[a][b][isMax];
    }
    if(b == K){
        return dp[a][b][isMax] = 1;
    }
    if(a == 1){
        return dp[a][b][isMax] = 0;
    }
    int res = 0;
    int dn = digitN(a - 1);
    if(isMax){
        for(int i = 0; i <= dn; i++){
            bool nextisMax = (i == dn);
            int nextb = b + (i != 0);
            res += dfs(a - 1, nextb, nextisMax);
        }
    }
    else{
        for(int i = 0; i <= 9; i++){
            int nextb = b + (i != 0);
            res += dfs(a - 1, nextb, isMax);
        }
    }
    return dp[a][b][isMax] = res;
}

signed main(){
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    int ketaMax = N.size();
    int dn = digitN(ketaMax);
    int res = 0;
    //cout << dn << endl;
    for(int i = 0; i <= dn; i++){
        bool nextisMax = (i == dn);
        int nextb = (i != 0);
        res += dfs(ketaMax, nextb, nextisMax);
    }
    cout << res << endl;
}


/*
状態
今の桁数　先頭の数字の桁　先頭の数字　0以外の個数　
dp[i][j][k][l]
dp[0~100][0~100][0~9][0~3]

状態遷移　配るdp dp[a][b][c][d]から配る

次の桁の数字が0の時
dp[a + 1][b][c][d] += dp[a][b][c][d];

0以外のnの時
dp[a + 1][a + 1][n][d + 1] += dp[a][b][c][d];

for(int i = 0; i < Maxketa; i++){
    for(int j = 0; j < 9; j++){

    }
}

Nの境界判定は上からずっと一致しているかでできる
一致ならNより大きくなれないので遷移に制限がある
不一致なら自由

桁がNより大きくなることはないのでNと同じ桁から始める
i = 0->dN

再帰が楽

今の桁数　0以外の個数　ここまでNと全一致しているか

*/