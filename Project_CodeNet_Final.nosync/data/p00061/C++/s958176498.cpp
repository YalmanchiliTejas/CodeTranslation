#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <complex>
#include <fstream>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T> T RoundOff(T a){ return int(a+.5-(a<0)); }
template<class T, class C> void chmax(T& a, C b){ if(a < b) a = b; }
template<class T, class C> void chmin(T& a, C b){ if(b < a) a = b; }
template<class T, class C> pair<T, C> mp(T a, C b){ return make_pair(a, b); }

class J
{
public:
    int p;
    J(int p) : p(p){}
    bool operator () (int x)
    { return p < x; }
};

int main()
{
    map<int, int> team;
    vint          points;
    
    int n, p; char k;
    while(cin >> n >> k >> p && (n || p))
    {
        points.push_back(p);
        team.insert(pair<int, int>(n, p));
    }
    
    sort(ALL(points));
    points.erase(unique(ALL(points)), points.end());
    
    while(cin >> n)
    {
        J j(team[n]);
    
        cout << count_if(ALL(points), j) + 1 << endl;
    }
}