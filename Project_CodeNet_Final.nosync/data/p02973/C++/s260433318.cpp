#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <deque>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <random>
#include <limits>
#include <iterator>
#include <functional>
#include <sstream>
#include <complex>
using namespace std;

typedef long long ll;
typedef uint64_t ull;
typedef pair<int, int> P;
constexpr double EPS = 1e-9;
constexpr int INF = 1001001001;
constexpr int mod = 1000000007;
// constexpr int mod = 998244353;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

template<typename T>
struct Compress{
    vector<T> xs;
    Compress() = default;
    Compress(const vector<T> &vs){
        add(vs);
    }
    Compress(const initializer_list<vector<T>> &vs){
        for(auto &p : vs)   add(p);
    }

    // vs 内の座標をすべて追加
    void add(const vector<T> &vs){
        copy(begin(vs), end(vs), back_inserter(xs));
    }

    void add(const T &x){
        xs.emplace_back(x);
    }
    
    void build(){
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
    }

    // vs 内の座標を座標圧縮したものを返す
    vector<int> get(const vector<T> &vs) const{
        vector<int> ret;
        transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x){
            return lower_bound(begin(xs), end(xs), x) - begin(xs);
        });
        return ret;
    }

    // 座標 x を座標圧縮したものを返す (x が xs 内で何番目にあるかを返す)
    int get(const T &x) const{
        return lower_bound(begin(xs), end(xs), x) - begin(xs);
    }

    // 座標圧縮後の k が示す実際の座標を返す
    const T &operator[](int k) const{
        return xs[k];
    }
};

template<typename T>
struct BinaryIndexedTree{
    vector<T> data;
    int sz;

    BinaryIndexedTree(int n){
        sz = n + 1;
        data.assign(sz, 0);
    }

    void add(int i, T x){
        ++i;
        while(i < sz){
            data[i] += x;
            i += i & -i;
        }
    }

    // [0, i] の区間和
    T sum(int i){
        T res = 0;
        ++i;
        while(i > 0){
            res += data[i];
            i -= i & -i;
        }
        return res;
    }

    T sum(int l, int r){
        return sum(r - 1) - sum(l - 1);
    }

    // val 以上を満たす 0-indexed の位置を返す
    int lower_bound(T val){
        // if(val <= 0)    return -1;
        int res = 0;
        int n = 1;
        while(n < sz)   n <<= 1;
        for(int k = n >> 1; k > 0; k >>= 1){
            if(res + k < sz && data[res + k] < val){
                val -= data[res + k];
                res += k;
            }
        }
        return res;     // 1-indexed であれば、res + 1 を返す
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    Compress<int> c;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        c.add(a[i]);
    }
    c.build();
    BinaryIndexedTree<int> bit(n);
    for(int i = 0; i < n; ++i){
        int x = c.get(a[i]);
        int sum = bit.sum(x - 1);
        if(sum == 0)    bit.add(x, 1);
        else{
            int y = bit.lower_bound(sum);
            bit.add(x, 1);
            bit.add(y, -1);
        }
    }
    cout << bit.sum(n - 1) << endl;
}