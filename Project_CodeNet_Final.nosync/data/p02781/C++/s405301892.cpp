#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const int INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()

//0以上N以下の整数で，いずれかの桁に3を含むものの個数を求めよ
// 0 <= N <= 10^100
const int MAX_N = 110;
const int MAX_K = 5;

ll dp[MAX_N][2][MAX_K];
//dp[i][smaller = 0][countnot0 = k] : N以下が確定していない，その桁までに0がk個登場する
//dp[i][smaller = 1][countnot0 = k] : N以下が確定している，その桁までに0がk個登場する
//if(i桁目がnot0) dp[i + 1][smaller][countnot0 + 1] = dp[i + 1][smaller][countnot0];

int main() {
    string N; cin >> N;
    vector<int>n;
    int K; cin >> K;
    int Nlen = N.size();
    rep(i, Nlen) n.pb(N[i] - '0');
    dp[0][0][0] = 1;
    rep(i, Nlen) {
        rep(smaller, 2) {
            rep(count0, K + 1) {
                rep(x, 10) {
                    if(!smaller && x > n[i])continue;
                    dp[i + 1][smaller || (x < n[i])][count0 + (x != 0)] += dp[i][smaller][count0];
                }
            }
        }
    }
    cout << dp[Nlen][0][K] + dp[Nlen][1][K] << endl;
}
