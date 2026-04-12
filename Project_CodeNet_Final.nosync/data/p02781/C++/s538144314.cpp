#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int dp[105][2][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.size();
    int k;
    cin >> k;
    dp[0][0][0] = 1;
    rep(i, n) {
        int x = s[i] - '0';
        rep(j, 2) {
            // 0でない数字が何個か
            rep(k, 4) {
                // 次に入れる数字
                rep(l, j?10:x+1) {
                    if (k+(l?1:0)<=3) {
                        dp[i+1][j||(l<x)][k+(l?1:0)] += dp[i][j][k];
                    }
                }
            }
        }
    }
    cout << dp[n][0][k] + dp[n][1][k] << endl;
}