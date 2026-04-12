#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i=0; i<int(n); i++)
#define RNG(i, f, t) for(int i=int(f); i<=int(t); i++)
#define REV(i, f, t) for(int i=int(f); i>=int(t); --i)
#define ALL(v) (v).begin(), (v).end()
bool RELAXED = false;
template<int,typename T> struct MINMAX{ T val; MINMAX(T val) : val(val) {} };
template<typename T> MINMAX<1,T> MAX(T val) { return MINMAX<1,T>(val); };
template<typename T> MINMAX<2,T> MIN(T val) { return MINMAX<2,T>(val); };
template<typename T, typename U> inline T& operator|=(T &lhs, MINMAX<1,U> rhs) { return lhs = (rhs.val > lhs ? (RELAXED=true,rhs.val) : (RELAXED=false,lhs)); }
template<typename T, typename U> inline T& operator|=(T &lhs, MINMAX<2,U> rhs) { return lhs = (rhs.val < lhs ? (RELAXED=true,rhs.val) : (RELAXED=false,lhs)); }
template<typename T> inline vector<T> readVector(int n) { vector<T> vec(n); FOR(i,n) cin>>vec[i]; return vec; }
template<typename T> void PRINT(T container, bool withSize) { if(withSize) cout<<container.size()<<endl; for(auto it : container) cout<<it<<" "; cout<<endl; }
template<typename T> void EXIT(T answer) { cout<<answer<<endl; exit(0); }
typedef signed long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

struct SegTree {
#define IS_LEAF(id) (id>=N)
#define LC (ID<<1)
#define RC (ID<<1|1)
    static const ll INF = 1e18;
    static const int H = 20; //TODO
    static const int N = 1<<H;
    ll t[2*N]={0};
    ll lazy[N]={0};

private:
    void update(int ID) {
        t[ID] = max(t[LC], t[RC]) + lazy[ID];
    }

    void propagate(int ID) {
        if(IS_LEAF(ID) || lazy[ID]==0) return;
        if(!IS_LEAF(LC)) {
            lazy[LC] += lazy[ID];
            lazy[RC] += lazy[ID];
        }
        t[LC] += lazy[ID];
        t[RC] += lazy[ID];
        lazy[ID] = 0;
    }

public:
    void incrementRange(int from, int to, ll val, int ID=1, int L=0, int R=N-1) {
        if(from<=L && to>=R) {
            if(!IS_LEAF(ID)) lazy[ID] += val;
            t[ID] += val;
            return;
        }
        propagate(ID);
        int mid = L+R>>1;
        if(from<=mid) incrementRange(from, to, val, LC, L, mid);
        if(to>mid) incrementRange(from, to, val, RC, mid+1, R);
        update(ID);
    }

    ll getPoint(int pos, int ID=1, int L=0, int R=N-1) {
        if(L==R)
            return t[ID];
        propagate(ID);
        int mid = L+R>>1;
        if(pos<=mid)
            return getPoint(pos, LC, L, mid);
        return getPoint(pos, RC, mid+1, R);
    }

    void setPoint(int pos, ll val, int ID=1, int L=0, int R=N-1) {
        if(L==R) {
            t[ID]=val;
            return;
        }
        propagate(ID);
        int mid = L+(R-L)/2;
        if(pos<=mid)
            setPoint(pos, val, ID*2, L, mid);
        else
            setPoint(pos, val, ID*2+1, mid+1, R);
        update(ID);
    }

    ll queryMax(int from, int to, int ID=1, int L=0, int R=N-1) {
        if(from<=L && to>=R)
            return t[ID];
        propagate(ID);
        ll res=-INF;
        int mid = L+(R-L)/2;
        if(from<=mid)
            res |= MAX(queryMax(from, to, ID*2, L, mid) );
        if(to>mid)
            res |= MAX(queryMax(from, to, ID*2+1, mid+1, R) );
        return res;
    }
};
SegTree st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n,m; cin>>n>>m;
    map<int,ll> open;
    map<int,vpii> close;
    FOR(i,m) {
        int l,r,val; cin>>l>>r>>val;
        open[l] += val;
        close[r].push_back(pii(l, val));
    }

    RNG(i,1,n) {
        st.incrementRange(0, i-1, open[i]);

        ll mmax = st.queryMax(0, i-1);
        st.setPoint(i, mmax);

        for(auto p : close[i]) {
            st.incrementRange(0, p.first-1, -1*p.second);
        }
    }

    cout<<st.queryMax(0, n)<<endl;

    return 0;
}
