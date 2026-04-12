#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

//#define LOCAL 0
//#ifdef LOCAL
//#define DEBUG(s) cout << (s) << endl
//#define dump(x)  cerr << #x << " = " << (x) << endl
//#define BR cout << endl;
//#else
//#define DEBUG(s) do{}while(0)
//#define dump(x) do{}while(0)
//#define BR
//#endif


//改造
typedef long long int ll;
using namespace std;
#define INF (1 << 20)
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl

//ここから編集する

///クラスカル法
struct edge {int u,v;ll cost;};
bool comp(const edge& e1,const edge& e2){
    return e1.cost < e2.cost;
}

vector<edge> es;
///クラスカル法ここまで

class UnionFind {
    vector<int> p;//p[i]はiの属する組織
public:
    UnionFind(int n){
        p = vector<int>(n);
        for(int i = 0; i < n; i++){
            p[i] = i;
        }
        return;
    }

    void printState() {
        if (DEBUG) {
            cout << "---" << endl;
            for (int i = 0; i < p.size(); i++) {
                printf("%dの親は%d\n", i, p[i]);
            }
            cout << "---" << endl;
        }
    }

/* xの属する集合を返す */
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

/* yにxを統合する */
    void unite(int x, int y) {
        p[find(x)] = p[find(y)];
    }

/* xとyが属する集合が同じかを判定する */
    bool same(int x, int y) {
        return find(x) == find(y);
    }

};


int main() {
    int N;
    cin >> N;
    vector<pair<ll,int> > x(N);
    vector<pair<ll,int> > y(N);
    rep(i,0,N){
        int xx,yy;
        cin >> xx >> yy;
        x[i] = make_pair(xx,i);
        y[i] = make_pair(yy,i);
    }
    sort(all(x));
    sort(all(y));
    rep(i,0,x.size()-1){
        edge e{};
        e.u = x[i].second;
        e.v = x[i+1].second;
        e.cost = abs(x[i].first - x[i+1].first);
        es.push_back(e);
        swap(e.u,e.v);
        es.push_back(e);
    }

    rep(i,0,y.size()-1){
        edge e{};
        e.u = y[i].second;
        e.v = y[i+1].second;
        e.cost = abs(y[i].first - y[i+1].first);
        es.push_back(e);
        swap(e.u,e.v);
        es.push_back(e);
    }
    sort(all(es),comp);
    UnionFind u(N);
    ll ans = 0LL;
    for(int i = 0; i < es.size(); i++){
        edge e = es[i];
        if(!u.same(e.u,e.v)){
            u.unite(e.u,e.v);
            ans += e.cost;
        }
    }
    cout << ans << endl;
    return 0;
}
