#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int H, W; cin >> H >> W;
    string A[H];
    rep(i, H) cin >> A[i];
    queue<Pint>Q;
    Q.push(mp(0, 0));
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    int cnt = 0;
    rep(i, H)
        rep(j, W)
            if(A[i][j] == '#') ++cnt;
    visited[0][0] = true;
    while(!Q.empty()) {
        Pint q = Q.front(); Q.pop();
        if(q.first + 1 < H) if(A[q.first + 1][q.second] != '.' && !visited[q.first + 1][q.second]) Q.push(mp(q.first + 1, q.second)), visited[q.first + 1][q.second] = true;
        if(q.second + 1 < W) if(A[q.first][q.second + 1] != '.' && !visited[q.first][q.second + 1]) Q.push(mp(q.first, q.second + 1)), visited[q.first][q.second + 1] = true;
    }
    cout << ((visited[H - 1][W - 1] && H + W - 1 == cnt) ? "Possible" : "Impossible") << endl;
}
