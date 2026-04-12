#include <bits/stdc++.h>
using namespace std;
#define int long long
#define stoi stoll
using pii=pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(c) begin(c),end(c)
#define rall(c) rbegin(c),rend(c)
#define fore(x,c) for(auto &&x:c)
#define rep(i,a,n) for(int i=a,i##len=(int)(n);i<i##len;++i)
#define rrep(i, a, n) for(int i=(int)(n-1);i>=a;--i)
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
        cin.tie(nullptr); ios::sync_with_stdio(0);
        cout << setprecision(15) << fixed;
        // #define endl "\n"
    }
} before_main_function;
//------------------8<------------------------------------8<--------------------

int ask(int u, int v) {
    cout << "? " << u + 1 << " " << v + 1 << endl;
    int ret;
    cin >> ret;
    return ret;
}
void answer(vi path) {
    cout << "! ";
    rep(i, 0, sz(path)) {
        if (i != 0) cout << " ";
        cout << path[i] + 1;
    }
    cout << endl;
}
signed main() {
    int N, S, T;
    cin >> N >> S >> T;
    S--, T--;

    vi dS(N), dT(N);
    rep(i, 0, N) {
        dS[i] = ask(S, i);
        dT[i] = ask(T, i);
    }

    vector<pii> vs;
    rep(i, 0, N) {
        if (dS[i] + dT[i] == dS[T]) {
            vs.push_back({dS[i], i});
        }
    }
    sort(all(vs));

    dump(vs);

    assert(vs.front() == pii(0, S));
    vi path;
    path.push_back(S);
    int dist = 0;
    rep(i, 1, sz(vs)) {
        int v = vs[i].second;
        int tmp = ask(path.back(), v);
        if (dist + tmp + dT[v] == dS[T]) {
            path.push_back(v);
            dist += tmp;
        }
    }

    answer(path);
    return (0^_^0);
}


