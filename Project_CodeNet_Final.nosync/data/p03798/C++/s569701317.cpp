#include <iostream>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
#define rep(i,a,b) for (int i=a; i<(b);++i)

int N;
string S;
char dp[110000];
void check(){
    rep(i,1,N+1){
        if(dp[i-1]=='S' && dp[i]=='S'){
            if(S[i]=='o') dp[i+1] = 'S';
            else dp[i+1] = 'W';
        } else if(dp[i-1]=='S' && dp[i]=='W'){
            if(S[i]=='o') dp[i+1] = 'W';
            else dp[i+1] = 'S';
        } else if(dp[i-1]=='W' && dp[i]=='S'){
            if(S[i]=='o') dp[i+1] = 'W';
            else dp[i+1] = 'S';
        } else if(dp[i-1]=='W' && dp[i]=='W'){
            if(S[i]=='o') dp[i+1] = 'S';
            else dp[i+1] = 'W';
        }
    }
}
int main(){
    cin >> N >> S;
    S += S[0]; // 0と1の確認のために
    // 0 と1を仮定すると、S[1]の符号により2がわかる。
    // N-1まで決めて、S[N-1]の符号と合わせて0と矛盾しないかチェック

    dp[0] = 'S', dp[1] = 'S';
    check();
    if(dp[N] == dp[0] && dp[N+1] == dp[1]){
        REP(i,N) cout << dp[i];
        cout << endl;
        return 0;
    }
    dp[0] = 'S', dp[1] = 'W';
    check();
    if(dp[N] == dp[0] && dp[N+1] == dp[1]){
        REP(i,N) cout << dp[i];
        cout << endl;
        return 0;
    }
    dp[0] = 'W', dp[1] = 'S';
    check();
    if(dp[N] == dp[0]&& dp[N+1] == dp[1]){
        REP(i,N) cout << dp[i];
        cout << endl;
        return 0;
    }
    dp[0] = 'W', dp[1] = 'W';
    check();
    if(dp[N] == dp[0]&& dp[N+1] == dp[1]){
        REP(i,N) cout << dp[i];
        cout << endl;
        return 0;
    }
    cout << -1 << endl;
}