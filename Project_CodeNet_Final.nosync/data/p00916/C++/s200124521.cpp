#include <bits/stdc++.h>
using namespace std;
using LL = long long;

#define fs first
#define sc second

const LL MOD = 1e9+7;
const double EPS = 1e-10;

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

// std::vector Declaration and Initialization
template<typename T>
vector<T> make_vector(size_t a, T x) { return vector<T>(a, x); }
template<typename T, typename U, typename... Ts>
auto make_vector(size_t a, U b, Ts... ts) {
    return vector<decltype(make_vector<T>(b,ts...))>(a,make_vector<T>(b,ts...));
}

// std::vector Input
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto &e : v) {
        is >> e;
    }
    return is;
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

int main()
{
    while (true) {
        int n; cin >> n;
        if (n == 0) break;

        vector<int> l(n), t(n), r(n), b(n);
        for (int i = 0; i < n; ++i) {
            input(l[i], t[i], r[i], b[i]);
        }

        map<int,int> col, row;
        for (int i = 0; i < n; ++i) {
            col[l[i]] = col[r[i]] = 1;
            row[t[i]] = row[b[i]] = 1;
        }

        int H = 0, W = 0;
        for (auto &p : col) {
            p.sc = W++;
        }
        for (auto &p : row) {
            p.sc = H++;
        }

        auto s = make_vector<bool>(2*H+1, 2*W+1, false);

        for (int i = 0; i < n; ++i) {
            for (int j = 2*col[l[i]]+1; j <= 2*col[r[i]]+1; ++j) {
                s[2*row[b[i]]+1][j] = s[2*row[t[i]]+1][j] = true;
            }
            for (int j = 2*row[b[i]]+1; j <= 2*row[t[i]]+1; ++j) {
                s[j][2*col[l[i]]+1] = s[j][2*col[r[i]]+1] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < 2*H+1; ++i) {
            for (int j = 0; j < 2*W+1; ++j) {
                if (s[i][j]) continue;
                s[i][j] = true;

                ++ans;
                queue<pair<int,int>> que;
                que.emplace(i, j);
                while (!que.empty()) {
                    int x, y;
                    tie(x, y) = que.front(); que.pop();
                    int dx[4] = {0, 1, 0, -1},
                        dy[4] = {1, 0, -1, 0};
                    for (int k = 0; k < 4; ++k) {
                        int tx = x + dx[k],
                            ty = y + dy[k];
                        if (tx < 0 || tx >= 2*H+1 ||
                            ty < 0 || ty >= 2*W+1) continue;
                        if (s[tx][ty]) continue;
                        s[tx][ty] = true;
                        que.emplace(tx, ty);
                    }
                }
            }
        }
        cout << ans << endl;

    }

    return 0;
}

