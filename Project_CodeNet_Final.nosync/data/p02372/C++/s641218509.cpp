#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <cassert>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <random>
#include <iomanip>
#include <unordered_set>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int,int> > vpii;
typedef vector<pair<ll,ll> > vpll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vc> vvc;
typedef vector<vs> vvs;
typedef vector<vll> vvll;
typedef map<int,int> mii;
typedef set<int> si;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define arep(i,v) for(auto i : v)
#define irep(it, stl) for(auto it = stl.begin(); it != stl.end(); it++)
#define drep(i,n) for(int i = (n) - 1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STLL(s) strtoll(s.c_str(), NULL, 10)
#define mp(p,q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define fi first
#define se second
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
template <class T> inline void dump(T &v){irep(i, v){cout<<*i<<((i==--v.end())?'\n':' ');}}
inline string getline(){string s; getline(cin,s); return s;}
inline void yn(const bool b){b?fin("yes"):fin("no");}
inline void Yn(const bool b){b?fin("Yes"):fin("No");}
inline void YN(const bool b){b?fin("YES"):fin("NO");}
struct io{io(){ios::sync_with_stdio(false);cin.tie(0);}};
const int INF = INT_MAX;
constexpr ll LLINF = 1LL<<60;
constexpr ll MOD = 1000000007;
constexpr ld EPS = 1e-11;

template <typename T>
class DIJKSTRA {
public:
    int V;

    struct dk_edge {
        int to;
        T cost;
    };

    typedef pair<T, int> PI; //firstは最短距離、secondは頂点の番号
    vector<vector<dk_edge> >G;
    vector<T> d; //これ答え。d[i]:=V[i]までの最短距離
    vector<int> prev; //経路復元

    DIJKSTRA(int size) {
        V = size;
        G = vector<vector<dk_edge> >(V);
        prev = vector<int> (V, -1);
    }

    void add(int from, int to, T cost) {
        dk_edge e = {to, cost};
        G[from].push_back(e);
    }

    void dijkstra(int s) {
        //greater<P>を指定することでfirstが小さい順に取り出せるようにする
        priority_queue<PI, vector<PI>, greater<PI> > que;
        d = vector<T> (V, LLINF);
        d[s] = 0;
        que.push(PI(0, s));

        while(!que.empty()) {
            PI p = que.top();
            que.pop();
            int v = p.second;
            if(d[v] < p.first) continue;
            for(int i = 0; i < G[v].size(); i++) {
                dk_edge e = G[v][i];
                if(d[e.to] > d[v] + e.cost) {
                    d[e.to] = d[v] + e.cost;
                    prev[e.to] = v;
                    que.push(PI(d[e.to], e.to));
                }
            }
        }
    }
    vector<int> get_path(int t) {
        vector<int> path;
        for(;t != -1; t = prev[t]) {
            //tがsになるまでprev[t]をたどっていく
            path.push_back(t);
        }
        //このままだとt->sの順になっているので逆順にする
        reverse(path.begin(),path.end());
        return path;
    }
    void show(void) {
        for(int i = 0; i < d.size()-1; i ++) {
            cout << d[i] << " ";
        }
        cout << d[d.size()-1] << endl;
    }
};

int main() {
    
    int v;
    cin >> v;
    DIJKSTRA<ll> dk(v);
    rep(i, v - 1) {
        int s,t,w;
        cin >> s >> t >> w;
        dk.add(s, t, w);
        dk.add(t, s, w);
    }
    vvll d(2, vll(v));
    int a=0,b=0;
    dk.dijkstra(0);
    int dA=0,dB=0;
    rep(i,v){
        if(dA<dk.d[i]){
            dA=dk.d[i];
            a=i;
        }
    }
    dk.dijkstra(a);
    rep(i,v){
        if(dB<dk.d[i]){
            dB=dk.d[i];
            b=i;
        }
    }
    dk.dijkstra(a);
    d[0]=dk.d;
    dk.dijkstra(b);
    d[1]=dk.d;
    rep(i, v) {
        cout<<max(d[1][i], d[0][i]) << endl;
    }
}
