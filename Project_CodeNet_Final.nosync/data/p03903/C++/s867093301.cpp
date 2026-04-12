#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using namespace std;
using lli = long long int;
template <class T>
class segtree
{
public:
    lli n;
    vector<T> dat;
    function<T(T, T)> func;
    T dummy;
    segtree<T>(lli _n, function<T(T, T)> f, T dummy) : func(f), dummy(dummy)
    {
        n = 1;
        while (n < _n) {
            n = n * 2;
        }
        dat.assign(2 * n - 1, dummy);
    }
    void update(lli k, T a)
    {
        k += n - 1;
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = func(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    T query(int a, int b)
    {
        return query(a, b, 0, 0, n);
    }
    // [a,b)の何かを求める.
    T query(int a, int b, int k, int l, int r)
    {
        //交差しないときはダミー
        if (r <= a || b <= l)
            return dummy;
        if (a <= l && r <= b)
            return dat[k];
        else {
            T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return func(vl, vr);
        }
    }
    T get(int a)
    {
        return query(a, a + 1, 0, 0, n);
    }
};
template <class T>
struct hldec {
    int n;
    int col = 0;
    vector<vector<int>> e;
    vector<vector<int>> heavy;
    vector<vector<int>> light;
    vector<vector<T>> cls;
    vector<T> vers;
    vector<pair<int, int>> pos;
    vector<pair<int, int>> par;
    map<pair<int, int>, int> dict;
    function<T(T, T)> f;
    T unit;
    vector<segtree<T>> vec_seg;
    int root = 0;
    vector<int> size;
    hldec(int n, vector<T> vers, function<T(T, T)> f, T unit, int root = 0) : n(n), root(root), vers(vers), unit(unit), f(f)
    {
        e.assign(n, {});
        par.assign(n, make_pair(-1, -1));
        heavy.assign(n, {});
        light.assign(n, {});
        size.assign(n, 0);
        pos.assign(n, make_pair(-1, -1));
        cls.assign(n, {});
    }
    void add(int u, int v)
    {
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int sub_tree_size(int cur, int par)
    {
        int tmp = 1;
        for (auto s : e[cur]) {
            if (par != s) {
                tmp += sub_tree_size(s, cur);
            }
        }
        size[cur] = tmp;
        return tmp;
    }
    void dfs_label(int cur, int par)
    {
        lli idx = -1;
        lli mem = 0;
        rep(i, e[cur].size())
        {
            auto s = e[cur][i];
            if (s != par) {
                if (size[s] > mem) {
                    mem = size[s];
                    idx = i;
                }
            }
        }
        if (idx == -1)
            return;
        rep(i, e[cur].size())
        {
            auto s = e[cur][i];
            if (s != par) {
                if (idx == i) {
                    heavy[cur].push_back(s);
                } else {
                    light[cur].push_back(s);
                }
                dfs_label(s, cur);
            }
        }
    }
    void edge_labeling()
    {
        sub_tree_size(root, -1);
        dfs_label(root, -1);
    }
    void dfs_arrays(int cur, int c)
    {
        cls[c].push_back(vers[cur]);
        int idx = cls[c].size() - 1;
        pos[cur] = make_pair(c, cls[c].size() - 1);
        dict[pos[cur]] = cur;

        for (auto s : heavy[cur]) {
            dfs_arrays(s, c);
        }
        for (auto s : light[cur]) {
            col++;
            par[col] = make_pair(c, idx);
            dfs_arrays(s, col);
        }
    }
    void make_arrays()
    {
        dfs_arrays(root, 0);
    }
    void build_segtree()
    {
        rep(j, cls.size())
        {
            auto& s = cls[j];
            int size = s.size();
            segtree<T> seg(size, f, unit);
            rep(i, size)
            {
                seg.update(i, s[i]);
            }
            vec_seg.push_back(seg);
        }
    }
    void build(bool opt = false)
    {
        edge_labeling();
        if (opt) {
            e.clear();
        }
        cerr << "labeled done" << endl;
        make_arrays();

        cerr << "arrays" << endl;
        if (opt) {
            heavy.clear();
            light.clear();
        }

        build_segtree();

        cerr << "seg_build" << endl;
    }
    T query(int u, int v)
    {

        vector<pair<int, int>> hist_u;
        vector<pair<int, int>> hist_v;
        rep(j, 2)
        {
            int tmp = j == 1 ? u : v;
            while (true) {
                int cur_col = pos[tmp].first;
                if (j)
                    hist_u.push_back(pos[tmp]);
                else
                    hist_v.push_back(pos[tmp]);
                if (cur_col == 0)
                    break;
                tmp = dict[par[cur_col]];
            }
        }
        int pivot = 0;
        T ans = unit;
        set<int> hist_u_set;
        map<int, int> post;
        for (auto s : hist_u) {
            hist_u_set.insert(s.first);
            post[s.first] = s.second;
        }
        rep(i, hist_v.size())
        {
            if (hist_u_set.find(hist_v[i].first) != hist_u_set.end()) {
                int h = post[hist_v[i].first];
                ans = f(vec_seg[hist_v[i].first].query(min(h, hist_v[i].second), max(h, hist_v[i].second) + 1), ans);
                pivot = hist_v[i].first;
                break;
            }
        }

        rep(i, hist_u.size())
        {
            if (hist_u[i].first == pivot)
                break;
            ans = f(vec_seg[hist_u[i].first].query(0, hist_u[i].second + 1), ans);
        }
        rep(i, hist_v.size())
        {
            if (hist_v[i].first == pivot)
                break;
            ans = f(vec_seg[hist_v[i].first].query(0, hist_v[i].second + 1), ans);
        }
        return ans;
    }
};

vector<pair<lli, lli>> e[4005];
vector<pair<lli, lli>> ne[4005];
int main()
{
    int n, m;
    cin >> n >> m;
    int a, b;
    lli c;
    rep(i, m)
    {
        cin >> a >> b >> c;
        a--, b--;
        e[a].push_back(make_pair(b, c));
        e[b].push_back(make_pair(a, c));
    }
    using p = pair<lli, pair<lli, lli>>;
    priority_queue<p, vector<p>, greater<p>> que;
    bool used[4005] = {};
    que.push(make_pair(0, make_pair(0, -1)));
    lli ans = 0;
    int hoge = n;
    vector<pair<lli, lli>> edge;
    vector<lli> v(2 * n, 0);
    while (!que.empty()) {
        auto cur = que.top().second;
        auto cost = que.top().first;
        que.pop();
        if (used[cur.first])
            continue;
        used[cur.first] = true;
        ans += cost;
        if (cur.second != -1) {
            edge.push_back(make_pair(cur.first, hoge));
            edge.push_back(make_pair(cur.second, hoge));
            v[hoge] = cost;
            hoge++;
        }
        for (auto s : e[cur.first]) {
            que.push(make_pair(s.second, make_pair(s.first, cur.first)));
        }
    }

    auto f = [](lli u, lli v) -> lli { return max(u, v); };
    hldec<lli> tr(hoge, v, f, 0);
    for (auto s : edge) {
        tr.add(s.first, s.second);
    }
    // tr.add(0, 1);
    // tr.add(0, 2);
    // tr.add(1, 3);
    // tr.add(1, 4);
    tr.build(true);
    int s, t, q;
    cin >> q;
    rep(i, q)
    {
        cin >> s >> t;
        cout << ans - tr.query(s - 1, t - 1) << endl;
    }
    // //cout << tr.query(0,1)<<endl;
    // cout << tr.query(3, 4) << endl;
};
;
