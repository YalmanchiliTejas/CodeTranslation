#include "bits/stdc++.h"

#ifdef WINT_MIN
#define __MAI
#endif

using namespace std;
typedef unsigned int uint;
typedef long long int ll;
typedef unsigned long long int ull;

#define debugv(v) printf("L%d %s => ",__LINE__,#v);for(auto e:v){cout<<e<<" ";}cout<<endl;
#define debugm(m) printf("L%d %s is..\n",__LINE__,#m);for(auto v:m){for(auto e:v){cout<<e<<" ";}cout<<endl;}
#define debuga(m,w) printf("L%d %s is => ",__LINE__,#m);for(int x=0;x<(w);x++){cout<<(m)[x]<<" ";}cout<<endl;
#define debugaa(m,w,h) printf("L%d %s is..\n",__LINE__,#m);for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){cout<<(m)[x][y]<<" ";}cout<<endl;}
#define debugaar(m,w,h) printf("L%d %s is..\n",__LINE__,#m);for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){cout<<(m)[y][x]<<" ";}cout<<endl;}
#define ALL(v) (v).begin(),(v).end()
#define BIGINT 0x7FFFFFFF
#define E107 1000000007ll
void printbit(int u) { if (u == 0)cout << 0; else { int s = 0, k = 0; for (; 0<u; u >>= 1, k++)s = (s << 1) | (u & 1); for (; 0<k--; s >>= 1)cout << (s & 1); } }template<typename T1, typename T2>
    ostream& operator <<(ostream &o, const pair<T1, T2> p) { o << "(" << p.first << ":" << p.second << ")"; return o; }

#define TIME chrono::system_clock::now()
#define MILLISEC(t) (chrono::duration_cast<chrono::milliseconds>(t).count())

namespace {
    std::chrono::system_clock::time_point t;
    void tic() { t = TIME; }
    void toc() { fprintf(stderr, "TIME : %lldms\n", MILLISEC(TIME - t)); }
    std::chrono::system_clock::time_point tle = TIME;
#ifdef __MAI
    void safe_tle(int msec) { assert(MILLISEC(TIME - tle) < msec); }
#else
#define safe_tle(k) ;
#endif
}

#ifndef __MAI 
namespace {
    class MaiScanner {
    public:
        template<typename T>
        void input_integer(T& var) {
            var = 0;
            T sign = 1;
            int cc = getchar_unlocked();
            for (; cc<'0' || '9'<cc; cc = getchar_unlocked())
                if (cc == '-') sign = -1;
            for (; '0' <= cc&&cc <= '9'; cc = getchar_unlocked())
                var = (var << 3) + (var << 1) + cc - '0';
            var = var*sign;
        }
        void ign() { getchar_unlocked(); }
        MaiScanner& operator>>(int& var) {
            input_integer<int>(var);
            return *this;
        }
        MaiScanner& operator>>(long long& var) {
            input_integer<long long>(var);
            return *this;
        }
    };
}
MaiScanner scanner;
#else
#define scanner cin
#endif

class UndirectedGraphE {
public:
    size_t n;
    struct Edge {
        int u, v;
        Edge(int from = 0, int to = 0) :u(from), v(to) {}

        int to(int _v) { return _v == v ? u : v; }
    };
    vector<vector<int>> vertex_to;
    vector<Edge> edge;

    UndirectedGraphE(int n, int m = 5010) :n(n), vertex_to(n) { edge.reserve(m); }

    void connect(int from, int to) {
        vertex_to[from].push_back(edge.size()); // toto
        vertex_to[to].push_back(edge.size()); // fromfrom
        edge.emplace_back(from, to);
    }
    size_t degree(int v) {
        return vertex_to[v].size();
    }
    void resize(size_t _n) {
        n = _n;
        vertex_to.resize(_n);
    }
};

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
    bool find_set(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

int width, height;
int m, n, kei;

int aa[20];


int main() {
    int i, j, k;
    int x, y, a, b;


    cin >> n;
    UndirectedGraphE graph(n);
    unionfind uniuni(n);


    for (i = 0; i < n - 1; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (uniuni.find_set(i, j)) continue;
            cout << "? ";
            for (k = 0; k < n; ++k) {
                if (i == k || j == k) cout << 1;
                else cout << 0;
            }
            cout << endl;
            cin >> a;
            if (a) {
                graph.connect(i, j);
                uniuni.union_set(i, j);
                if (graph.edge.size() == n - 1) break;
            }
        }
    }

    cout << "! ";

    for (auto& e : graph.edge) {
        cout << "(" << e.u << "," << e.v << ") ";
    }
    cout << endl;



    return 0;
}