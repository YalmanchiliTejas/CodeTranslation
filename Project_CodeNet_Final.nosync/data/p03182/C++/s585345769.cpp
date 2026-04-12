#include <iostream>
#include <map>
using namespace std;

class SegTree {
    using T = long long int;
    static const T& op(const T& lhs, const T& rhs) { // binary operator
        return max(lhs, rhs);
    }
    constexpr static T unit = -1LL<<60; // unit element
    const int N;
    T *data, *delay;
    int calc_size(int n) { int ret = 1; while (n > ret) ret *= 2; return ret; }
    void force(int i, int l, int r) {
        if (delay[i]) {
            data[i] += delay[i];
            if (r - l > 1) {
                delay[2*i+1] += delay[i];
                delay[2*i+2] += delay[i];
            }
            delay[i] = 0;
        }
    }
public:
    explicit SegTree(int n) : N(calc_size(n)) {   // [0, n-1]
        data = new T[2*N-1];
        delay = new T[2*N-1];
    }
    ~SegTree() { delete[] data, delay; }
    T query(int a, int b, int i = -1, int l = -1, int r = -1) {
        if (i == -1) { i = 0; l = 0; r = N; }
        if (r <= a || b <= l) return unit;
        force(i, l, r);
        if (a <= l && r <= b) return data[i];
        T v1 = query(a, b, 2*i+1, l, (l+r)/2),
            v2 = query(a, b, 2*i+2, (l+r)/2, r);
        return op(v1, v2);
    }
    void update(int i, T v) {
        int x = i + N - 1;
        data[x] = v;
        while (x > 0) {
            x = (x-1)/2;
            data[x] = op(data[2*x+1], data[2*x+2]);
        }
    }
    void add(int a, int b, T v, int i = -1, int l = -1, int r = -1) {
        if (i == -1) { i = 0; l = 0; r = N; }
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) { delay[i] += v; force(i, l, r); return; }
        add(a, b, v, 2*i+1, l, (l+r)/2); force(2*i+1, l, (l+r)/2);
        add(a, b, v, 2*i+2, (l+r)/2, r); force(2*i+2, (l+r)/2, r);
        data[i] = op(data[2*i+1], data[2*i+2]);
    }
    void dump() {
        cerr << "data "; for (int i = 0; i < 2*N-1; i++) cerr << ' ' << data[i]; cerr << endl;
        cerr << "delay "; for (int i = 0; i < 2*N-1; i++) cerr << ' ' << delay[i]; cerr << endl;
    }
};

int main() {
    int n, m; cin >> n >> m;
    map<int, long long> intervals[200100];
    for (int i = 0; i < m; i++) {
        int l, r, a; cin >> l >> r >> a;
        intervals[r][l] += a;
    }
    SegTree st(n+1);
    for (int r = 1; r <= n; r++) {
        const long long prev_max = st.query(0, r);
        long long sum = 0;
        int previdx = 1;
        for (auto &x : intervals[r]) {
            st.add(previdx, x.first, sum);
            previdx = x.first;
            sum += x.second;
        }
        st.add(previdx, r, sum);
        st.update(r, sum + prev_max);
    }
    cout << st.query(0, n+1) << endl;
}
