#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define REP(i, s) for (int i = 0; i < s; ++i)
#define ALL(v) (v.begin(), v.end())
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T> ostream& operator << (ostream &s, set<T> P)
{ EACH(it, P) { s << "<" << *it << "> "; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }


const long long MOD = 1000000007;
inline long long mod(long long a, long long m) { return (a % m + m) % m; }

typedef pair<long long, int> Edge;

const int MAX = 110000;
const long long INF = 1LL<<59;
int N, M, S, T;
vector<Edge> G[MAX];

long long ds[MAX], ns[MAX], dt[MAX], nt[MAX];

int main() {
    while (cin >> N >> M >> S >> T) {
        --S, --T;
        for (int i = 0; i < MAX; ++i) G[i].clear();
        for (int i = 0; i < M; ++i) {
            int u, v, d;
            cin >> u >> v >> d;
            --u, --v;
            G[u].push_back(Edge(d, v));
            G[v].push_back(Edge(d, u));
        }
        for (int i = 0; i < MAX; ++i) {
            ds[i] = dt[i] = INF;
            ns[i] = nt[i] = 0;
        }
        ds[S] = 0;
        ns[S] = 1;
        priority_queue<Edge, vector<Edge>, greater<Edge> > que;
        que.push(Edge(0, S));
        while (!que.empty()) {
            long long curd = que.top().first;
            int cur = que.top().second;
            que.pop();
            if (ds[cur] < curd) continue;
            
            //cout << "S start " << cur << ": " << ds[cur] << ", " << ns[cur] << endl;
            
            for (auto e : G[cur]) {
                if (ds[e.second] > ds[cur] + e.first) {
                    ds[e.second] = ds[cur] + e.first;
                    ns[e.second] = ns[cur];
                    que.push(Edge(ds[e.second], e.second));
                }
                else if (ds[e.second] == ds[cur] + e.first) {
                    ns[e.second] += ns[cur];
                    ns[e.second] %= MOD;
                }
            }
        }
        dt[T] = 0;
        nt[T] = 1;
        que.push(Edge(0, T));
        while (!que.empty()) {
            long long curd = que.top().first;
            int cur = que.top().second;
            que.pop();
            if (dt[cur] < curd) continue;
            
            //cout << "T start " << cur << ": " << dt[cur] << ", " << nt[cur] << endl;
            
            for (auto e : G[cur]) {
                if (dt[e.second] > dt[cur] + e.first) {
                    dt[e.second] = dt[cur] + e.first;
                    nt[e.second] = nt[cur];
                    que.push(Edge(dt[e.second], e.second));
                }
                else if (dt[e.second] == dt[cur] + e.first) {
                    nt[e.second] += nt[cur];
                    nt[e.second] %= MOD;
                }
            }
        }
        
        //COUT(ns[T]); COUT(nt[S]);
        
        long long D = ds[T];
        long long res = (ns[T] * nt[S]) % MOD;
        for (int v = 0; v < N; ++v) {
            if (ds[v] == dt[v] && ds[v] + dt[v] == D) {
                long long sub = (ns[v] * nt[v]) % MOD;
                sub = (sub * sub) % MOD;
                res = mod(res - sub, MOD);
            }
            
            for (auto e : G[v]) {
                int from = v;
                int to = e.second;
                long long dis = e.first;
                if (ds[from] + dis + dt[to] != D) continue;
                if (ds[from] == dt[from] || ds[to] == dt[to]) continue;
                if (ds[from] < dt[from] && ds[to] > dt[to]) {
                    long long sub = (ns[from] * nt[to]) % MOD;
                    sub = (sub * sub) % MOD;
                    res = mod(res - sub, MOD);
                }
            }
        }
        
        cout << res << endl;
    }
}





