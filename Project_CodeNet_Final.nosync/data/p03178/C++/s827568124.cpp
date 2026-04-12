#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define SORT(v, n) sort(v, v+n)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define vi vector<int>
#define ddvi vector<vector<int>>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

// 桁DPはグローバルにしたほうがいい？
string K;
int D;

// 桁DP dp[i][flg][D] = 総数
// 上から i 桁目まで決定
// flg : K 未満が確定しているかどうか
// D : mod D の値
int dp[10002][2][101];

// modつき足し算のテンプレートクラスを用意
template<class T>
void Add(T &a, const T &b, const T &mod=1e9+7){
    int val = ((a % mod) + (b % mod)) % mod;
    if(val < 0){val += mod;}
    // aにその値を上書き
    a = val;
}

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
// ここに処理を記述
    cin >> K >> D;
    
    dp[0][0][0] = 1; // 初期化
    // DP
    REP(digit, K.size()){
        for(int smaller : {0,1}){
            REP(modD, D){
                // 未満フラグの値によってこの桁で調べるべき数字の限界を決定
                int limit = (smaller ? 9 : K[digit]-'0');
                // num : 次の桁となる数 --> modの状態遷移にかかわる
                REP(num, limit + 1){
                    // nSmaller : num == limit となるとき smaller == 0 で 0 となる
                    // つまり、前の桁まで決めたときにK未満と確定しない数において、
                    // 次の桁を決めてもK未満と確定しないときを分ける
                    int nSmaller = smaller || (num < limit);
                    if(smaller == 1 && nSmaller == 0) continue;
                    Add(dp[digit+1][nSmaller][(modD + num) % D], dp[digit][smaller][modD]);
                }
            }
        }
    }

    int ans = 0;
    for(int smaller : {0, 1}){
        Add(ans, dp[K.size()][smaller][0]);
    }

    Add(ans, -1); // 0になる場合の数を引く
    cout << ans << endl;


return 0;
}