#include <bits/stdc++.h>
using namespace std;
 
#define DUMP(x) cerr << #x << "=" << x << endl
#define DUMP2(x, y) cerr<<"("<<#x<<", "<<#y<<") = ("<<x<<", "<<y<<")"<< endl
#define BINARY(x) static_cast<bitset<16> >(x)
 
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)
 
#define in_range(x, y, w, h) (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))
#define ALL(a) (a).begin(),(a).end()
 
typedef long long ll;
const int INF = 1e9;
typedef pair<int, int> PII;
int dx[4]={0, -1, 1, 0}, dy[4]={-1, 0, 0, 1};
 
int main()
{
    ios::sync_with_stdio(false);
 
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];
 
    bool ans = false;
    map<PII, int> vis;
    {
        int x = 0, y = 0;
        while (true) {
            vis[PII(x, y)] = true;
 
            if (x == W-1 && y == H-1) {
                ans = true;
                break;
            }
 
            if (x+1 < W && y+1 < H && S[y][x+1] == '#' && S[y+1][x] == '#') break;
            else if (x+1 < W && S[y][x+1] == '#') x++;
            else if (y+1 < H && S[y+1][x] == '#') y++;
            else break;
        }
    }
 
    if (ans) {
        rep(y, H) rep(x, W) {
            if (S[y][x] == '#' && !vis[PII(x, y)]) ans = false;
        }
    }
 
    cout << (ans ? "Possible" : "Impossible") << endl;
}