#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int H,W;
int shp_cnt = 0;
int dy[2] = {0,1};
int dx[2] = {1,0};
int dfs(pair<int,int> pos,const vector<vector<char>> &v, int depth) {
    auto goal = make_pair(H,W);
    if (depth == shp_cnt && goal==pos) return depth;
    if(v[pos.first][pos.second] == '.') return -1;
    auto pos1 = make_pair(pos.first+dy[0],pos.second+dx[0]);
    auto pos2 = make_pair(pos.first+dy[1],pos.second+dx[1]);

    int ret1 = dfs(pos1,v,depth+1);
    int ret2 = dfs(pos2,v,depth+1);

    return max(ret1,ret2);
}

void solve() {
    cin >> H >> W;
    vector<vector<char>> v(H+2,vector<char>(W+2,'.'));
    FOR(i,1,H+1) {
        FOR(j,1,W+1) {
            cin >> v[i][j];
            if (v[i][j]=='#') shp_cnt++;
        }
    }
    auto st = make_pair(1,1);
    auto ans = (dfs(st,v,1)==-1) ? "Impossible" : "Possible";

    cout << ans << endl;

}


int main() {
    solve();
    return 0;
}
