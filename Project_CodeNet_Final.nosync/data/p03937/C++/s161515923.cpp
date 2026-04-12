#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr long long INFL = numeric_limits<long long>::max() / 2;
constexpr int MOD = 1000000007;
using Graph = vector<vector<int>>;



int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int H,W;
    cin >> H >> W;
    char A[H][W];
    rep(i,H){
        rep(j,W){
            cin >> A[i][j];
        }
    }
    string ans="Possible";
    rep(i,H){
        rep(j,W){
            if(A[i][j]=='#' && A[i+1][j]=='#' && A[i][j+1]=='#'){
                ans="Impossible";
            }
            if(A[i][j]=='#' && A[i-1][j]=='#' && A[i][j-1]=='#'){
                ans="Impossible";
            }
        }
    }
    cout << ans << endl;







}
