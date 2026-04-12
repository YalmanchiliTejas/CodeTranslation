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
#define FOR(i,a,n) for(int i=a,i##_len=(int)n;i<i##_len;++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i=((int)(n)-1);i>=0;--i)
#define ALL(c) begin(c),end(c)
#define RALL(c) rbegin(c),rend(c)
#define SZ(c) ((int)c.size())
#define dump(...)
const int DX[9]={0,1,0,-1,1,1,-1,-1,0}, DY[9]={-1,0,1,0,-1,1,1,-1,0};
const int INF=1e9*2; const long long INFLL=1e18*2;
template<class T> ostream& operator << (ostream &os, const vector<T> &v) {
    ITR(i,v) os << *i << (i==end(v)-1 ? "" : " "); return os; }
template<class T> istream& operator >> (istream &is, vector<T> &v) {
    ITR(i,v) is >> * i; return is; }
template<class T> istream& operator >> (istream &is, pair<T,T> &p) {
        is >> p.second >> p.first; return is; }
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
//------------------------------------------------------------------------------

signed main() {
    string s;
    cin>>s;
    string boin="aeiou";
    bool f=false;
    FORE(x,boin) {
        if(s[0]==x) f=true;
    }
    cout<<(f?"vowel":"consonant")<<endl;
    return 0;
}
