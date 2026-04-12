#include <bits/stdc++.h>
#ifdef __DEBUG__
    #define DBG(X) cout << #X << " = " << (X) << endl;
    #define SAY(X) cout << (X) << endl;
#else
    #define DBG(X)
    #define SAY(X)
#endif

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int dx[]={1, 0, -1, 0, 1,-1, 1,-1};
int dy[]={0, 1, 0, -1, 1, 1,-1,-1};
const int INT_INF = (int)(2e9);
const ll  LL_INF = (ll)(2e18);

inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const map<T, S> p) { for (auto el : p) cout << "[" << el.first << ";" << el.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (auto el : v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const deque<T>& v) { for (auto el : v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const set<T>& v) { for (auto el : v) cout << el << " "; return os; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for (auto& elem : ret) cin >> elem; return ret; }

int H,W;
vector<string> A;
void input(){
    fast_io();
    cin >> H >> W;
    for (int i = 0; i < H; i++)
    {
        string s; cin >> s;
        A.push_back(s);
    }
}

vector<vector<bool>> visited;
void dfs(int i, int j){
    visited[i][j] = true;
    int cnt = 0;
    for (int k = 0; k < 2; k++)
    {
        int x = i+dx[k];
        int y = j+dy[k];
        if(x<0 || x>=H) continue;
        if(y<0 || y>=W) continue;
        if(A[x][y]=='#') cnt++;
    }
    if(cnt!=1) return;

    for (int k = 0; k < 2; k++)
    {
        int x = i+dx[k];
        int y = j+dy[k];
        if(x<0 || x>=H) continue;
        if(y<0 || y>=W) continue;
        if(A[x][y]=='#') dfs(x,y);
    }
}

bool solve(){
    visited.assign(H,vector<bool>(W,false));
    dfs(0,0);
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if(A[i][j]=='#' && !visited[i][j]) return false;
            if(A[i][j]!='#' && visited[i][j]) return false;
        }
    }    
    return visited[H-1][W-1];
}

bool WAsolve(){
    for (int i = 0; i < H-1; i++)
    {
        for (int j = 0; j < W-1; j++)
        {
            if(A[i][j]=='#'){
                if(A[i+1][j]=='#' && A[i][j+1]=='#') return false;
                else if(A[i+1][j]=='.' && A[i][j+1]=='.') return false;
            }
        }
        
    }
    return true;
}   

int main()
{
    input();
    cout << (solve()?"Possible":"Impossible") << endl;
    return 0;
}