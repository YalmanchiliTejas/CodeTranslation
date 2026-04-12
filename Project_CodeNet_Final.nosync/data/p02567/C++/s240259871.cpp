#include<functional>
#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

template <typename T>
class SegTree {
private:
    size_t node_size_;
    vector<T> node_;
    T identity_;                     // ex) INF, 0, etc...
    function<T(T, T)> operation_;    // ex) min, max, sum, etc...
    function<T(T, T)> update_;       // ex) add, change, etc..
public:
    SegTree(size_t node_size, T identity, function<T(T, T)> operation, function<T(T, T)> update):
        identity_(identity), operation_(operation), update_(update) {
        node_size_ = 1;
        while (node_size_ < node_size) node_size_ *= 2;
        node_ = vector<T>(2 * node_size_ - 1, identity);
    }
    void change(int idx, T new_value) {
        int node_idx = idx + node_size_ - 1;
        node_[node_idx] = update_(node_[node_idx], new_value);
        while (node_idx > 0) {
            node_idx = (node_idx - 1) / 2;
            node_[node_idx] = operation_(node_[node_idx * 2 + 1], node_[node_idx * 2 + 2]);
        }
    }
    T _query(int left, int right, int node_idx, int node_left, int node_right) {
        if (node_right <= left || right <= node_left) {
            return identity_;
        }
        if (left <= node_left && node_right <= right) {
            return node_[node_idx];
        }
        else {
            T left_value = _query(left, right, node_idx * 2 + 1, node_left, (node_left + node_right) / 2);
            T right_value = _query(left, right, node_idx * 2 + 2, (node_left + node_right) / 2, node_right);
            return operation_(left_value, right_value);
        }
    }
    T query(int left, int right) {
        return _query(left, right, 0, 0, node_size_);
    }
    T operator[](int idx) {
        return node_[idx + node_size_ - 1];
    }
    int _search(int kth, int node_idx, int node_left, int node_right) {
        // kth >= 1
        if (node_right - node_left == 1) {
            return node_idx - node_size_ + 1;
        }
        if (node_[node_idx * 2 + 1] < kth) {
            return _search(kth - node_[node_idx * 2 + 1], node_idx * 2 + 2, (node_left + node_right) / 2, node_right);
        } else {
            return _search(kth, node_idx * 2 + 1, node_left, (node_left + node_right) / 2);
        }
    }
    int search(int kth) {
        return _search(kth, 0, 0, node_size_);
    }
    int _findMinLeft(int left, int right, T val, int node_idx, int node_left, int node_right) {
        if (node_[node_idx] < val || right <= node_left || left >= node_right) {
            return (int)node_size_;
        }
        if (node_idx >= (int)node_size_ - 1) {
            return node_idx - (int)node_size_ + 1;
        }
        int left_pos = _findMinLeft(left, right, val, node_idx * 2 + 1, node_left, (node_left + node_right) / 2);
        if (left_pos != (int)node_size_) {
            return left_pos;
        }
        return _findMinLeft(left, right, val, node_idx * 2 + 2, (node_left + node_right) / 2, node_right);
    }
    int findMinLeft(int left, int right, T val) {
        return _findMinLeft(left, right, val, 0, 0, (int)node_size_);
    }
};

const int INF = 1 << 30;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    int a;
    SegTree<int> seg(N, -INF, [](int a, int b) {return max(a, b);}, [](int a, int b) {return b;});
    rep(i, 0, N) {
        cin >> a;
        seg.change(i, a);
    }
    int t, x, v, l, r;
    rep(i, 0, Q) {
        cin >> t;
        if (t == 1) {
            cin >> x >> v;
            --x;
            seg.change(x, v);
        } else if (t == 2) {
            cin >> l >> r;
            --l;
            cout << seg.query(l, r) << endl;
        } else {
            cin >> x >> v;
            --x;
            cout << min(seg.findMinLeft(x, N, v), N) + 1 << endl;
        }
    }
    return 0;
}