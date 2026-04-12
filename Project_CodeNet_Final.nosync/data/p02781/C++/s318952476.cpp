#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    string s;
    int K;
    cin >> s >> K;
    int n = s.size();

    VVI dp0(n+1, VI(K+2)), dp1(n+1, VI(K+2));
    dp0[0][0] = 1;
    rep(i,n) rep(j, K+1){
        int nd = s[i] - '0';
        rep(d, 10){
            if (d == 0){
                dp1[i+1][j] += dp1[i][j];
                if (d < nd) dp1[i+1][j] += dp0[i][j];
                if (d == nd) dp0[i+1][j] += dp0[i][j];
            }else {
                if (d <= nd){
                    dp1[i+1][j+1] += dp1[i][j];
                    if (d == nd) dp0[i+1][j+1] += dp0[i][j];
                    else dp1[i+1][j+1] += dp0[i][j];
                }else{
                    dp1[i+1][j+1] += dp1[i][j];
                }
            }
        }
    }
    cout << (dp0[n][K] + dp1[n][K]) << endl;
    return 0;
}