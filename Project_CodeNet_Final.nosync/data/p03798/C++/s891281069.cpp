#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;

int solve(string s, bool *ans, int N);

int main(void){
    int N; string s;
    cin >> N >> s;
    //SS, SW, WS, WWの順にシミュレート
    bool ans[N+1];
    int res;
    ans[0] = true; ans[1] = true;
    res = solve(s, ans, N);
    if(res == 1) return 0;
    ans[0] = true; ans[1] = false;
    res = solve(s, ans, N);
    if(res == 1) return 0;
    ans[0] = false; ans[1] = true;
    res = solve(s, ans, N);
    if(res == 1) return 0;
    ans[0] = false; ans[1] = false;
    res = solve(s, ans, N);
    if(res == -1) cout << -1 << endl;
    return 0;
}

int solve(string s, bool *ans, int N){
    //1-Nまで時計回りに並んでいるとして、自分の右側の動物と自分の答えが分かっていれば自分の左側がどちらか確定する
    for(int i = 1; i <= N-1; i++){
        if(s[i] == 'o' && ans[i]){
            ans[i+1] = ans[i-1];
        }
        else if(s[i] == 'o'){
            ans[i+1] = !ans[i-1];
        }
        else if(s[i] == 'x' && ans[i]){
            ans[i+1] = !ans[i-1];
        }
        else{
            ans[i+1] = ans[i-1];
        }
    }
    //ans[0]とans[N]が等しければ辻褄が合っている -> どうやらそうではないらしい s[N-1]の検査をしているだけ
    //検査してないのはs[0].そこの正当性を確認する
    //正当なのはans[0]がS && s[0]がo && (ans[1] == ans[N-1]), ans[0]がS && s[0]がx && (ans[1] != ans[N-1]),...
    if((ans[0] == ans[N])){
        if(ans[0] && s[0] == 'o' && (ans[1] == ans[N-1]) ||
           ans[0] && s[0] == 'x' && (ans[1] != ans[N-1]) ||
           !ans[0] && s[0] == 'o' && (ans[1] != ans[N-1]) ||
           !ans[0] && s[0] == 'x' && (ans[1] == ans[N-1]))
        {
            rep(i, N){
                if(ans[i]) cout << 'S';
                else cout << 'W';
            }
            cout << endl;
            return 1;
        }
        else return -1;
    }
    else return -1;
}