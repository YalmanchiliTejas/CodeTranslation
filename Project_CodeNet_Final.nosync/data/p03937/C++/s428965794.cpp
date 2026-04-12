#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int h,w;
string s[10];
vector<pair<int,int>> check;
bool ok = 0;
void dfs(int x, int y, int cnt,vector<vector<int>> dis){
    if(ok == 1) return;
    if(cnt > 100) return ;
    int dx[] = {0, 1}, dy[] = {1, 0};
    rep(i,2){
        vector<vector<int>> copy = dis;
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < h && ny >= 0 && ny < w && s[nx][ny] == '#'){
            copy[nx][ny] = 1;
            if(nx == h - 1 && ny == w - 1){
                ok = 1;
                for(auto u : check){
                    if(copy[u.first][u.second] == 0) ok = 0;
                }
                if(ok == 1) return;
                dfs(nx, ny, cnt + 1, copy);
            }else dfs(nx, ny, cnt + 1, copy);
        }
    }
}
int main(){
    cout << fixed << setprecision(10);
    cin >> h >> w;
    rep(i,h) cin >> s[i];
    rep(i,h) rep(j,w) if(s[i][j] == '#') check.push_back({i, j});
    if(s[0][0] == '.'){
        cout << "Impossible" << endl;
        return 0;
    } 
    vector<vector<int>> dis(10, vector<int>(10, 0));
    dis[0][0] = 1;
    dfs(0, 0, 0, dis);
    if(ok) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}