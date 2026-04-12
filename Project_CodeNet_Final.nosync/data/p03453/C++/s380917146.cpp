#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}

vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
    vector<int> ord(size);
    for (int i = 0; i < size; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), compare);
    return ord;
}

template <typename T>
bool MinPlace(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool MaxPlace(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename Container>
int SZ(const Container& S) { return S.size(); }

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 100010;
int N;
vector<int> aa[MAXN];
vector<LL> dd[MAXN];

const LL mod = 1e9+7;
const LL INF = 1e16 + 8;
LL distS[MAXN], distT[MAXN], numS[MAXN], numT[MAXN];

void dijkstra(int source, LL dist[], LL num[]) {
    for (int v = 1; v <= N; v++) dist[v] = INF, num[v] = 0;
    dist[source] = 0, num[source] = 1;
    typedef pair<LL, int> pli;
    priority_queue<pli, vector<pli>, greater<pli>> q;
    q.push({0, source});
    while (!q.empty()) {
        auto pp = q.top();
        q.pop();
        int v = pp.second;
        LL d = pp.first;
        if (d > dist[v]) continue;
        for (int i = 0; i < (int)aa[v].size(); i++) {
            int a = aa[v][i];
            if (dist[a] == d + dd[v][i]) num[a] = (num[a] + num[v]) % mod;
            else if (dist[a] > d + dd[v][i]) {
                num[a] = num[v];
                dist[a] = d + dd[v][i];
                q.push({dist[a], a});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int M;
    int S, T;
    cin >> N >> M >> S >> T;
    for (int i = 0; i < M; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        aa[a].push_back(b);
        aa[b].push_back(a);
        dd[a].push_back(d);
        dd[b].push_back(d);
    }
    dijkstra(S, distS, numS);
    dijkstra(T, distT, numT);
    LL res = (numS[T] * numS[T]) % mod;
    for (int v = 1; v <= N; v++) {
        if (distS[v] + distT[v] == distS[T] and distS[v] == distT[v]) {
            LL K = (numS[v]*numT[v]) % mod;
            res -= (K*K) % mod;
        }
        for (int i = 0; i < (int)aa[v].size(); i++) {
            int a = aa[v][i];
            if (distS[v] + dd[v][i] + distT[a] > distS[T]) continue;
            if (distT[a] < distS[a] and distS[v] < distT[v]) {
                LL K = (numS[v] * numT[a]) % mod;
                res -= (K*K) % mod;
            }
        }
    }
    res %= mod;
    if (res < 0) res += mod;
    cout << res << "\n";
}

