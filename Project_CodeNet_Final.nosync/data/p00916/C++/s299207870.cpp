#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <climits>
using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define RREP(i,n) for(int i=(int)n-1; i>=0; i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pipii;
typedef vector<int> vi;

#define int ll

int N;
int l[64], t[64], r[64], b[64];
int table[256][256];

inline bool in(int i, int j){return i >= 0 && j >= 0 && i < 256 && j < 256;}
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

void dfs(int x, int y){
    int t = table[x][y];
    table[x][y] = -1;
    for(int d = 0; d < 4; d++){
        int nx = x + dx[d], ny = y + dy[d];
        if(in(nx, ny) && table[nx][ny] == t) dfs(nx, ny);
    }
}

signed main(void){
    while(cin >> N, N){
        vector<int> tmp;
        map<int, int> zip;
        for(int i = 0; i < N; i++){
            cin >> l[i] >> t[i] >> r[i] >> b[i];
            tmp.pb(l[i]);
            tmp.pb(t[i]);
            tmp.pb(r[i]);
            tmp.pb(b[i]);
        }
        sort(tmp.begin(), tmp.end());
        for(int i = 1; i <= tmp.size(); i++){
            zip[tmp[i-1]] = i;
        }
        memset(table, 0, sizeof(table));
        for(int i = 0; i < N; i++){
            int mask = 1LL << i;
            int left = zip[l[i]];
            int right = zip[r[i]];
            int top = zip[t[i]];
            int bottom = zip[b[i]];
            for(int x = left; x < right; x++)
                for(int y = bottom; y < top; y++)
                    table[x][y] |= mask;
        }
        int ans = 0;
        for(int i = 0; i < 256; i++)
            for(int j = 0; j < 256; j++)
                if(table[i][j] != -1){
                    ans++;
                    dfs(i, j);
                }

        cout << ans << endl;
    }
}