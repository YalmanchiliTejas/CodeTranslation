#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()

using namespace std;

unsigned long long clp(unsigned long long x) {
    x -= 1;
    x = x | (x >>  1);
    x = x | (x >>  2);
    x = x | (x >>  4);
    x = x | (x >>  8);
    x = x | (x >> 16);
    x = x | (x >> 32);
    return x + 1;
}

template <class T>
class segment_tree {
private:
    const size_t n;
    const std::function<T(const T&, const T&)> f;
    const T UNIT;
    std::vector<T> a;
public:
    segment_tree(size_t size, std::function<T(const T&, const T&)> f, T UNIT) : n(clp(size)), UNIT(UNIT), f(f) {
        a.resize(2 * n - 1, UNIT);
    }

    template <class Iterator>
    segment_tree(Iterator first, Iterator last, std::function<T(const T&, const T&)> f, T UNIT) : n(clp(std::distance(first, last))), f(f), UNIT(UNIT) {
        size_t size = std::distance(first, last);
        a.resize(2 * n - 1, UNIT);
        for (size_t i = n - 1; first != last; ++i) {
            a[i] = *(first++);
        }
        for (int i = n - 2; i >= 0; --i) {
            a[i] = f(a[2 * i + 1], a[2 * i + 2]);
        }
    }

    void update(size_t i, const T &x) {
        i += n - 1;
        a[i] = x;
        while (i) {
            i = (i - 1) / 2;
            a[i] = f(a[2 * i + 1], a[2 * i + 2]);
        }
    }

    T query(size_t query_first, size_t query_last, size_t k = 0, size_t node_first = 0, size_t node_last = 0) const {
        if (k == 0) {
            node_last = n;
        }
        if (node_last <= query_first || query_last <= node_first) {
            return UNIT;
        }
        if (query_first <= node_first && node_last <= query_last) {
            return a[k];
        } else {
            size_t node_mid = (node_first + node_last) / 2;
            T vl = query(query_first, query_last, k * 2 + 1, node_first, node_mid);
            T vr = query(query_first, query_last, k * 2 + 2, node_mid, node_last);
            return f(vl, vr);
        }
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    segment_tree<int> st(all(A), [](int x, int y) { return max(x, y); }, -1);
    REP(_, Q) {
        int T;
        cin >> T;
        if (T == 1) {
            int X, V;
            cin >> X >> V;
            --X;
            st.update(X, V);
        } else if (T == 2) {
            int L, R;
            cin >> L >> R;
            --L;
            cout << st.query(L, R) << '\n';
        } else if (T == 3) {
            int X, V;
            cin >> X >> V;
            --X;
            int first = X;
            int last = N + 1;
            while (first < last) {
                int mid = (first + last) / 2;
                if (st.query(X, mid) >= V) {
                    last = mid;
                } else {
                    first = mid + 1;
                }
            }
            --first;
            cout << (first + 1) << '\n'; // 1-based indexing
        }
    }
    cout << flush;

    return 0;
}
