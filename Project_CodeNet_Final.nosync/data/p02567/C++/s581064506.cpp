#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
struct INF { template<class T> operator T() { return numeric_limits<T>::max() / 2; } } INF;


template<class T>
struct SegmentTree { // セグメント木

    const T INF = numeric_limits<T>::max();

    int n;
    int size;
    vector<T> mins, maxs;

    SegmentTree(int _n) {
        n = 1;
        size = _n;
        while(n < _n) n *= 2;
        mins.assign(n*2,INF);
        maxs.assign(n*2,-INF);
    }

    void update(int k, T a) { // val[k] = a;
        k += n-1;
        maxs[k] = mins[k] = a;
        while(k > 0) {
            k = (k-1) / 2;
            mins[k] = min(mins[k*2+1], mins[k*2+2]);
            maxs[k] = max(maxs[k*2+1], maxs[k*2+2]);
        }
    }

    T Min(int l, int r) { // 閉区間 [l,r] の最小値
        return _min(l, r+1, 0, 0, n);
    }
    T _min(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) return mins[k];
        else {
            T vl = _min(a, b, k*2+1, l, (l+r)/2);
            T vr = _min(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }

    T Max(int l, int r) { // 閉区間 [l,r] の最大値
        return _max(l, r+1, 0, 0, n);
    }
    T _max(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return -INF;
        if(a <= l && r <= b) return maxs[k];
        else {
            T vl = _max(a, b, k*2+1, l, (l+r)/2);
            T vr = _max(a, b, k*2+2, (l+r)/2, r);
            return max(vl, vr);
        }
    }

    // 閉区間 [l,r] で x 以上の数が最初に現れるインデックスを返す
    // 無ければ一番後ろ (= r) を返す
    int lower_bound(int l, int r, T x) {
        while(abs(l-r) > 0) {
            int mid = (l+r) / 2;
            if(Max(l,mid) >= x) r = mid;
            else l = mid+1;
        }
        return Max(r,r) >= x ? l : r+1;
    }
};


int main(){

    int n, q;
    cin >> n >> q;

    SegmentTree<int> st(n);

    rep(i,n) {
        int a;
        cin >> a;
        st.update(i,a);
    }

    rep(i,q) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            a--;
            st.update(a,b);
        }
        if(t == 2) {
            a--; b--;
            cout << st.Max(a,b) << endl;
        }
        if(t == 3) {
            a--;
            cout << st.lower_bound(a,n-1,b) + 1 << endl;
        }
    }
}