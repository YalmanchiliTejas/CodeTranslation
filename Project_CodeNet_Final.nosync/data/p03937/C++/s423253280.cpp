#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define CLEAR(a) memset(a,0,sizeof a)
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define fr freopen("input.txt", "r", stdin);
#define fw freopen("output.txt", "w", stdout);
typedef long long LL;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
const int MAX = 1e3 + 5;
char grid[MAX][MAX];
int vis[MAX][MAX], r, c;

bool valid(int i, int j){
    if(i >=0 &&i < r && j >=0 && j < c) return 1;
    return 0;
}

int main() {
    cin >> r >> c;
    REP(i, r) REP(j, c) cin >> grid[i][j];

    queue<pii> q;
    q.push(mp(0,0));
    vis[0][0] = 1;
    while(!q.empty()){
        pii p = q.front();
        q.pop();
        int x = p.F, y = p.S;

        if(valid(x+1, y)){
            if(grid[x+1][y] == '#' && vis[x+1][y] == 0){
                vis[x+1][y] = 1;
                q.push(mp(x+1, y));
                continue;
            }
        }
       if(valid(x, y+1)){
            if(grid[x][y+1] == '#' && vis[x][y+1] == 0){
                vis[x][y+1] = 1;
                q.push(mp(x, y+1));
            }
        }
    }

    REP(i, r){
        REP(j, c){

            if(grid[i][j] == '#' && vis[i][j] == 0){
                cout << "Impossible";
                return 0;
            }
        }
    }
    cout << "Possible";
    return 0;
}