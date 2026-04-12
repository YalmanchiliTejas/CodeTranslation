#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

const ll mod = 1000000007;

template<typename T>
static inline void chmin(T & ref, const T  value) {
	if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
	if (ref < value) ref = value;
}

//遅延セグメントツリー
template <typename X, typename M>
struct SegTreeLazyProportional {
    using FX = function<X(X, X)>;
    using FA = function<X(X, M)>;
    using FM = function<M(M, M)>;
    using FP = function<M(M, int)>;
private:
    int n;
    FX query_Value_;
    FA merge_data_and_lazy_;
    //遅延評価するときに子に伝番させる方法
    FM updateLazy_;
    //遅延評価値と長さから何をするか決める
    FP evaluateLazyLength_;
    //無効値
    const X defaultData_;
    vector<X> data_;
    //無効値
    const M defaultLazy_;
    vector<M> lazy_;
public:
    SegTreeLazyProportional(int n_, FX query_value, FA merge_data_and_lazy, FM updateLazy, FP evaluateLazyLength, X defaultData, M defaultLazy)
        : n(), query_Value_(query_value), merge_data_and_lazy_(merge_data_and_lazy),
        updateLazy_(updateLazy),
        evaluateLazyLength_(evaluateLazyLength),
        defaultData_(defaultData),
        defaultLazy_(defaultLazy),
        data_(n_ * 4, defaultData_), lazy_(n_ * 4, defaultLazy_) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }

    void set(int i, X x) { data_[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--) data_[k] = query_Value_(data_[2 * k + 1], data_[2 * k + 2]);
    }
    //[a,b)
    void update(int a, int b, M x) { update(a, b, x, 0, 0, n); }
    //[a,b)
    X query(int a, int b) { return query_sub(a, b, 0, 0, n); }

private:
    void eval(int k, int len) {
        if (lazy_[k] == defaultLazy_) return;  // 更新するものが無ければ終了
        if (k < n - 1) {            // 葉でなければ子に伝搬
            lazy_[k * 2 + 1] = updateLazy_(lazy_[k * 2 + 1], lazy_[k]);
            lazy_[k * 2 + 2] = updateLazy_(lazy_[k * 2 + 2], lazy_[k]);
        }
        // 自身を更新
        data_[k] = merge_data_and_lazy_(data_[k], evaluateLazyLength_(lazy_[k], len));
        lazy_[k] = defaultLazy_;
    }

    void update(int a, int b, M x, int k, int l, int r) {
        eval(k, r - l);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy_[k] = updateLazy_(lazy_[k], x);
            eval(k, r - l);
        }
        else if (a < r && l < b) {                     // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            data_[k] = query_Value_(data_[k * 2 + 1], data_[k * 2 + 2]);
        }
    }

    X query_sub(int a, int b, int k, int l, int r) {
        eval(k, r - l);
        if (r <= a || b <= l) {  // 完全に外側の時
            return defaultData_;
        }
        else if (a <= l && r <= b) {  // 完全に内側の時
            return data_[k];
        }
        else {  // 一部区間が被る時
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return query_Value_(vl, vr);
        }
    }
};

SegTreeLazyProportional<ll, ll> RangeAdd1(int n) {
    auto queryValue = [=](ll left, ll right) -> ll { return max(left, right); };
    auto updateValue = [=](ll old, ll next) -> ll { return old + next; };
    auto merge = [=](ll source, ll lazyValue) -> ll { return source + lazyValue; };
    auto evaluate_lazy_length = [=](ll lazyValue, ll length) -> ll { return lazyValue ; };
    ll defaultValue_ = 0;
    SegTreeLazyProportional<ll, ll> rmq(n, queryValue, merge, updateValue, evaluate_lazy_length, defaultValue_, defaultValue_);
    return rmq;
}

int main() {
	ll n, m;
	cin >> n >> m;
    auto dp = RangeAdd1(n);
    vector<vector<P>> vs(n);
    rep(i, m) {
        ll a, b, p;
        cin >> a >> b >> p;
        a--; b--;
        vs[b].emplace_back(a, p);
	}
    //dp1[i][j]...i番目までみて、最後の要素がjの場合の最大値
    //vector<vector<ll>> dp1(n, vector<ll>(n, 0));
    //for (int i = 0; i < n; i++) {
    //    ll pmax = 0;
    //    if (i > 0) {
    //        dp1[i] = dp1[i - 1];
    //        for (int j = 0; j < i; j++) {
    //            pmax = max(pmax, dp1[i][j]);
    //        }
    //    }
    //    if (vs[i].size()) {
    //        dp1[i][i] = pmax;
    //        for (auto p : vs[i]) {
    //            for (int j = p.first; j <= i; j++) {
    //                dp1[i][j] += p.second;
    //            }
    //        }
    //    }
    //}
    //for (int i = 0; i < n; i++) {
    //    cout << i << "," << dp1[n-1][i]<< endl;
    //}
    //return 0;

    for (int i = 0; i < n; i++) {
        ll prev = 0;
        if (i > 0) {
            ll u = dp.query(0, i);
            prev = max(u, prev);
        }
        dp.update(i, i+1, prev);
        for (auto p : vs[i]) {
            dp.update(p.first, i+1, p.second);
        }
    }
    //rep(i, n) {
    //    cout << i << "," << dp.query(i, i+1) << endl;
    //}
    cout << max(0LL, dp.query(0, n)) << endl;
	return 0;
}
