#include <bits/stdc++.h>
using namespace std;
using LL = long long;

#define fs first
#define sc second

const LL MOD = 1e9+7;

template<class T>bool chmax(T &a, const T &b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T>bool chmin(T &a, const T &b) {
    if (b < a) { a = b; return true; }
    return false;
}


// std::vector Declaration
template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

// std::vector Initialization
template<typename T>
void fill_all(T& arr, const T& v) { arr = v; }
template<typename T, typename U>
void fill_all(T& arr, const U& v) { for (auto& i : arr) fill_all(i, v); }

// std::vector Debug
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    bool a = 1;
    for (auto e : v) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "]";
    return os;
}

// std::deque Debug
template<typename T>
ostream& operator<<(ostream& os, const deque<T>& d) {
    os << "[";
    bool a = 1;
    for (auto e : d) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "]";
    return os;
}

// std::pair Debug
template<typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << " " << p.second << ")";
    return os;
}

// std::set Debug
template<typename T>
ostream& operator<<(ostream& os, const set<T>& st) {
    os << "{";
    bool a = 1;
    for (auto e : st) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "}";
    return os;
}

// std::multiset Debug
template<typename T>
ostream& operator<<(ostream& os, const multiset<T>& st) {
    os << "{";
    bool a = 1;
    for (auto e : st) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "}";
    return os;
}

// std::map Debug
template<typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& mp) {
    os << "{";
    bool a = 1;
    for (auto e : mp) {
        os << (a ? "" : " ");
        os << e.first << ":" << e.second;
        a = 0;
    }
    os << "}";
    return os;
}

// std::tuple Debug
template<int N, class Tuple>
void out(ostream& os, const Tuple& t){}
template<int N, class Tuple, class H, class ...Ts>
void out(ostream& os, const Tuple& t) {
    if (N) os << " ";
    os << get<N>(t);
    out<N+1,Tuple,Ts...>(os, t);
}
template<class ...Ts>
ostream& operator<<(ostream& os, const tuple<Ts...>& t) {
    os << "(";
    out<0,tuple<Ts...>,Ts...>(os, t);
    os << ")";
    return os;
}

// Debug
#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl

template<typename T>
struct edge {
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}
    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    friend ostream& operator<<(ostream& os, const edge& e) {
        return os << "(" << e.src << "->" << e.to << ":" << e.cost << ")";
    }
};

template<typename T>
using Edges = vector<edge<T>>;
template<typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template<typename T>
using MatrixGraph = vector<vector<T>>;

int n, m;

int d0[] = {1, 0, -1, 0};
int d1[] = {0, 1, 0, -1};

bool dfs(int s0, int s1, int t0, int t1, int k, auto& used) {
    if (s0 == t0 && s1 == t1) {
        return true;
    }
    for (int u = k-1; u <= k+1; ++u) {
        int v = (u+4)%4;
        int x = s0 + d0[v],
            y = s1 + d1[v];
        if (x < 0 || x >= n || y < 0 || y >= m || used[x][y]) {
            continue;
        }
        used[x][y] = 1;
        if (dfs(x, y, t0, t1, v, used)) {
            return true;
        }
    }
    return false;
}

int main()
{
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        vector<string> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }

        auto used = make_v<int>(n, m);
        fill_all(used, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (c[i][j] == '#') {
                    used[i][j] = 1;
                }
            }
        }

        if (!dfs(0, 0, n-1, 0, 0, used)) {
            printf("NO\n");
            continue;
        }
        if (!dfs(n-1, 0, n-1, m-1, 1, used)) {
            printf("NO\n");
            continue;
        }
        if (!dfs(n-1, m-1, 0, m-1, 2, used)) {
            printf("NO\n");
            continue;
        }
        if (!dfs(0, m-1, 0, 0, 3, used)) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }

    return 0;
}

