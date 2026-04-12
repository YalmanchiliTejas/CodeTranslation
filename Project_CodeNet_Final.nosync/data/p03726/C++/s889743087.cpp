#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int> >;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class T> vector<T> make_vec(size_t a) { return vector<T>(a); }
template<class T, class... Ts> auto make_vec(size_t a, Ts... ts) {
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template<class T, class V>
typename enable_if<is_class<T>::value == 0>::type fill(T &t, const V &v) {
    t = v;
}
template<class T, class V>
typename enable_if<is_class<T>::value != 0>::type fill(T &t, const V &v){
    for (auto &e : t) fill(e, v);
}

#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }



Graph G;
vector<int> deg;
vector<bool> seen;

int main() {
    int N; cin >> N;
    G.assign(N, vector<int>());
    deg.assign(N, 0);
    seen.assign(N, 0);
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
        deg[a]++, deg[b]++;
    }
    bool res = true;
    queue<int> que;
    for (int i = 0; i < N; ++i) if (deg[i] == 1) que.push(i);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        if (seen[v]) continue;
        seen[v] = true;

        //COUT(v);
        
        int nv = -1;
        for (auto e : G[v]) if (!seen[e]) nv = e;
        if (nv == -1) {
            res = false;
            break;
        }
        seen[nv] = true;
        for (auto nv2 : G[nv]) {
            if (seen[nv2]) continue;
            deg[nv2]--;
            if (deg[nv2] == 1) que.push(nv2);
        }

        //COUT(nv);
    }
    if (res) cout << "Second" << endl;
    else cout << "First" << endl;
}
