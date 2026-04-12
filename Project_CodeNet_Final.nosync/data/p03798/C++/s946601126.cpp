#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<cmath>
#include<cstdio>
#include<cassert>
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
#define dump(x) cerr << " [L" << __LINE__ << "] " << #x << " = " << (x) << endl;

template<typename T>string join(vector<T>&v, string del=", ")
{stringstream s;rep(i,v.size())s<<del<<v[i];return s.str().substr(del.size());}
template<typename T1, typename T2> ostream& operator<<(ostream& o, const pair<T1, T2>& p)
{return o<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream& operator<<(ostream& o, vector<T>&v)
{if(v.size())o<<"["<<join(v)<<"]";return o;}
template<typename T>ostream& operator<<(ostream& o, vector<vector<T> >&vv)
{int l=vv.size();if(l){rep(i,l){o<<(i==0?"[ ":",\n  ")<<vv[i]<<(i==l-1?" ]":"");}}return o;}
template<typename T>ostream& operator<<(ostream& o, const set<T>& st)
{vector<T> v(st.begin(),st.end());o<<"{ "<<join(v)<<" }";return o;}
template<typename T1, typename T2>ostream& operator<<(ostream& o, const map<T1, T2>& m)
{each(p,m){o<<(p==m.begin()?"{ ":",\n  ")<<*p<<(p==--m.end()?" }":"");}return o;}

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

const double PI = (1*acos(0.0)); 
const double INF = 0x3f3f3f3f;
const double INFL = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;
const double mod = 1e9 + 7;

inline void finput(string filename) {
    freopen(filename.c_str(), "r", stdin);
}

int N;
vi a, b;

int check(int cur, int pre){
    a[0] = pre; a[1] = cur;
    REP(i, 2, N+1) a[i] = a[i-2] ^ a[i-1] ^ b[i-1];
    a[N+1] = a[1]; a[0] = a[N];
    return !(a[0]^a[1]^b[1]^a[2] || a[N-1]^a[N]^b[N]^a[N+1]);
}

int main(){
    ios_base::sync_with_stdio(0);
    // finput("./input");

    cin >> N;
    string s;
    cin >> s;

    a = b = vi(N+2);
    rep(i, N) b[i+1] = (s[i] == 'o' ? 0 : 1);
    int found = 0;
    if(check(0,0)||check(1,0)||check(0,1)||check(1,1)) found = 1;
    if(!found){
        cout << -1;
    }else{
        REP(i, 1, N+1) cout << ((a[i]==0) ? "S" : "W");
    }
    cout << endl;
    return 0;
}
