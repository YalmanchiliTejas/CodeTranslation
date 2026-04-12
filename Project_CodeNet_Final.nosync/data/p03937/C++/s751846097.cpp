#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i < b; i++)
#define out(x) cout << x << endl
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<vector<vector<ll> > > vvvl;
ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
//cout<<fixed<<setprecision(10);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

signed main()
{   
    gearup;
    int h,w;cin>>h>>w;
    vvc s(h,vc(w));
    vector<vector<bool> > b(h,vb(w));
    rep(i,h)rep(j,w){
        cin>>s[i][j];
        if(s[i][j]=='#')b[i][j]=true;
    }
    queue<pair<int,int>> que;
    que.push(make_pair(0,0));
    b[0][0]=false;
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        bool is_right = false;
        //右と下に移動
        for(int i=0;i<3;i+=2){
            int ex = x + dx[i];
            int ey = y + dy[i];
            if(ex < 0 || ex >=h || ey <0 || ey >= w)continue;
            if(b[ex][ey]){
                b[ex][ey]=false;
                que.push(make_pair(ex,ey));
                if(is_right){
                    out("Impossible");
                    return 0;
                }
                if(i == 0)is_right = true;
            }
        }
    }
    //rep(i,h)rep(j,w)cout<<b[i][j];
    rep(i,h)rep(j,w)if(b[i][j]){
        out("Impossible");
        return 0;
    }
    out("Possible");
}
