#include <bits/stdc++.h>
using namespace std;
#define int long long
#define stoi stoll
using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;
#define ALL(c) begin(c),end(c)
#define RALL(c) rbegin(c),rend(c)
#define ITR(i,b,e) for(auto i=(b);i!=(e);++i)
#define FORE(x,c) for(auto &x:c)
#define REPF(i,a,n) for(int i=a,i##len=(int)(n);i<i##len;++i)
#define REP(i,n) REPF(i,0,n)
#define REPR(i,n) for(int i=(int)(n);i>=0;--i)
#define SZ(c) ((int)c.size())
#define CONTAIN(c,x) (c.find(x)!=end(c))
#define OUTOFRANGE(y,x,h,w) ((y)<0||(x)<0||(y)>=(h)||(x)>=(w))
#define dump(...)
const signed INF_=1001001001; const long long INF=1001001001001001001LL;
const int DX[9]={0,1,0,-1,1,1,-1,-1,0},DY[9]={-1,0,1,0,-1,1,1,-1,0};
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) {
    ITR(i,begin(v),end(v))os<<*i<<(i==end(v)-1?"":" ");return os;}
template<class T> istream& operator>>(istream &is,vector<T> &v) {
    ITR(i,begin(v),end(v)) is>>*i;return is;}
template<class T,class U> istream& operator>>(istream &is, pair<T,U> &p) {
    is>>p.first>>p.second;return is;}
template<class T, class U> bool chmax(T &a,const U &b){return a<b?a=b,1:0;}
template<class T, class U> bool chmin(T &a,const U &b){return a>b?a=b,1:0;}
template<class T> using heap=priority_queue<T,vector<T>,greater<T>>;
struct{template<class T> operator T(){T x;cin>>x;return x;}} IN;
struct before_main_function {
    before_main_function() {
        cin.tie(0);ios::sync_with_stdio(false);
        cout<<setprecision(15)<<fixed;
        #define endl "\n"
    }
} before_main_function;
//------------------8<------------------------------------8<--------------------

void solve(int n) {
    vector<int> x(3 * n), y(3 * n);
    vector<vector<int>> rect(n);
    REP(i, n) {
        int l, t, r, b;
        cin >> l >> b >> r >> t;
        r--, b--;
        x[i * 3 + 0] = l;
        x[i * 3 + 1] = r;
        x[i * 3 + 2] = r + 1;
        y[i * 3 + 0] = t;
        y[i * 3 + 1] = b;
        y[i * 3 + 2] = b + 1;
        rect[i] = {l, t, r, b};
    }
    sort(ALL(x)); sort(ALL(y));
    auto getX = [&](int X) { return lower_bound(ALL(x), X) - begin(x); };
    auto getY = [&](int Y) { return lower_bound(ALL(y), Y) - begin(y); };
    vector<vector<int>> S(200, vector<int>(200, 0));
    REP(i, n) {
        int l = getX(rect[i][0]) + 1;
        int t = getY(rect[i][1]) + 1;
        int r = getX(rect[i][2]) + 1;
        int r_ = getX(rect[i][2] + 1) + 1;
        int b = getY(rect[i][3]) + 1;
        int b_ = getY(rect[i][3] + 1) + 1;
        int num = 1 << (i + 1);
        S[t][l] += num;
        S[t][r_] -= num;
        S[b_][l] -= num;
        S[b_][r_] += num;
    }
    REP(i, 200) REPF(j, 1, 200) S[i][j] += S[i][j - 1];
    REP(i, 200) REPF(j, 1, 200) S[j][i] += S[j - 1][i];

    vector<vector<bool>> vis(200, vector<bool>(200, false));
    int ans = 0;
    REP(i, 200) {
        REP(j, 200) {
            int num = S[i][j];
            if (vis[i][j]) continue;
            ans++;
            queue<pii> q;
            q.push({i, j});
            vis[i][j] = true;
            while (!q.empty()) {
                int iy = q.front().first;
                int ix = q.front().second; q.pop();
                REP(dir, 4) {
                    int niy = iy + DY[dir];
                    int nix = ix + DX[dir];
                    if (OUTOFRANGE(niy, nix, 200, 200)) continue;
                    if (vis[niy][nix]) continue;
                    if (S[niy][nix] == num) {
                        vis[niy][nix] = true;
                        q.push({niy, nix});
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
signed main() {
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        solve(n);
    }
    return 0;
}


