#include <bits/stdc++.h>
using namespace std;

#define REP(i,m,n) for(int i=(m); i<(int)(n); i++)
#define RREP(i,m,n) for(int i=(int)(n-1); i>=m; i--)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) RREP(i,0,n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define aut(r,v) __typeof(v) r = (v)
#define each(it,o) for(aut(it,(o).begin()); it!=(o).end(); ++it)
#define reach(it,o) for(aut(it,(o).rbegin()); it!=(o).rend(); ++it)
#define fi first
#define se second
#define debug(...) {cerr<<"[L"<<__LINE__<<"] "; _debug(__VA_ARGS__);}

template<typename T1, typename T2> ostream& operator<<(ostream& o, const pair<T1, T2>& p)
{return o<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>string join(const vector<T>&v, string del=", ")
{stringstream s;rep(i,v.size())s<<del<<v[i];return s.str().substr(del.size());}
template<typename T>ostream& operator<<(ostream& o, const vector<T>&v)
{if(v.size())o<<"["<<join(v)<<"]";return o;}
template<typename T>ostream& operator<<(ostream& o, const vector<vector<T> >&vv)
{int l=vv.size();if(l){o<<endl;rep(i,l){o<<(i==0?"[ ":",\n  ")<<vv[i]<<(i==l-1?" ]":"");}}return o;}
template<typename T>ostream& operator<<(ostream& o, const set<T>& st)
{vector<T> v(st.begin(),st.end());o<<"{ "<<join(v)<<" }";return o;}
template<typename T1, typename T2>ostream& operator<<(ostream& o, const map<T1, T2>& m)
{each(p,m){o<<(p==m.begin()?"{ ":",\n  ")<<*p<<(p==--m.end()?" }":"");}return o;}
inline void _debug(){cerr<<endl;}
template<class First, class... Rest>
void _debug(const First& first, const Rest&... rest){cerr<<first<<" ";_debug(rest...);}

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

const double PI = (1*acos(0.0));
const double EPS = 1e-9;
const ll INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll mod = 1e9 + 7;

inline void finput(string filename) {
    freopen(filename.c_str(), "r", stdin);
}

ll dp[10010][110][2];

int main(){
    ios_base::sync_with_stdio(0);
    // finput("./input");

    string s; cin >> s;
    int D; cin >> D;
    int k = s.length();

    dp[0][0][0] = 1ll;
    rep(i,k) rep(d,D) rep(isless,2) {
        int c = s[i] - '0';
        rep(j,10){
            int dj = (d + j) % D;
            if(j < c)
                dp[i+1][dj][1] += dp[i][d][isless];
            else if(j == c)
                dp[i+1][dj][isless] += dp[i][d][isless];
            else{
                if(isless) dp[i+1][dj][isless] += dp[i][d][isless];
            }
            dp[i+1][dj][0] %= mod;
            dp[i+1][dj][1] %= mod;
        }
    }
    cout << (dp[k][0][0] + dp[k][0][1] - 1 + mod) % mod << endl;
    return 0;
}