#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef vector<vector<long long>> VVL;
typedef pair<int,int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define EXIST(m,v) (m).find((v)) != (m).end()
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

constexpr double EPS = 1e-9;
constexpr double PI  = 3.1415926535897932;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007; // 998244353;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<typename T, typename E>
struct SegmentTree {
	typedef function<T(T,T)> F;
    typedef function<T(T,E)> G;
    int n;
    F f;
    G g;
    T e;

    vector<T> val;

    SegmentTree(vector<T> a, F f_, G g_, T e):
        f(f_), g(g_), e(e){
            int sz = a.size();
            n = 1;

            while (n < sz) n <<= 1;
            val.resize(2*n-1, e);
            for (int i=0; i<sz; i++) val[i+n-1] = a[i];
            for (int i=n-2; i>=0; i--) val[i] = f(val[i*2+1], val[i*2+2]);
        }
    
        SegmentTree() {}

        void update(int pos, E v) {
            // 0-indexed
            int k = pos + n-1;
            val[k] = g(val[k], v);
            while (k > 0) {
                k = (k-1) / 2;
                val[k] = f(val[k*2+1], val[k*2+2]);
            }
        }

        T get(int pos) {
            // 0-indexed
            int k = pos + n-1;
            return val[k];
        }

        T query(int a, int b, int k = 0, int l = 0, int r = -1) {
            // 0-indexed
            // [a,b)に対してquery
            if (r < 0) r = n;
            if (r <= a || b <= l) return e;
            if (a <= l && r <= b) return val[k];
            T lv = query(a, b, k*2+1, l, (l+r)/2);
            T rv = query(a, b, k*2+2, (l+r)/2, r);
            return f(lv, rv);
        }

        int findL(int a, int b, const function<bool(T)>& check, int k=0, int l=0, int r=-1){
            // 0-indexed
            // [a,b)でf(val[k])がtrueとなるような最小のkを返す 無ければ-1を返す
            // a      k         b
            // xxxxxxxoooooooooo

            if(r<0) r = n;
            if(!check(val[k]) || (r<=a || b<=l)) return -1;
            if(r-l == 1) return l;

            int lv = findL(a, b, check, 2*k+1, l, (l+r)/2);
            if(lv != -1) return lv;

            int rv = findL(a, b, check, 2*k+2, (l+r)/2, r);
            return rv;
        }

        int findR(int a, int b, const function<bool(T)>& check, int k=0, int l=0, int r=-1){
            // 0-indexed
            // [a,b)でf(val[k])がtrueとなるような最大のkを返す 無ければ-1を返す
            // a      k         b
            // ooooooooxxxxxxxxx

            if(r<0) r = n;
            if(!check(val[k]) || (r<=a || b<=l)) return -1;
            if(r-l == 1) return l;

            int rv = findR(a, b, check, 2*k+2, (l+r)/2, r);
            if(rv != -1) return rv;

            int lv = findR(a, b, check, 2*k+1, l, (l+r)/2);
            return lv;
        }
};

int f(int a, int b){return max(a,b);}
int g(int a, int b){return b;}

void Main(){
    int N,Q; cin >> N >> Q;
    VI A(N); REP(i,N) cin >> A[i];

    int V = 0;
    auto check = [&](int v){
        return V<=v;
    };

    SegmentTree<int,int> st(A,f,g,0);
    REP(_,Q){
        int t; cin >> t;
        if(t == 1){
            int x,v; cin >> x >> v; x--;
            st.update(x,v);
        }
        else if(t == 2){
            int l,r; cin >> l >> r; l--;
            int ans = st.query(l,r);
            cout << ans << en;
        }
        else{
            int x,v; cin >> x >> v; x--; V = v;
            int ans = st.findL(x,N,check) + 1;
            cout << (ans>0 ? ans : N+1) << en;
        }
    }
    return;
}

int main(void){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);cout<<fixed<<setprecision(15);
    int t=1; //cin>>t;
    REP(_,t) Main();
    return 0;
}