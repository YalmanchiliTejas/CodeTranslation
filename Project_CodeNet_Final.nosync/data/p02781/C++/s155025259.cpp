#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <cstring>

#define fi first
#define se second
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = 1; i < (n); ++i)
#define drep(i,n) for (int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define all(x) (x).begin(), (x).end()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define pb push_back
#define sz(x) (int)(x).size()
#define PQ(T) priority_queue<T, v(T), greater<T> >

using namespace std;
typedef long long ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;

const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;

const int mod = 1000000007;

int dp[105][4][2];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int K;
    cin >> K;
    dp[0][0][0] = 1;
    rep(i,n)rep(j,4)rep(k,2) {
        int nd = s[i] - '0';
        rep(d,10) {
            int ni = i+1, nj = j, nk = k;
            if (d != 0) ++nj;
            if (nj > K) continue;
            if (k == 0) {
                if (d > nd) continue;
                if (d < nd) nk = 1;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
        
    } 
    int ans = dp[n][K][0] + dp[n][K][1];
    cout << ans << endl;
    return 0;
}



