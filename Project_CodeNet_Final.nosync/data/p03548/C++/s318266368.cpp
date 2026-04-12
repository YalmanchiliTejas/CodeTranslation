#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iomanip>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)

#define DEBUG

#ifdef DEBUG
#define var_dump(...) fprintf(stdout, __VA_ARGS__)
#define dump(a) cout << a << "\n";
#else
#define var_dump(...) 42
#define dump(a) 42
#endif

typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy4[]={0, 0, 1, -1};
int dx4[]={1, -1, 0, 0};
int dx8[]={0, 0, 1, -1, 1, 1, -1, -1};
int dy8[]={1, -1, 0, 0, 1, -1, -1, 1};

// https://beta.atcoder.jp/contests/abc078/tasks/abc078_b

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    int ans = X / (Y+Z);
    if (X % (Y+Z) < Z) ans--;

    cout << ans << "\n";

    return 0;
}
