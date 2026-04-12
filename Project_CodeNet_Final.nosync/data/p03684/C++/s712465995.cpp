#define _USE_MATH_DEFINES
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <clocale>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i, s, n) for(int i = (s), i##_len=(n); i < i##_len; ++i)
#define FORS(i, s, n) for(int i = (s), i##_len=(n); i <= i##_len; ++i)
#define VFOR(i, s, n) for(int i = (s); i < (n); ++i)
#define VFORS(i, s, n) for(int i = (s); i <= (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define REPS(i, n) FORS(i, 0, n)
#define VREP(i, n) VFOR(i, 0, n)
#define VREPS(i, n) VFORS(i, 0, n)
#define RFOR(i, s, n) for(int i = (s), i##_len=(n); i >= i##_len; --i)
#define RFORS(i, s, n) for(int i = (s), i##_len=(n); i > i##_len; --i)
#define RREP(i, n) RFOR(i, n, 0)
#define RREPS(i, n) RFORS(i, n, 0)
#define LLFOR(i, s, n) for(ll i = (s), i##_len=(n); i < i##_len; ++i)
#define LLFORS(i, s, n) for(ll i = (s), i##_len=(n); i <= i##_len; ++i)
#define LLVFOR(i, s, n) for(ll i = (s); i < (n); ++i)
#define LLVFORS(i, s, n) for(ll i = (s); i <= (n); ++i)
#define LLREP(i, n) LLFOR(i, 0, n)
#define LLREPS(i, n) LLFORS(i, 0, n)
#define LLVREP(i, n) LLVFOR(i, 0, n)
#define LLVREPS(i, n) LLVFORS(i, 0, n)
#define LLRFOR(i, s, n) for(ll i = (s). i##_len=(n); i >= i##_len; --i)
#define LLRFORS(i, s, n) for(ll i = (s), i##_len=(n); i > i##_len; --i)
#define LLRREP(i, n) LLRFOR(i, n, 0)
#define LLRREPS(i, n) LLRFORS(i, n, 0)
#define IREP(i, v) for(auto i = (v).begin(); i != (v).end(); ++i)
#define IRREP(i, v) for(auto i = (v).rbegin(); i != (v).rend(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(RALL(v))
#define SZ(x) ((int)(x).size())
#define REV(x) reverse(ALL(x))
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define BIT(n) (1LL<<(n))
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end())

using ld = long double;
using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using Pi_i = pair<int, int>;
using Pll_ll = pair<ll, ll>;
using VB = vector<bool>;
using VC = vector<char>;
using VD = vector<double>;
using VI = vector<int>;
using VLL = vector<ll>;
using VS = vector<string>;
using VSH = vector<short>;
using VULL = vector<ull>;

const int MOD = 1000000007; 
const int INF = 1000000000; //1e9
const int NIL = -1;
const ll LINF = 1000000000000000000; // 1e18
const double EPS = 1E-10;

template<class T, class S>
bool chmax(T &a, const S &b){
    if(a < b){
        a = b; return true;
    }
    return false;
}
template<class T, class S>
bool chmin(T &a, const S &b){
    if(b < a){
        a = b; return true;
    }
    return false;
}



struct edge{
    int to, cost;
    edge(int To, int Cost): to(To), cost(Cost){};
};


/*
int V; //頂点数
vector<vector<edge>> G;
vector<int> d; //既に木に含まれる点からの距離
*/

int prim(vector<vector<edge>>& G){
    int V(G.size());
    int res = 0;
    //Pi_i first: 距離　second: 頂点
    priority_queue<Pi_i, vector<Pi_i>, greater<Pi_i>> que;
    VI d(V, INF);
    d[0] = 0;
    que.push(MP(0, 0));

    while(!que.empty()){
        Pi_i p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        d[v] = 0;
        res += p.first;
        for(edge &e : G[v]){
            if(d[e.to] > e.cost){
                d[e.to] = e.cost;
                que.push(MP(d[e.to], e.to));
            }
        }
    }
    return res;
}


int main(){
    int N; cin >> N;
    vector<vector<edge>> G(N);
    //x,y,idx と y,x,id
    vector<pair<Pi_i, int>> px(N), py(N);
    REP(i, N){
        px[i].second = py[i].second = i;
        cin >> px[i].first.first >> px[i].first.second;
        py[i].first.first = px[i].first.second;
        py[i].first.second = px[i].first.first;
    }
    SORT(px); SORT(py);
    REP(i, N-1){
        G[px[i].second].push_back({px[i+1].second, 
                    abs(px[i].first.first - px[i+1].first.first)});
        G[px[i+1].second].push_back({px[i].second, 
                                  abs(px[i].first.first - px[i+1].first.first)});
        G[py[i].second].push_back({py[i+1].second, 
                                  abs(py[i].first.first - py[i+1].first.first)});
        G[py[i+1].second].push_back({py[i].second, 
                    abs(py[i].first.first - py[i+1].first.first)});
    }
    cout << prim(G) << endl;
    return 0;
}
