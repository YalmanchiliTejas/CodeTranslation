#include <bits/stdc++.h>
using namespace std;
// #define int long long
using ll=long long;
using vi=vector<int>;
using vl=vector<long long>;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define ITR(v,c) for(auto v=begin(c);v!=end(c);v++)
#define FORE(x,c) for(auto &x:c)
#define FOR(v,a,n) for(int v=a;v<(int)(n);v++)
#define REP(v,n) FOR(v,0,n)
#define RREP(v,n) for(int v=((int)(n)-1);v>=0;v--)
#define ALL(c) begin(c),end(c)
#define RALL(c) rbegin(c),rend(c)
#define SZ(c) ((int)c.size())
const int DX[9]={0,1,0,-1,1,1,-1,-1,0}, DY[9]={-1,0,1,0,-1,1,1,-1,0};
const int INF=1e9; const long long INFLL=1e18;
template<class T> ostream& operator << (ostream &os, const vector<T> &v) {
    ITR(i,v) os<<*i<<(i==end(v)-1?"":" "); return os; }
template<class T> istream& operator >> (istream &is, vector<T> &v) {
    ITR(i,v) is>>*i; return is; }
//------------------------------------------------------------------------------

signed main() {
    int  h,w;
    int cnt=0;
    cin>>h>>w;
    vector<string> a(h),b;
    REP(i,h) {
        cin>>a[i];
        REP(j,w) {
            if(a[i][j]=='#') cnt++;
        }
    }
    b=a;

    queue<pii> q;
    cnt--;
    q.push({0,0});
    a[0][0]='.';
    while(!q.empty()) {
        int y=q.front().first;
        int x=q.front().second;
        q.pop();

        if(x<w-1 && a[y][x+1]!='.') {
            if(a[y][x+1]=='#') cnt--;
            a[y][x+1]='.';
            q.push({y,x+1});
        }
        else if(y<h-1 && a[y+1][x]!='.') {
            if(a[y+1][x]=='#') cnt--;
            a[y+1][x]='.';
            q.push({y+1,x});
        }
    }
    if(cnt==0) {
        cout<<"Possible"<<endl;
    }
    else cout<<"Impossible"<<endl;
    return 0;
}
