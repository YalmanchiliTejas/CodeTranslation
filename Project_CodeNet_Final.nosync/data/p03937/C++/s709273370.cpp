#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int H, W;
string S[8];
int vis[8][8];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> H >> W) {
        rep(y, H)cin >> S[y];

        MEM(vis, 0);
        queue<pii> Q;
        Q.push(mp(0,0));
        while(sz(Q)) {
            int y, x;
            tie(y, x) = Q.front(); Q.pop();
            if(y < 0 || x < 0 || y >= H || x >= W || S[y][x]=='.' || vis[y][x]++)continue;
            
            if(y + 1 < H && S[y + 1][x] == '#')Q.push(mp(y + 1, x));
            else if(x + 1 < W && S[y][x + 1] == '#')Q.push(mp(y, x + 1));
        }
        bool allVisited = true;
        rep(y, H)rep(x, W)if(!vis[y][x] && S[y][x] == '#') {
            allVisited = false;
        }
        if(vis[H - 1][W - 1] && allVisited)cout << "Possible" << endl;
        else cout << "Impossible" << endl;
    }
}