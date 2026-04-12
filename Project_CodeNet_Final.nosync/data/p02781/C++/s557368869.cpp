#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
using namespace std;
typedef long long ll;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//桁dの用意をグローバルにとる
ll dp[105][4][2];

int main(){
    //文字列で使うと扱いやすい　→ 桁数はs.size()で管理.
    string s; cin >> s;
    int n = s.size();

    int K; cin >> K;

    //空集合の時は一致している.
    dp[0][0][0] = 1;
    //配っていく
    rep(i,n)rep(j,4)rep(k,2){
        //今の桁
        int nx = s[i] - '0';
        rep(d,10){

            int ni = i+1, nj= j, nk = k;
            if (d != 0) nj++;
            if (nj > K) continue;

            if (k == 0){
                if(d > nx) continue;
                if(d < nx) nk = 1;
            }

            dp[ni][nj][nk] += dp[i][j][k];
        }
    }

    dunk(dp[n][K][0] + dp[n][K][1]);
}





    