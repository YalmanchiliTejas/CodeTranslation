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

// input
template<typename T>
void input(T& a) { cin >> a; }
template<typename T,typename... Ts>
void input(T& a,Ts&... ts) {
    input<T>(a);
    input<T>(ts...);
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

// std::vector Input
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto &e : v) {
        is >> e;
    }
    return is;
}

// std::vector Input parallel
template<typename T>
void input_at(size_t idx, T& a) {
    cin >> a[idx];
}
template<typename T, typename... Ts>
void input_at(size_t idx, T& a, Ts&... ts) {
    input_at<T>(idx, a);
    input_at<T>(idx, ts...);
}
template<typename T>
void input_parallel(T& a) {
    for (size_t idx = 0; idx < (size_t)a.size(); ++idx) {
        input_at<T>(idx, a);
    }
}
template<typename T, typename...Ts>
void input_parallel(T& a, Ts&... ts) {
    for (size_t idx = 0; idx < (size_t)a.size(); ++idx) {
        input_at<Ts...>(idx, a, ts...);
    }
}

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

// std::array Debug
template<typename T, size_t n>
ostream& operator<<(ostream& os, const array<T, n>& v) {
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

// Weighted edge
template<typename T>
struct edge {
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}
    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x) {
        to = x;
        return *this;
    }

    operator int() const { return to; }

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

template<typename T>
void warshall_floyd(MatrixGraph<T> &g) {
    const auto INF = numeric_limits<T>::max();
    for(int k = 0; k < g.size(); k++) {
        for(int i = 0; i < g.size(); i++) {
            for(int j = 0; j < g.size(); j++) {
                if(g[i][k] == INF || g[k][j] == INF) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

typedef complex<double> Point;
typedef pair<Point, Point> LS;

#define INF 1000000000
#define EPS 1e-10

double cross(const Point &a, const Point &b) {
    return a.real() * b.imag() - a.imag() * b.real();
}

double dot(const Point &a, const Point &b) {
    return a.real() * b.real() + a.imag() * b.imag();
}

int is_intersected_ls(
        const Point &a1, const Point &a2,
        const Point &b1, const Point &b2)
{
    return cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS &&
           cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS;
}

int is_parallel(
        const Point &a1, const Point &a2,
        const Point &b1, const Point &b2)
{
    return abs(cross(a1-a2, b1-b2)) < EPS;
}

double distance_l_p(const LS &ls, const Point &c) {
    Point a = ls.fs, b = ls.sc;
    if (dot(b-a, c-a) < EPS) return abs(c-a);
    if (dot(a-b, c-b) < EPS) return abs(c-b);
    return abs(cross(b-a, c-a)) / abs(b-a);
}

double ls_distance(const LS &a, const LS &b) {
    bool parallel = is_parallel(a.fs, a.sc, b.fs, b.sc);
    bool intersect = is_intersected_ls(a.fs, a.sc, b.fs, b.sc);

    if (!parallel && intersect) return 0;

    return min({distance_l_p(a, b.fs),
                distance_l_p(a, b.sc),
                distance_l_p(b, a.fs),
                distance_l_p(b, a.sc)});
}

int main()
{
    while (true) {
        int N, M, L;
        input(N, M, L);
        if (N == 0) {
            break;
        }
        vector<double> x(N), y(N), a(N), r(N);
        for (int i = 0; i < N; ++i) {
            input(x[i], y[i], a[i], r[i]);
        }

        vector<array<Point,5>> v(N);

        for (int i = 0; i < N; ++i) {
            for (int k = 0; k < 5; ++k) {
                double theta = 2*M_PI*(90. + a[i] + 72. * k)/360.;
                v[i][k] = Point(x[i], y[i]) + std::polar(r[i], theta);
            }
        }


        auto dist = make_v<double>(N, N);
        fill_all(dist, numeric_limits<double>::max());
        for (int i = 0; i < N; ++i) {
            dist[i][i] = 0;
        }

        for (int i = 0; i < N; ++i) {
            for (int k = 0; k < 5; ++k) {
                LS l1 = {v[i][k], v[i][(k+2)%5]};

                for (int j = i+1; j < N; ++j) {
                    for (int l = 0; l < 5; ++l) {
                        LS l2 = {v[j][l], v[j][(l+2)%5]};

                        chmin(dist[i][j], ls_distance(l1, l2));
                        chmin(dist[j][i], ls_distance(l1, l2));

                    }
                }
            }
        }

        warshall_floyd(dist);

        printf("%.8lf\n", dist[M-1][L-1]);
    }

    return 0;
}

