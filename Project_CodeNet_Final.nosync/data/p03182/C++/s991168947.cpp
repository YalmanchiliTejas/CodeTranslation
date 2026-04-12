#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

template<typename T, typename U, bool PROP = true> struct segment_tree_lazy {
    int S;
    vector<T> table;
    vb has; vector<U> ops;

    segment_tree_lazy(int _S) : S(_S) {
        table.resize(2 * S), has.resize(S), ops.resize(S);
    }

    segment_tree_lazy(auto begin, auto end) : segment_tree_lazy(distance(begin, end)) {
        copy(begin, end, table.begin() + S);
        for (int i = S - 1; i > 0; i--)
            table[i] = table[2 * i] + table[2 * i + 1];
    }

    void apply(int i, const U &op) {
        table[i] = op(table[i]);
        if (i < S) has[i] = true, ops[i] = op(ops[i]);
    }

    void rebuild(int i) {
        for (i /= 2; i; i /= 2)
            table[i] = ops[i](table[2 * i] + table[2 * i + 1]);
    }

    void propagate(int i) {
        for (int j = 31 - __builtin_clz(i); j > 0; j--) {
            int k = i >> j;
            if (has[k]) {
                apply(2 * k, ops[k]);
                apply(2 * k + 1, ops[k]);
                has[k] = false, ops[k] = U{};
            }
        }
    }

    void replace(int i, T v) {
        if (PROP) propagate(i + S);
        table[i + S] = v;
        rebuild(i + S);
    }

    void operator()(int i, int j, U op) {
        i += S, j += S;
        if (PROP) propagate(i), propagate(j - 1);
        for (int l = i, r = j; l < r; l /= 2, r /= 2) {
            if (l&1) apply(l++, op);
            if (r&1) apply(--r, op);
        }
        rebuild(i), rebuild(j - 1);
    }

    T operator()(int i, int j) {
        i += S, j += S;
        if (PROP) propagate(i), propagate(j - 1);
        T left{}, right{};
        for (; i < j; i /= 2, j /= 2) {
            if (i&1) left = left + table[i++];
            if (j&1) right = table[--j] + right;
        }
        return left + right;
    }
    T operator()(int i) { return (*this)(i, i+1); }
};

struct max_ll {
    ll val;

    max_ll() : val(0) {}
    max_ll(ll val) : val(val) {}

    max_ll operator+(const max_ll& other) const {
        return max_ll(max(val, other.val));
    }
};

struct add_op {
    ll val;

    add_op() : val(0) {}
    add_op(ll val) : val(val) {}

    max_ll operator()(const max_ll& x) const {
        return max_ll(val + x.val);
    }

    add_op operator()(const add_op& other) const {
        return add_op(val + other.val);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    ll M;
    cin >> N >> M;

    vll A(M);
    vi L(M);
    vi R(M);
    vvi Rs(N+1);

    for(int i=0;i<M;i++) {
        cin >> L[i] >> R[i] >> A[i];
        Rs[R[i]].push_back(i);
    }

    segment_tree_lazy<max_ll, add_op> segdp(N+1);

    for(int i=1;i<=N;i++) {
        max_ll cur = segdp(0, i);
        segdp.replace(i, cur);

        for (int j : Rs[i]) {
            segdp(L[j], R[j]+1, add_op(A[j]));
        }
    }

    cout << segdp(1, N+1).val << endl;

    return 0;
}