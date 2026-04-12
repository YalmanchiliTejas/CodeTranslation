#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n-1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
#define RALL(a) rbegin(a),rend(a)
typedef long long int ll;
typedef long double ld;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
const int MAX = 510000;
const int MOD = 1000000007;
const int inf = 1<<31-1;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main(void) {
    string s; int k; cin >> s >> k;
    int dp[110][2][4],n = s.size();
    Fill(dp, 0);
    dp[0][0][0] = 1;
    rep(i, n) {
        int nm = s[i] - '0';
        rep(j, 2) {
            rep(l, 4) {
                rep(d, 10) {
                    int nl = l, nj = j;
                    if (d != 0)nl++;
                    if (nl > k)continue;
                    if (nj == 0) {
                        if (nm < d)continue;
                        if (nm > d) nj = 1;
                    }dp[i + 1][nj][nl] += dp[i][j][l];
                }
            }
        }
    }cout << dp[n][0][k] + dp[n][1][k] << endl;
}