#include <bits/stdc++.h>
using namespace std;
/*{{{*/  //template
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
constexpr int INF = numeric_limits<int>::max()/2;
constexpr long long LINF = numeric_limits<long long>::max()/3;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<":"<<x<<endl
#define debug2(x,y) cerr<<#x<<","<<#y":"<<x<<","<<y<<endl
//struct fin{ fin(){ cin.tie(0); ios::sync_with_stdio(false); } } fin_;
struct Double{ double d; explicit Double(double x) : d(x){} };
ostream& operator<<(ostream& os,const Double x){ os << fixed << setprecision(20) << x.d; return os; }
template<typename T> ostream& operator<<(ostream& os,const vector<T>& vec){ os << "["; for(const auto& v : vec){ os << v << ","; } os << "]"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os, const map<T,U>& mp){ os << "{"; for(auto& p : mp){ os << p << ","; } os << "}"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os,const pair<T,U>& p){ os << "(" << p.first << ","<< p.second <<")"; return os; }
template<typename T> ostream& operator<<(ostream& os,const set<T>& st){ os<<"{"; for(T v:st) os<<v<<","; os <<"}"; return os; }
template<typename T,typename U> inline void chmax(T &x,U y){ if(y>x) x = y; }
template<typename T,typename U> inline void chmin(T &x,U y){ if(y<x) x = y; }
using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int,int>;
using vi = std::vector<int>;
typedef vector<vi> vvi;
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b); }
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
//constexpr double eps = 1e-14; 
constexpr double eps = 1e-10; 
constexpr ll mod = 1e9+7;
const int dx[]={1,0,-1,0} ,dy[] = {0,1,0,-1};
/*}}}*/

class disjoint_set {
    vector<int> p;
public:
    int count;
    disjoint_set(int n) : p(n, -1), count(0) {}
    int root(int i) { return p[i] >= 0 ? p[i] = root(p[i]) : i; }
    bool same(int i, int j) { return root(i) == root(j); }
    int size(int i) { return -p[root(i)]; }
    void merge(int i, int j) {
        count++;
        i = root(i), j = root(j);
        if (i == j) return;
        if (p[i] > p[j]) swap(i, j);
        p[i] += p[j], p[j] = i;
    }
    int size(int i, int j) {
        if(same(i,j)) return size(i);
        else return size(i) + size(j);
    }
};

int main(){
    int n; cin >> n;
    using P = pair<int,long>;
    vector<P> h,w;
    rep(i,n){
        int x,y; cin >> x >> y;
        x--;y--;
        h.emplace_back(x,i);
        w.emplace_back(y,i);
    }
    sort(all(h));
    sort(all(w));

    /* cerr << "h : " << h << endl; */
    /* cerr << "w : " << w << endl; */
    using T = tuple<int,int,int>;
    vector<T> h2,w2;
    rep(i,n-1){
        h2.emplace_back(h[i+1].first-h[i].first, h[i].second, h[i+1].second);
        w2.emplace_back(w[i+1].first-w[i].first, w[i].second, w[i+1].second);
    }
    sort(all(h2));
    sort(all(w2));
    int m = h2.size();

    disjoint_set uf(n);
    ll ans = 0;
    int i=0,j=0;
    while(i < m && j < m){
        ll H = LINF;
        ll W = LINF;

        if(i<m){
            int l,x,y;
            tie(l,x,y) = h2[i];
            while(i<m && uf.same(x,y)){
                i++;
                if(i==m) break;
                tie(l,x,y) = h2[i];
            }
            if(i<m){
                tie(l,x,y) = h2[i];
                H = l;
            }
        }
        if(j<m){
            int l,x,y;
            tie(l,x,y) = w2[j];
            while(j<m && uf.same(x,y)){
                j++;
                if(j==m) break;
                tie(l,x,y) = w2[j];
            }
            if(j<m){
                tie(l,x,y) = w2[j];
                W = l;
            }
        }

        if(H == LINF && W == LINF){
            break;
        }

        int l,x,y;
        if(H < W){
            tie(l,x,y) = h2[i];
            ans += l;
            uf.merge(x,y);
        }else{
            tie(l,x,y) = w2[j];
            ans += l;
            uf.merge(x,y);
        }
    }
    cout << ans << endl;
}
