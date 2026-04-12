#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
int C[111][111]; // nCr の 事前計算.
int p9[5] = {1, 9, 81, 729, 6561};

// 0でない数字が, ちょうどK個あるようなものの個数を計算.
// @param N: 与えられた整数.
// @param c: 現在見ている桁.
// @param k: 0でない数字が使える残りの桁数.
// @return : 計算結果.
int recursive(string N, int c, int k){
    int ret = 0, d = N.size();
    // ex.
    // 1
    // 1
    // -> 1 が 正解だが, 3 と 出力されたため, ロジック修正.
    // if(c >= d) return 1;
    if(c >= d - 1) return N[d - 1] - '0';
    if(k == 0) return 1;
    // if(c >= d) return 1;
    // hand_03 ～ hand_05 で, WA版.
    // ex.
    // 10
    //  2
    // -> 0 が 正解だが, 1 と 出力された.
    // -> 以下の桁数チェックのロジックを追加.
    if(d - c < k) return 0;
    
    if(N[c] > '0'){
        // c桁目が, 0 だった場合, (c + 1)桁目 ～ d桁目 の中で, 1 ～ 9 を k回選択できる.
        ret += C[d - 1 - c][k] * p9[k];
        
        // c桁目が, 1 ～ (N[c] - 1) だった場合, (c + 1)桁目 ～ d桁目 の中で, 1 ～ 9 を (k - 1)回選択できる.
        ret += (N[c] - '1') * C[d - 1 - c][k - 1] * p9[k - 1];
        
        // c桁目が, N[c] だった場合, (c + 1)桁目 ～ d桁目 の中で, 1 ～ 9 を (k - 1)回選択できる.
        ret += recursive(N, c + 1, k - 1);
    }else{
        ret += recursive(N, c + 1, k);
    }
    return ret;
}

int main(){
    
    // 1. 入力情報.
    int K;
    char c[111];
    scanf("%s %d", c, &K);
    string N(c);
    int d = N.size();
    
    // 2. nCr の 事前計算.
    C[0][0] = 1;
    rep(n, 111) C[n][0] = C[n][n] = 1;
    rep(n, 110) repx(k, 1, 111) C[n + 1][k] = C[n][k - 1] + C[n][k];
    assert(C[1][1] == 1);
    assert(C[1][3] == 0);
    assert(C[3][2] == 3);
    assert(C[5][3] == 10);
    assert(C[10][3] == 120);
    assert(C[55][2] == 1485);
    assert(C[100][3] == 161700);
    
    // 3. d < K の 場合.
    if(d < K){
        puts("0");
        return 0;
    }
    
    // 4. d >= K の 場合.
    // ex.
    // 1111
    // 3
    // 
    // 1011 ～ 1099: 81通り
    // 1101 ～ 1109: 9通り
    // 1110 ～ 1110: 1通り
    // 0111 ～ 0999: 729通り
    // => 合計 820通り
    int ans = recursive(N, 0, K);
    
    // 5. 出力.
    printf("%d\n", ans);
    return 0;
    
}