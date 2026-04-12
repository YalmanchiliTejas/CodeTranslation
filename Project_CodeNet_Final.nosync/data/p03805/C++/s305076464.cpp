# pragma GCC optimize("Ofast")
# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size)
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
using namespace std;
using lint = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int N=8,white=0,gray=1,black=2;
int n;
int ans=0;

vector<vector<int> > M(N,vector<int> (N,0)); //隣接行列を用いたグラフ表現
vector<int> color(N,0),d(N,0),f(N,0); //d,fはタイムスタンプ（最初の訪問, 調べ終えた）

void dfs_visit(int u){ //グラフデータは隣接行列にて受け取る
    
    //for(auto x:color) cout << x ;
    //cout << endl;
    int count1=0;
    rep(i,n){
        if(color[i]==black) ++count1; 
    }
    if(count1==n-1) ans++;
    color[u] = black;
    rep(v,n){
        if(M[u][v] == 0) continue;
        if(color[v] == white) {
            
            dfs_visit(v);
            color[v]=white;
        }
    }
    return;
}

int main(){
    cin >> n;
    int m; cin >> m;

    rep(i,m){
        int a,b;
        cin >> a >> b;
        M[a-1][b-1] = M[b-1][a-1] = 1;
    }
    dfs_visit(0);
    /*
    rep(i,n){
        rep(j,n){
            if(j) cout << " ";
            cout << M[i][j];
        }
        cout << endl;
    }
    */
    cout << ans << endl;
    return 0;
}