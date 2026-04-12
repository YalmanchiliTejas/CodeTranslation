#include <bits/stdc++.h>

#define VARNAME(x) #x
#define show(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "sz:" << v.size() << "\n[";
    for (const auto& p : v) {
        os << p << ",";
    }
    os << "]\n";
    return os;
}

template <typename T>
istream& operator>>(istream& is, vector<T>& v)
{
    for (auto& e : v) {
        is >> e;
    }
    return is;
}

template <typename S, typename T>
ostream& operator<<(ostream& os, const pair<S, T>& p)
{
    os << "(" << p.first << "," << p.second
       << ")";
    return os;
}


constexpr ll MOD = (ll)1e9 + 7LL;

template <typename T>
constexpr T INF = numeric_limits<T>::max() / 10;

struct Min_Plus {
    using T = ll;

    struct AccMonoid {
        T operator()(const T& a, const T& b) const { return min(a, b); }
        static constexpr T identity() { return INF<T>; }
    };

    struct OpMonoid {
        using T = ll;
        T operator()(const T& f1, const T& f2) const { return f1 + f2; }
        static constexpr T identity() { return 0; }
    };

    T operator()(const OpMonoid::T& f, const T& x) const { return f + x; }
};
template <typename Base>
class SegmentTree
{
public:
    using BaseAlgebra = Base;
    using AccMonoid = typename BaseAlgebra::AccMonoid;
    using OpMonoid = typename BaseAlgebra::OpMonoid;
    using T = typename BaseAlgebra::T;
    using F = typename BaseAlgebra::OpMonoid::T;

    SegmentTree(const int n) : data_num(n), height(__lg(2 * data_num - 1)), size(1 << (1 + height)), half(size >> 1), value(size, AccMonoid::identity()), action(size, OpMonoid::identity()) { assert(n > 0); }
    SegmentTree(const std::vector<T>& val) : data_num(val.size()), height(__lg(2 * data_num - 1)), size(1 << (1 + height)), half(size >> 1), value(size), action(size, OpMonoid::identity())
    {
        for (int data = 0; data < half; data++) {
            if (data < data_num) {
                value[data + half] = val[data];
            } else {
                value[data + half] = AccMonoid::identity();
            }
        }
        for (int node = half - 1; node >= 1; node--) {
            value[node] = acc(value[2 * node], value[2 * node + 1]);
        }
    }

    T get(const int a) const
    {
        assert(0 <= a and a < data_num);
        return accumulate(a, a + 1);
    }

    void set(const int a, const T& val)
    {
        assert(0 <= a and a < data_num);
        const int node = a + half;
        value[node] = val;
        for (int i = node / 2; i > 0; i /= 2) {
            value[i] = acc(value[2 * i], value[2 * i + 1]);
        }
    }

    T accumulate(const int a, const int b) const  // Accumulate (a,b]
    {
        assert(0 <= a and a < b and b <= data_num);
        return accumulateRec(1, 0, half, a, b);
    }

    void modify(const int a, const int b, const F& f)  // Apply f on (a,b]
    {
        assert(0 <= a and a < b and b <= data_num);
        if (f == OpMonoid::identity()) {
            return;
        }
        modifyRec(1, 0, half, a, b, f);
    }

    void print() const
    {
        // cout << "#VALUE" << endl;
        // for (int i = half; i < size; i++) {
        //     cout << value[i] << " ";
        // }
        // cout << endl;
        // cout << "#ACTION" << endl;
        // for (int i = 1; i < half; i++) {
        //     cout << action[i] << " ";
        // }
        // cout << endl;
    }

private:
    void modifyRec(const int int_index, const int int_left, const int int_right, const int mod_left, const int mod_right, const F& f)
    {
        if (mod_left <= int_left and int_right <= mod_right) {
            value[int_index] = act(f, value[int_index]);
            action[int_index] = compose(f, action[int_index]);
        } else if (int_right <= mod_left or mod_right <= int_left) {
            // Do nothing
        } else {
            modifyRec(2 * int_index, int_left, (int_left + int_right) / 2, 0, half, action[int_index]);
            modifyRec(2 * int_index, int_left, (int_left + int_right) / 2, mod_left, mod_right, f);
            modifyRec(2 * int_index + 1, (int_left + int_right) / 2, int_right, 0, half, action[int_index]);
            modifyRec(2 * int_index + 1, (int_left + int_right) / 2, int_right, mod_left, mod_right, f);
            value[int_index] = acc(value[2 * int_index], value[2 * int_index + 1]);
            action[int_index] = OpMonoid::identity();
        }
    }

    T accumulateRec(const int int_index, const int int_left, const int int_right, const int mod_left, const int mod_right) const
    {
        if (mod_left <= int_left and int_right <= mod_right) {
            return value[int_index];
        } else if (int_right <= mod_left or mod_right <= int_left) {
            return AccMonoid::identity();
        } else {
            return act(action[int_index], acc(accumulateRec(2 * int_index, int_left, (int_left + int_right) / 2, mod_left, mod_right),
                                              accumulateRec(2 * int_index + 1, (int_left + int_right) / 2, int_right, mod_left, mod_right)));
        }
    }

    const int data_num;  // Num of valid data on leaves.
    const int height;
    const int size;
    const int half;
    vector<T> value;   // Tree for value(length: size)
    vector<F> action;  // Tree for action(length: half)
    bool has_lazy;

    const AccMonoid acc{};
    const OpMonoid compose{};
    const BaseAlgebra act{};
};


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    set<int> st;
    for (int i = 0; i < N; i++) {
        if (s[i] == ')') {
            st.insert(i);
        }
    }
    vector<ll> value(N, 0);
    for (int i = 0; i < N; i++) {
        value[i] = ((i == 0) ? 0 : value[i - 1]) + ((s[i] == '(') ? 1 : -1);
    }
    SegmentTree<Min_Plus> seg(value);
    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        q--;
        if (s[q] == '(') {
            seg.modify(q, N, -2);
            st.insert(q);
            s[q] = ')';
            s[*st.begin()] = '(';
            seg.modify(*st.begin(), N, 2);
            cout << *st.begin() + 1 << endl;
            st.erase(st.begin());
        } else {
            s[q] = '(';
            st.erase(q);
            int inf = 0;
            int sup = N;
            seg.modify(q, N, 2);
            while (inf < sup - 1) {
                const int mid = (inf + sup) / 2;
                const ll mini = seg.accumulate(mid, N);
                if (mini >= 2) {
                    sup = mid;
                } else {
                    inf = mid;
                }
            }
            s[sup] = ')';
            cout << sup + 1 << endl;
            st.insert(sup);
            seg.modify(sup, N, -2);
        }
    }

    return 0;
}