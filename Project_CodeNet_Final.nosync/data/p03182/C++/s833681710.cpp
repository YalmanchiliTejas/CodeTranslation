#include <cstdio>
#include <cstdlib>
#include <functional>
#include <vector>

using namespace std;

template <class T>
class segment_tree_lazy {
    public:
    segment_tree_lazy(int n, function<T(const T&, const T&)> merge_func, function<T(const T&, const T&)> calc_func, const T& init = T());
    ~segment_tree_lazy();
    void update(int x, const T& value);
    void update(int x, int y, const T& value); // [x, y)
    T get(int x);
    T get(int x, int y); // [x, y)
    
    private:
    int size;
    int height;
    function<T(const T&, const T&)> merge_func;
    function<T(const T&, const T&)> calc_func;
    T init;
    T* data;
    bool* has_delay;
    T* delay;
    inline void apply(int x, const T& value);
    inline void propagate(int x, int y);
    inline void propagate(int x);
};

template <class T> segment_tree_lazy<T>::segment_tree_lazy(int n, function<T(const T&, const T&)> merge_func, function<T(const T&, const T&)> calc_func, const T& init) : size(1 << (32 - __builtin_clz(n - 1))), height(31 - __builtin_clz(size)), merge_func(merge_func), calc_func(calc_func), init(init) {
    data = (T *)malloc(sizeof(T) * size * 2);
    has_delay = (bool *)malloc(sizeof(bool) * size);
    delay = (T *)malloc(sizeof(T) * size);
    for (int i = 0; i < size * 2; i++) data[i] = init;
    for (int i = 0; i < size; i++) has_delay[i] = false;
}

template <class T> segment_tree_lazy<T>::~segment_tree_lazy() {
    free(data);
    free(has_delay);
    free(delay);
}

template <class T> void segment_tree_lazy<T>::update(int x, const T& value) {
    x += size;
    propagate(x, x);
    apply(x, value);
    while (x >>= 1) data[x] = calc_func(data[x * 2], data[x * 2 + 1]);
}

template <class T> void segment_tree_lazy<T>::update(int x, int y, const T& value) {
    x += size, y += size;
    propagate(x, y - 1);
    bool fx = false, fy = false;
    for (; x < y; x >>= 1, y >>= 1) {
        if (fx) data[x - 1] = calc_func(data[(x - 1) * 2], data[(x - 1) * 2 + 1]);
        if (fy) data[y] = calc_func(data[y * 2], data[y * 2 + 1]);
        if (x & 1) apply(x++, value), fx = true;
        if (y & 1) apply(--y, value), fy = true;
    }
    for (x--; y > 0; x >>= 1, y >>= 1) {
        if (fx) data[x] = calc_func(data[x * 2], data[x * 2 + 1]);
        if (fy && (!fx || x != y)) data[y] = calc_func(data[y * 2], data[y * 2 + 1]);
    }
}

template <class T> T segment_tree_lazy<T>::get(int x) {
    x += size;
    propagate(x, x);
    return data[x];
}

template <class T> T segment_tree_lazy<T>::get(int x, int y) {
    T vl = init, vr = init;
    x += size, y += size;
    propagate(x, y - 1);
    for (; x < y; x >>= 1, y >>= 1) {
        if (x & 1) vl = calc_func(vl, data[x++]);
        if (y & 1) vr = calc_func(data[--y], vr);
    }
    return calc_func(vl, vr);
}

template <class T> inline void segment_tree_lazy<T>::apply(int x, const T& value) {
    data[x] = merge_func(data[x], value);
    if (x < size) {
        if (!has_delay[x]) {
            has_delay[x] = true;
            delay[x] = value;
        } else {
            delay[x] = merge_func(delay[x], value);
        }
    }
}

template <class T> inline void segment_tree_lazy<T>::propagate(int x, int y) {
    for (int i = height; i > 0; i--) propagate(x >> i), propagate(y >> i);
}

template <class T> inline void segment_tree_lazy<T>::propagate(int x) {
    if (!has_delay[x]) return;
    apply(x * 2, delay[x]);
    apply(x * 2 + 1, delay[x]);
    has_delay[x] = false;
}

vector <int> v[200001];
vector <pair<int, int>> w[200001];

int main() {
    int n, m, i, j;
    long long ans = 0;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int l, r, a;
        
        scanf("%d %d %d", &l, &r, &a);
        
        v[l].push_back(a);
        w[r].push_back(make_pair(l, a));
    }
    
    segment_tree_lazy <long long> s(n, [](long long x, long long y) {return x + y;}, [](long long x, long long y) {return max(x, y);}, -1e18);
    
    s.update(0, n + 1, 1e18);
    
    for (i = 1; i <= n; i++) {
        for (j = 0; j < v[i].size(); j++) s.update(0, i, v[i][j]);
        
        s.update(i, s.get(0, i));
        
        ans = max(ans, s.get(i, i + 1));
        
        for (j = 0; j < w[i].size(); j++) s.update(0, w[i][j].first, -w[i][j].second);
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
