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

int main()
{
    int n; cin >> n;
    vector<int> v(n); cin >> v;

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    n = v.size();

    map<int,int> mp;
    for (int i = 0; i < n; ++i) {
        mp[v[i]] = i;
    }

    auto dp = make_v<int>(n, n);
    fill_all(dp, 2);

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int next = v[j] + (v[j] - v[i]);
            if (mp.count(next) != 0) {
                chmax(dp[j][mp[next]], dp[i][j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            chmax(ans, dp[i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}

