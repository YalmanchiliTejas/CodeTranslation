#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
using vi=vector<int>;
using vl=vector<long long>;
using pii=pair<int,int>;
using pll=pair<long long,long long>;
#define ITR(i,c) for(auto i=begin(c);i!=end(c);++i)
#define FORE(x,c) for(auto &x:c)
#define REPF(i,a,n) for(int i=a,i##_len=(int)(n);i<i##_len;++i)
#define REP(i,n) REPF(i,0,n)
#define REPR(i,n) for(int i=(int)(n);i>=0;--i)
#define REPW(i,n) for(i=0;i<(int)(n);++i)
#define ALL(c) begin(c),end(c)
#define RALL(c) rbegin(c),rend(c)   // c++14
#define SZ(c) ((int)c.size())
#define EXIST(c,x) (c.find(x)!=end(c))
#define OUTOFRANGE(y,x,h,w) (y<0||x<0||y>=h||x>=w)
#define dump(...)
const int DX[9]={0,1,0,-1,1,1,-1,-1,0},DY[9]={-1,0,1,0,-1,1,1,-1,0};
#define INF (1001001001)
#define INFLL (1001001001001001001ll)
template<class T> ostream& operator << (ostream &os,const vector<T> &v) {
    ITR(i,v) os << *i << (i==end(v)-1 ? "" : " "); return os; }
template<class T> istream& operator >> (istream &is,vector<T> &v) {
    ITR(i,v) is >> * i; return is; }
template<class T> istream& operator >> (istream &is, pair<T,T> &p) {
        is >> p.first >> p.second; return is; }
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
//------------------------------------------------------------------------------
struct before_main_function {
    before_main_function() {
        #ifdef int
            #undef INF
            #define INF INFLL
            #define stoi stoll
        #endif
        cin.tie(0);ios::sync_with_stdio(false);
        cout<<setprecision(15)<<fixed;
    }
} before_main_function;
//------------------------------------------------------------------------------

int n;
string s;
bool hoge(string &t) {
    REPF(i,1,n-1) {
        if((t[i]=='S' && s[i]=='o') || (t[i]=='W' && s[i]=='x')) {
            t+=t[i-1];
        }
        else {
            t+=(t[i-1]=='S'?'W':'S');
        }
    }
    if((t[0]=='S' && s[0]=='o') || (t[0]=='W' && s[0]=='x')) {
        if(t[1]!=t[n-1]) {
            return false;
        }
    }
    else {
        if(t[1]==t[n-1]) {
            return false;
        }
    }
    if((t[n-1]=='S' && s[n-1]=='o') || (t[n-1]=='W' && s[n-1]=='x')) {
        if(t[n-2]!=t[0]) {
            return false;
        }
    }
    else {
        if(t[n-2]==t[0]) {
            return false;
        }
    }
    return true;
}
signed main() {
    cin>>n;
    cin>>s;
    vector<string> t={"SS","SW","WS","WW"};
    REP(i,4) {
        if(hoge(t[i])) {
            cout<<t[i]<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
