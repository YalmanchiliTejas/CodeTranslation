#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <memory>
#include <complex>
#include <numeric>
#include <cstdio>
#include <iomanip>

#define REP(i,m,n) for(int i=int(m);i<int(n);i++)
#define RREP(i,m,n) for(int i=int(n)-1;i>=int(m);--i)
#define EACH(i,c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

#ifdef LOCAL
#define DEBUG(s) cout << (s) << endl
#define dump(x)  cerr << #x << " = " << (x) << endl
#define BR cout << endl;
#else
#define DEBUG(s) do{}while(0)
#define dump(x) do{}while(0)
#define BR 
#endif
using namespace std;

using UI = unsigned int;
using UL = unsigned long;
using LL = long long int;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;

//struct edge {int from, to, cost;};

constexpr double EPS = 1e-10;
//constexpr double PI  = acos(-1.0);
//constexpr int INF = INT_MAX;
constexpr int MOD = 1'000'000'007;

template<class T> inline T sqr(T x) {return x*x;}

LL len[51] = {};
vector<map<LL,LL>> memo(51);

LL calcp(int n, LL x) {
    if (memo[n].count(x) == 1) return memo[n][x];
    //dump(n);
    //dump(x);
    if (n == 1) {
        if (x == 0) return memo[n][x] = 0;
        if (x == 4) return memo[n][x] = 3;
        else return memo[n][x] = x;
    }
    if (x == 0) return 0;
    if (x == len[n] - 1) return memo[n][x] = 0LL + 1 + 2 * calcp(n-1,len[n-1]-1);
    if (x == len[n] / 2) return memo[n][x] = 0LL + 1 + calcp(n-1,len[n-1]-1);
    if (x < len[n] / 2) return memo[n][x] = 0LL + calcp(n-1,x-1);
    if (x > len[n] / 2) return memo[n][x] = 0LL + 1 + calcp(n-1,len[n-1]-1) + calcp(n-1,x - 2 - len[n-1]);
}

void solve() {
    LL n,x;
    cin >> n >> x;
    len[0] = 1;
    REP(i,1,n+1) len[i] = 3 + 2 * len[i-1];
    --x;
    cout << calcp(n,x) << endl;
}

int main() {
    solve();
    
    return 0;
}