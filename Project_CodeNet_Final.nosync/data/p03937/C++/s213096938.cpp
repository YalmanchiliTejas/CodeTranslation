#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
int H, W;
string S[10];
bool K[10][10];
bool dfs(int a, int b) {
    if (a == H - 1 && b == W - 1) return K[a][b] = true;
    if (a + 1 < H && S[a + 1][b] == '#' && dfs(a + 1, b)) return K[a][b] = true;
    if (b + 1 < W && S[a][b + 1] == '#' && dfs(a, b + 1)) return K[a][b] = true;
    return K[a][b] = false;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> H >> W;
    rep(i, H) cin >> S[i];
    if(dfs(0, 0)) {
        rep(i, H) {
            rep(j, W) {
                if(S[i][j] == '#' && !K[i][j]) {
                    cout << "Impossible" << endl;
                    return 0;
                }
            }
        }
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
