#include <bits/stdc++.h>
using namespace std;
#define int long long
#define stoi stoll
using pii=pair<int,int>;
#define all(c) begin(c),end(c)
#define rall(c) rbegin(c),rend(c)
#define fore(x,c) for(auto &&x:c)
#define rep(i,a,n) for(int i=a,i##len=(int)(n);i<i##len;++i)
#define rrep(i,n) for(int i=(int)(n);i>=0;--i)
#define sz(c) ((int)c.size())
#define contains(c,x) (c.find(x)!=end(c))
#define inseg(l,x,r) ((l)<=(x)&&(x)<(r))
#define dump(...)
#define pb push_back
#define _ 0
const signed INF_=1001001001; const long long INF=1001001001001001001LL;
const int DX[9]={0,1,0,-1,1,1,-1,-1,0},DY[9]={-1,0,1,0,-1,1,1,-1,0};
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) {
    for (auto i = begin(v); i != end(v); i++) os<<*i<<(i==end(v)-1?"":" ");return os;}
template<class T> istream& operator>>(istream &is,vector<T> &v) {
    for (auto i = begin(v); i != end(v); i++) is>>*i;return is;}
template<class T,class U> istream& operator>>(istream &is, pair<T,U> &p) {
    is>>p.first>>p.second;return is;}
template<class T, class U> bool chmax(T &a,const U &b){return a<b?a=b,1:0;}
template<class T, class U> bool chmin(T &a,const U &b){return a>b?a=b,1:0;}
template <class T> void psum(T& c) {partial_sum(begin(c), end(c), begin(c));}
template<class T> using heap=priority_queue<T,vector<T>,greater<T>>;
struct before_main_function {
    before_main_function() {
        cin.tie(0); ios::sync_with_stdio(0);
        cout << setprecision(15) << fixed;
        // #define endl "\n"
    }
} before_main_function;
//------------------8<------------------------------------8<--------------------
 
signed main() {
    int n;
    cin >> n;
    vector<int> h(n);
    cin >> h;
    int max=0, cnt=0;
		for (auto temp: h) {
      if (max <= temp) {
        max = temp;
        cnt++;
      }
    }
		cout << cnt << endl;
    return 0;
}
