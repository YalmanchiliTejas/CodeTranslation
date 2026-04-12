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
    int m=0;
    rep(i,H){
        rep(j,W){
            char x;
            cin >> x;
            if(x=='#') m++;
        }
    }
    string ans="Possible";
    if(m-(H+W-1)!=0) ans="Impossible";
    cout << ans << endl;







}
