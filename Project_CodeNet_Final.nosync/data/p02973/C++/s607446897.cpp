#include<iostream>
#include<functional>
#include<vector>
#include<string>
#include<map>
#include<set>
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
    // serach-method's usage is written on CF567
    int _search(int kth, int node_idx, int node_left, int node_right) {
        // kth >= 1
        if (node_right - node_left == 1) return node_idx - node_size_ + 1;
        if (node_[node_idx * 2 + 1] < kth) return _search(kth - node_[node_idx * 2 + 1], node_idx * 2 + 2, (node_left + node_right) / 2, node_right);
        else return _search(kth, node_idx * 2 + 1, node_left, (node_left + node_right) / 2);
    }
    int search(int kth) {
        return _search(kth, 0, 0, node_size_);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& a : A) {
        cin >> a;
    }
    map<int, int> val_map;
    set<int> S;
    for (auto a : A) {
        S.insert(a);
    }
    int now_val = 0;
    for (auto s : S) {
        val_map[s] = now_val++;
    }
    for (auto& a : A) {
        a = val_map[a];
    }
    SegTree<int> seg(now_val, 0, [](int a, int b) {return max(a, b);}, [](int a, int b) {return max(a, b);});
    for (auto& a : A) {
        int val = seg.query(a, now_val);
        seg.change(a, val + 1);
    }
    int ans = 0;
    rep(val, 0, now_val) {
        chmax(ans, seg.query(val, val + 1));
    }
    cout << ans << endl;
    return 0;
}