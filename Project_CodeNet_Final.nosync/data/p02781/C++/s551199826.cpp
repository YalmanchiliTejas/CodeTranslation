#include<bits/stdc++.h>
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define print(x) cout << (x) << endl;
#define printa(x, n) for(ll i = 0; i < n; i++) {cout << (x[i]) << " ";} cout << endl;
using namespace std;
using ll = long long;

int dp[101][2][4];
//dp[i][j][k]...i桁まで見てj = 0...同じ..1..異なる k...0じゃない数

int main(void) {
    string n;
    cin >> n;
    int K;
    cin >> K;

    int sz = n.size();

    dp[0][0][0] = 1;


    //例えばi = 0ならば、i = 1に持っていける数は大体10個くらい。
    //このときdp[0][0][0](値は1)を合計10回dp[1][0][1]とかdp[1][1][1]とかに持っていきたいから、
    //        下記のようなfor文の使い方になる。
    //配る前の状態をforで全列挙して、最後のforのなかで遷移先を決定するという、いわゆる「配るDP」。


    for (int i = 0; i < sz; i++) {

        int x = n[i] - '0';
        for (int j = 0; j < 2; j++) for (int k = 0; k < 4; k++) for (int d = 0; d < 10; d++) {
            int ni = i + 1;
            int nj = j;
            int nk = k;

            if (d != 0) nk++;
            if (nk > K) continue;

            if (j == 0) {
                if (d < x) nj = 1;
                if (d > x) continue;
            }
        


            dp[ni][nj][nk] += dp[i][j][k];
            
        }
        
    }
    
    cout << dp[sz][0][K] + dp[sz][1][K] << endl;
    return 0;
}