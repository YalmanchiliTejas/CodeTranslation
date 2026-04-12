#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
using namespace std;

#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define int long long int

template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}

typedef pair<int, int> pii;
typedef long long ll;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
constexpr ll INF = 1001001001001001LL;
constexpr ll MOD = 1000000007LL;

bool board[10][10];

signed main() {
    string s;
    while(cin >> s, s != "#") {
        memset(board, false, sizeof(board));
        int x = 0, y = 0;
        int H = 0, W = 0;
        rep(i,0,s.length()) {
            if(s[i] == 'b') {
                board[x][y] = true;
                y++;
            }
            else if(s[i] == '/') {
                H++; W = y;
                x++; y = 0;
            }
            else {
                int v = s[i] - '0';
                rep(j,0,v) y++;
            }
        }
        H++;

        int a, b, c, d; cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        swap(board[a][b], board[c][d]);

        rep(i,0,H) {
            int cnt = 0;
            rep(j,0,W) {
                if(board[i][j]) {
                    if(cnt) cout << cnt;
                    cout << "b";
                    cnt = 0;
                }
                else cnt++;
            }
            if(cnt) cout << cnt;
            if(i != H-1) cout << "/";
        }
        cout << endl;
    }
    return 0;
}