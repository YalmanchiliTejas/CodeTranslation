/*
本番ではACできなかった.
この問題は言い換えると数列を出来るだけ少ないLISに
分割するという問題となる.
解説では最終的な答えが結局は数列における
広義単調減少列の長さになるとあるので
その通り実装したらACできた.
自分がずっと考えていたことで, 
もし同じ色として塗ることができるものがこれまでに
存在する場合は新しく色を作るよりぬれるものと
同じ色で塗るのが最適らしい.（わからん）
他の人の解法を見てみると普通に前から
LISを作っていって, もし追加できるLISの候補が
複数あったらその中で最大のものに追加するという
貪欲な方法で良いらしい.（わからん）
多くの人が行なっていた後者の貪欲法だが,
ここでは各色で塗られている最大値を保持し, かつ
高速に取り出せる必要があるためmultisetを使用していた.
multisetはsetとは異なり複数要素を管理できるため
同じ要素を管理しなければならない場面でも使用できる.
multisetはlower_boundを使用できるため,
自身以上の値を対数時間で参照することができる.
注意点として, multisetのメンバ関数にあるlower_boundを
使用しないと計算量が線形になるのでmultisetの
メンバ関数を使用する.
*/
#include<iostream>
#include<set>
using namespace std;

const int MAX_N = 1e5 + 1;
const int INF = 1 << 30;

int A[MAX_N];
int dp[MAX_N];

/* 
// 解説にあるLDSで求める解法
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) dp[i] = -INF;
    for (int i = 0; i < N; ++i) {
        int l = -1, r = N - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (dp[mid] < A[i]) r = mid;
            else l = mid;
        }
        dp[r] = A[i];
    }
    for (int i = N - 1; i >= 0; --i) {
        if (dp[i] == -INF) continue;
        cout << i + 1 << endl;
        return 0;
    }
    return 0;
}
*/

// multisetを用いて貪欲に見つける方法
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    multiset<int> S;
    for (int i = 0; i < N; i++) {
        auto itr = S.lower_bound(A[i]);
        if (itr != S.begin()) S.erase(--itr);
        S.insert(A[i]);
    }
    cout << S.size() << endl;
    return 0;
}