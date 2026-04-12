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
    VI a(n);
    REP(i,0,n) cin >> a[i];
    bool b = false;
    if (n % 2) {
        for (int i = n - 1; i >= 0; i -= 2) {
            if (b) cout << " ";
            else b = true;
            cout << a[i];
        }
        for (int i = 1; i < n; i += 2) {
            if (b) cout << " ";
            else b = true;
            cout << a[i];
        }
        cout << endl;
    } else {
        for (int i = n - 1; i >= 0; i -= 2) {
            if (b) cout << " ";
            else b = true;
            cout << a[i];
        }
        for (int i = 0; i < n; i += 2) {
            if (b) cout << " ";
            else b = true;
            cout << a[i];
        }
        cout << endl;
    }
    
     return 0;
}