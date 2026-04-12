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
constexpr double PI  = acos(-1.0);
//constexpr int INF = INT_MAX;

template<class T> inline T sqr(T x) {return x*x;}

int main() {
    int n;
    cin >> n;
    VLL a(n);
    REP(i,0,n) cin >> a[i];
    sort(all(a));
    reverse(all(a));
    REP(i,0,n) cerr << a[i] << " ";
    cerr << endl;
    LL cnt = 0;
    REP(r,0,1000) {
        if (*max_element(all(a)) <= n * 10) break;
        REP(i,0,n) {
            LL tmp = (a[i] - 50) / n;
            if (tmp < 0) tmp = 0;
            cnt += tmp;
            a[i] -= n * tmp;
            REP(j,0,n) {
                if (i != j) a[j] += tmp;
            }
        }
    }
    while (*max_element(all(a)) >= n && cnt++ >= 0) {
        auto it = max_element(all(a));
        for (auto i = begin(a); i != end(a); ++i) {
            if (i != it) *i += 1;
            else *i -= n;
        }
    }
    cout << cnt << endl;
    
    return 0;
}