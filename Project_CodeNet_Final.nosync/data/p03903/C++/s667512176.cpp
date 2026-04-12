#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include "bits/stdc++.h" // define macro "/D__MAI"

using namespace std;
typedef long long int ll;

#define xprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#define debugv(v) {printf("L%d %s > ",__LINE__,#v);for(auto e:v){cout<<e<<" ";}cout<<endl;}
#define debuga(m,w) {printf("L%d %s > ",__LINE__,#m);for(int x=0;x<(w);x++){cout<<(m)[x]<<" ";}cout<<endl;}
#define debugaa(m,h,w) {printf("L%d %s >\n",__LINE__,#m);for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){cout<<(m)[y][x]<<" ";}cout<<endl;}}
#define ALL(v) (v).begin(),(v).end()
#define repeat(cnt,l) for(auto cnt=0ll;cnt<(l);++cnt)
#define iterate(cnt,b,e) for(auto cnt=(b);cnt!=(e);++cnt)
#define MD 1000000007ll
#define PI 3.1415926535897932384626433832795
template<typename T1, typename T2> ostream& operator <<(ostream &o, const pair<T1, T2> p) { o << "(" << p.first << ":" << p.second << ")"; return o; }
template<typename iterator> inline size_t argmin(iterator begin, iterator end) {
    return distance(begin, min_element(begin, end));
}
template<typename iterator> inline size_t argmax(iterator begin, iterator end) {
    return distance(begin, max_element(begin, end));
}
template<typename T> T& maxset(T& to, const T& val) { return to = max(to, val); }
template<typename T> T& minset(T& to, const T& val) { return to = min(to, val); }

mt19937_64 randdev(8901016);
inline ll rand_range(ll l, ll h) {
    return uniform_int_distribution<ll>(l, h)(randdev);
}

#ifdef __MAI
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
#ifdef __VSCC
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
namespace {
#define isvisiblechar(c) (0x21<=(c)&&(c)<=0x7E)
    class MaiScanner {
    public:
        template<typename T> void input_integer(T& var) {
            var = 0;
            T sign = 1;
            int cc = getchar_unlocked();
            for (; cc<'0' || '9'<cc; cc = getchar_unlocked())
                if (cc == '-') sign = -1;
            for (; '0' <= cc&&cc <= '9'; cc = getchar_unlocked())
                var = (var << 3) + (var << 1) + cc - '0';
            var = var*sign;
        }
        inline int c() { return getchar_unlocked(); }
        inline MaiScanner& operator>>(int& var) {
            input_integer<int>(var);
            return *this;
        }
        inline MaiScanner& operator>>(long long& var) {
            input_integer<long long>(var);
            return *this;
        }
        inline MaiScanner& operator>>(string& var) {
            int cc = getchar_unlocked();
            for (; !isvisiblechar(cc); cc = getchar_unlocked());
            for (; isvisiblechar(cc); cc = getchar_unlocked())
                var.push_back(cc);
        }
        template<typename IT> void in(IT begin, IT end) {
            for (auto it = begin; it != end; ++it) *this >> *it;
        }
    };
    class MaiPrinter {
        int stack_p;
        char stack[32];
    public:
        template<typename T>
        void output_integer(T var) {
            if (var == 0) {
                putchar_unlocked('0');
                return;
            }
            if (var < 0) {
                putchar_unlocked('-');
                var = -var;
            }
            stack_p = 0;
            while (var) {
                stack[stack_p++] = '0' + (var % 10);
                var /= 10;
            }
            while (stack_p)
                putchar_unlocked(stack[--stack_p]);
        }
        MaiPrinter& operator<<(char c) {
            putchar_unlocked(c);
            return *this;
        }
        MaiPrinter& operator<<(int var) {
            output_integer<int>(var);
            return *this;
        }
        MaiPrinter& operator<<(long long var) {
            output_integer<long long>(var);
            return *this;
        }
        MaiPrinter& operator<(int var) {
            output_integer<int>(var);
            putchar_unlocked(' ');
            return *this;
        }
        MaiPrinter& operator<(long long var) {
            output_integer<long long>(var);
            putchar_unlocked(' ');
            return *this;
        }
        MaiPrinter& operator<<(const string& str) {
            const char* p = str.c_str();
            const char* l = p + str.size();
            while (p < l) putchar_unlocked(*p++);
            return *this;
        }
    };
}
MaiScanner scanner;
MaiPrinter printer;


class Graph2d {
public:
    typedef int numeric;
    size_t n;
    vector<numeric> matrix;

    Graph2d(size_t size) :n(size), matrix(size*size) {};

    void resize(size_t s) {
        n = s;
        matrix.resize(n*n);
    }

    inline numeric& at(int y, int x) { return matrix[y*n + x]; }
    inline numeric& operator()(int y, int x) { return matrix[y*n + x]; }
    inline numeric at(int y, int x) const { return matrix[y*n + x]; }
    inline numeric operator()(int y, int x) const { return matrix[y*n + x]; }

    inline void connect(int u, int v, int dist = 1) {
        at(u, v) = at(v, u) = dist;
    }
    inline void connect_d(int from, int to, int dist = 1) { // directedEdge u->v
        at(from, to) = dist;
    }
};


class Graph {
public:
    size_t n;
    vector<vector<int>> vertex_to;

    Graph(size_t n) :n(n), vertex_to(n) {}

    void connect(int from, int to) {
        vertex_to[from].emplace_back(to);
        vertex_to[to].emplace_back(from);
    }
    void resize(size_t _n) {
        n = _n;
        vertex_to.resize(_n);
    }
};


void warshall_floyd(Graph2d& g) {
    int i, j, k;
    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++) {
            for (k = 0; k < g.n; k++) {
                g(j, k) = min(g(j, k), g(j, i) + g(i, k));
            }
        }
    }
}


class unionfind {
public:
    vector<int> data;
    unionfind(int size) : data(size, -1) { }
    bool union_set(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    inline bool find_set(int x, int y) {
        return root(x) == root(y);
    }
    inline int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    inline int size(int x) {
        return -data[root(x)];
    }
};


int m, n, kei;
Graph2d graph_mat(1);
vector<array<int,3>> edges;
ll answer[4040][4040];

void build() {
    Graph tree(n);
    unionfind uf(n);
    ll total = 0;
    for (int i = 0, cnt = 0; cnt < n - 1; ++i) {
        auto& v = edges[i];
        if (uf.union_set(v[1], v[2])) {
            tree.connect(v[1], v[2]);
            ++cnt;
            total += v[0];
        }
    }
    vector<int> cycle_detector(n);
    function<void(int, int, int, ll)> dfs = [&](int start, int idx,int from, ll wmax) {
        answer[start][idx] = total - wmax;
        answer[idx][start] = total - wmax;
        assert(!cycle_detector[idx]);
        cycle_detector[idx] = 1;

        for (int to : tree.vertex_to[idx]) {
            if (from == to) continue;
            dfs(start, to, idx, max(wmax, (ll)graph_mat(idx, to)));
        }
    };

    for (int i = 0; i < n; ++i) {
        fill(ALL(cycle_detector), 0);
        dfs(i, i, 4010, 0);
    }
}

int main() {

    scanner >> n >> m;

    graph_mat.resize(n);
    fill(ALL(graph_mat.matrix), 5e15);

    repeat(i, m) {
        ll a, b, c;
        scanner >> a >> b >> c;
        --a; --b;
        graph_mat.connect(a, b, c);
        edges.push_back({ c,a,b });
    }
    sort(ALL(edges));

    build();

    ll nq;
    scanner >> nq;

    repeat(qi, nq) {
        ll u, v;
        scanner >> u >> v;
        --u; --v;
        printer << answer[u][v] << '\n';
    }
    

    return 0;
}