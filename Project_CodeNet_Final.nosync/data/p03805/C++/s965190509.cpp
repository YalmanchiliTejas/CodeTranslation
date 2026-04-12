#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>

#define int long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (signed)((a).size())
#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

const int MOD = 1000000007;

#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")"  << " " << __FILE__ << endl;

signed main(void) {
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    VI a(m), b(m);
    REP(i, m) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    VVI e(n, VI(n, 0));
    REP(i, m) {
        e[a[i]][b[i]] = 1;
        e[b[i]][a[i]] = 1;
    }

    VI v(n);
    iota(ALL(v), 0);
    int ans = 0;
    do {
        if(v[0]!=0){
            continue;
        }
        bool f = true;
        FOR(i, 1, n) {
            if (e[v[i - 1]][v[i]] == 0) {
                f = false;
                break;
            }
        }
        if (f) {
            ans++;
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
    return 0;
}
