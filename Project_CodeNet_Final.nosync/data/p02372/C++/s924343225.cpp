#pragma region Macro
#pragma region Basic
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i < i##_len; i++)
#define FORD(i, a, b) for (int i = (a), i##_len = (b); i > i##_len; i--)
#define FORR(t, a) for (auto t : a)
#define ALL(x) (x).begin(), (x).end()  // sortなどの引数を省略したい
#define GET(i, j) get<j>(i)
#define MT(x, ...) make_tuple(x, __VA_ARGS__)
#define SZ(x) ((int)(x).size())
//#define ZERO(x) memset(x, 0, sizeof(x))
//#define FILL(x, y) memset(x, y, sizeof(x))
#define UNUSED(x) (void(x));
#define PB push_back
#define EB emplace_back
#ifdef _DEBUG
#define PRE_COMMAND             \
    std::cin.rdbuf(in.rdbuf()); \
    cout << fixed << setprecision(15);
#else
#define PRE_COMMAND cout << fixed << setprecision(15);
#endif
const double EPS = 1e-10;
const double PI = acos(-1.0);
template <class T>
auto MAX(T& seq) {
    return *max_element(seq.begin(), seq.end());
}
template <class T>
auto MIN(T& seq) {
    return *min_element(seq.begin(), seq.end());
}
template <class T>
auto SUM(T& seq) {
    T temp{0};
    auto& temp2 = temp[0];
    return accumulate(seq.begin(), seq.end(), temp2);
}
template <class T>
void SORT(T& seq) {
    sort(seq.begin(), seq.end());
}
template <class T, class S>
void SORT(T& seq, S& sort_order) {
    sort(seq.begin(), seq.end(), sort_order);
}
template <class T>
void SORTR(vector<T>& seq) {
    sort(seq.begin(), seq.end(), greater<T>());
}
template <class T>
void CHMAX(T& a, const T& b) {
    if (a < b) { a = b; }
}
template <class T>
void CHMIN(T& a, const T& b) {
    if (b < a) { a = b; }
}
template <class T>
set<T> VECTOR_2_SET(vector<T>& v) {
    set<T> s;
    for (auto ele : v) { s.insert(ele); }
    return s;
}
template <class T>
vector<T> SET_2_VECTOR(set<T>& s) {
    vector<T> v;
    for (auto ele : s) { v.push_back(ele); }
    return v;
}
#pragma endregion Basic
#pragma region overload
template <class T, class S>
void operator+=(vector<T>& l, S& r) {
    for (auto i : r) { l.push_back(i); }
}
template <class T, class S>
void operator+=(set<T>& l, S& r) {
    for (auto i : r) { l.insert(i); }
}
template <class T, class S>
void operator+=(multiset<T>& l, S& r) {
    for (auto i : r) { l.insert(i); }
}
template <class T, class S>
vector<T> operator+(vector<T>& l, S& r) {
    vector<T> l_copy = l;
    for (auto i : r) { l_copy.push_back(i); }
    return l_copy;
}
template <class T>
vector<T> operator+(const vector<T> l, const vector<T>& r) {
    vector<T> l_copy = l;
    for (auto i : r) { l_copy.push_back(i); }
    return l_copy;
}
template <class T, class S>
set<T> operator+(set<T>& l, S& r) {
    set<T> l_copy = l;
    for (auto i : r) { l_copy.insert(i); }
    return l_copy;
}
template <class T>
set<T> operator+(const set<T> l, const set<T>& r) {
    set<T> l_copy = l;
    for (auto i : r) { l_copy.insert(i); }
    return l_copy;
}
template <class T, class S>
multiset<T> operator+(multiset<T>& l, S& r) {
    set<T> l_copy = l;
    for (auto i : r) { l_copy.insert(i); }
    return l_copy;
}
template <class T>
multiset<T> operator+(const multiset<T> l, const set<T>& r) {
    set<T> l_copy = l;
    for (auto i : r) { l_copy.insert(i); }
    return l_copy;
}
string operator+(const string l, const string& r) {
    string str = l;
    str += r;
    return str;
}
string operator*(const string l, const size_t& r) {
    string str = l;
    for (size_t i = 0; i < r; i++) { str += l; }
    return str;
}
#pragma endregion overload
#pragma region Input
template <class Head>
void INPUT(vector<Head>& head);
template <size_t N, class Head>
void INPUT(array<Head, N>& head);
template <class T1>
void INPUT(tuple<T1>& t);
template <class T1, class T2>
void INPUT(tuple<T1, T2>& t);
template <class T1, class T2, class T3>
void INPUT(tuple<T1, T2, T3>& t);
template <class T1, class T2, class T3, class T4>
void INPUT(tuple<T1, T2, T3, T4>& t);
template <class T1, class T2, class T3, class T4, class T5>
void INPUT(tuple<T1, T2, T3, T4, T5>& t);
template <class Head>
void INPUT(Head& head);
template <class Head, class... Tail>
void INPUT(Head& head, Tail&... tail);
//本体
template <class Head>
void INPUT(vector<Head>& head) {
    for (size_t i = 0; i < head.size(); i++) { INPUT(head[i]); }
}
template <size_t N, class Head>
void INPUT(array<Head, N>& head) {
    for (size_t i = 0; i < head.size(); i++) { INPUT(head[i]); }
}
template <class T1>
void INPUT(tuple<T1>& t) {
    cin >> get<0>(t);
}
template <class T1, class T2>
void INPUT(tuple<T1, T2>& t) {
    cin >> get<0>(t) >> get<1>(t);
}
template <class T1, class T2, class T3>
void INPUT(tuple<T1, T2, T3>& t) {
    cin >> get<0>(t) >> get<1>(t) >> get<2>(t);
}
template <class T1, class T2, class T3, class T4>
void INPUT(tuple<T1, T2, T3, T4>& t) {
    cin >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t);
}
template <class T1, class T2, class T3, class T4, class T5>
void INPUT(tuple<T1, T2, T3, T4, T5>& t) {
    cin >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t);
}
template <class Head>
void INPUT(Head& head) {
    cin >> head;
}
template <class Head, class... Tail>
void INPUT(Head& head, Tail&... tail) {
    INPUT(head);
    INPUT((tail)...);
}
#pragma endregion Input
#pragma region Print
template <class T1>
void PRINT2(tuple<T1> t);
template <class T1, class T2>
void PRINT2(tuple<T1, T2> t);
template <class T1, class T2, class T3>
void PRINT2(tuple<T1, T2, T3> t);
template <class T1, class T2, class T3, class T4>
void PRINT2(tuple<T1, T2, T3, T4> t);
template <class T1, class T2, class T3, class T4, class T5>
void PRINT2(tuple<T1, T2, T3, T4, T5> t);
template <class Head>
void PRINT2(vector<Head> head);
template <class Head>
void PRINT2(vector<vector<Head>> head);
template <size_t N, class Head>
void PRINT2(vector<array<Head, N>> head);
template <class... Head>
void PRINT2(vector<tuple<Head...>> head);
template <size_t N, class Head>
void PRINT2(array<Head, N> head);
template <class Head>
void PRINT2(Head head);
template <class Head, class... Tail>
void PRINT2(Head head, Tail... tail);
template <class Head>
void PRINT(Head head);
template <class... Head>
void PRINT(Head... head);
template <int N, class Head>
void PRINT(Head head);
template <class T1>
void PRINT2(tuple<T1> t) {
    PRINT2(get<0>(t));
}
template <class T1, class T2>
void PRINT2(tuple<T1, T2> t) {
    PRINT2(get<0>(t), get<1>(t));
}
template <class T1, class T2, class T3>
void PRINT2(tuple<T1, T2, T3> t) {
    PRINT2(get<0>(t), get<1>(t), get<2>(t));
}
template <class T1, class T2, class T3, class T4>
void PRINT2(tuple<T1, T2, T3, T4> t) {
    PRINT2(get<0>(t), get<1>(t), get<2>(t), get<3>(t));
}
template <class T1, class T2, class T3, class T4, class T5>
void PRINT2(tuple<T1, T2, T3, T4, T5> t) {
    PRINT2(get<0>(t), get<1>(t), get<2>(t), get<3>(t), get<4>(t));
}
template <class Head>
void PRINT2(vector<Head> head) {
    for (auto i = head.begin(); i != head.end(); i++) {
        PRINT2(*i);
        if (i != head.end() - 1) { cout << " "; }
    }
}
template <class Head>
void PRINT2(vector<vector<Head>> head) {
    for (auto i = head.begin(); i != head.end(); i++) {
        PRINT2(*i);
        if (i != head.end() - 1) { cout << endl; }
    }
}
template <size_t N, class Head>
void PRINT2(vector<array<Head, N>> head) {
    for (auto i = head.begin(); i != head.end(); i++) {
        PRINT2(*i);
        if (i != head.end() - 1) { cout << endl; }
    }
}
template <class... Head>
void PRINT2(vector<tuple<Head...>> head) {
    for (auto i = head.begin(); i != head.end(); i++) {
        PRINT2(*i);
        if (i != head.end() - 1) { cout << endl; }
    }
}
template <size_t N, class Head>
void PRINT2(array<Head, N> head) {
    for (auto i = head.begin(); i != head.end(); i++) {
        PRINT2(*i);
        if (i != head.end() - 1) { cout << " "; }
    }
}
template <class Head>
void PRINT2(Head head) {
    cout << head;
}
template <class Head, class... Tail>
void PRINT2(Head head, Tail... tail) {
    PRINT2(head);
    cout << " ";
    PRINT2((tail)...);
}
template <class Head>
void PRINT(Head head) {
    PRINT2(head);
    cout << endl;
}
template <class... Head>
void PRINT(Head... head) {
    PRINT2((head)...);
    cout << endl;
}
template <int N, class Head>
void PRINT(Head head) {
    PRINT2(head);
    cout << endl;
}
#pragma endregion Print
#pragma endregion Macro

template <class T>
vector<T> tree_dist(vector<vector<tuple<int, T>>>& g, int start) {
    int n = (int)g.size(), u, v;
    T inf = pow(10, 9), w;
    vector<int> q(1, start);
    vector<T> dist(n, inf);
    dist[start] = 0;
    while (q.size()) {
        u = q.back();
        q.pop_back();
        for (auto temp : g[u]) {
            tie(v, w) = temp;
            if (dist[v] == inf) {
                q.push_back(v);
                dist[v] = dist[u] + w;
            }
        }
    }
    return dist;
}

template <class T>
vector<T> tree_height(vector<vector<tuple<int, T>>>& g) {
    T m1 = -pow(10, 9), m2 = -pow(10, 9);
    int n = (int)g.size(), v1 = -1, v2 = -1;
    vector<T> d1 = tree_dist(g, 0);
    for (int i = 0; i < n; i++) {
        if (d1[i] > m1) {
            m1 = d1[i];
            v1 = i;
        }
    }
    vector<T> d2 = tree_dist(g, v1);
    for (int i = 0; i < n; i++) {
        if (d2[i] > m2) {
            m2 = d2[i];
            v2 = i;
        }
    }
    d1 = tree_dist(g, v2);
    for (int i = 0; i < n; i++) { d2[i] = max(d1[i], d2[i]); }
    return d2;
}

int main() {
    PRE_COMMAND
    int n, a, b, c;
    INPUT(n);
    vector<vector<tuple<int, int>>> g(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        g[a].push_back(make_tuple(b, c));
        g[b].push_back(make_tuple(a, c));
    }
    auto s = tree_height(g);
    FORR(i, s) { PRINT(i); };
}
