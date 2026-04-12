#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <cstdio>
#include <climits>
#include <complex>
#include <cstdint>
#include <tuple>

#define M_PI       3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
inline int readInt() { int x; scanf("%d", &x); return x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, K;
struct Edge {
    int to, cost;
    Edge(int to, int cost): to(to), cost(cost) {}
};

typedef vector<vector<Edge>> AdjList;
AdjList graph;

const int INF = 100000000;

vi dist;
int d[110][110];

bool bellman_ford(int n, int s) { // nは頂点数、sは開始頂点
    dist = vector<int>(n, INF);
    dist[s] = 0; // 開始点の距離は0
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            for (int u = 0; u < n; u++) {
                if (dist[v] != INF && dist[u] > dist[v] + d[v][u]) {
                    dist[u] = dist[v] + d[v][u];
                    if (i == n - 1) return true; // n回目にも更新があるなら負の閉路が存在
                }
            }
        }
    }
    return false;
}
bool cmp(const pair<int,string>& a, const pair<int,string>& b){
    return a.first < b.first;
}
int main() {
    //cout << fixed << setprecision(15);

    int n;
    int cnt=0;
    while(cin >> n, n){
        if(cnt) cout << endl;
        cnt++;
        vector<pair<int, string>> vp;
        REP(i, n){
            string s;
            cin >> s;
            int q, w, e;
            cin >> q >> w >> e;
            vp.push_back({-(q*3+e), s});
        }

        sort(vp.begin(), vp.end(), cmp);

        REP(i, n){
            cout << vp[i].second << "," << -vp[i].first << endl;
        }
        
    }
    return 0;
}
