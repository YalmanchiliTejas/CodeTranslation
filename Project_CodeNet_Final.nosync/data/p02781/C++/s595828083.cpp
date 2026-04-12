#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);
ll dp[1005][4][2]; // dp[i][j][k]:= i桁目まで見て0以外がj個あって
// k=0:N以下がまだ確定していない k=1:N以下が確定
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;
    int K;
    cin >> K;
    int N = S.size();
    dp[0][0][0] = 1;
    rep(i,N)rep(j,4)rep(k,2){
        int x = S[i]-'0';
        rep(d,10){//新たに追加する数
            int ni = i + 1, nj = j, nk = k;
            if(d!=0)nj++;
            if(nj>3)continue;
            if(k==0 && d>x)continue;
            if(d<x)nk=1;
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    cout << dp[N][K][0] + dp[N][K][1] << endl;
}