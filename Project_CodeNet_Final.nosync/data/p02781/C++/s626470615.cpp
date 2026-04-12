#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

int dp[105][2][4];

int main() {
    string s; cin >> s;
    int k; cin >> k;
    int x = s.size();
    dp[0][0][0] = 1;
    for (int i = 0; i < x; i++) {
        for (int smaller = 0; smaller < 2; smaller++) {
            for (int j = 0; j <= k; j++) {
                int nd = s[i] - '0';
                rep(d,10) {
                    int ni = i + 1, ns = smaller, nj = j;
                    if (ns == 0) {
                        if (d > nd) continue;
                        if (d < nd) ns = 1;
                    }
                    if (d != 0) nj++;
                    if (nj > k) continue;
                    dp[ni][ns][nj] += dp[i][smaller][j];
                }
            }
        }
    }
    cout << dp[x][0][k] + dp[x][1][k] << endl;
}