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
#define PB push_back
#define MP make_pair
#define FST first
#define SND second
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

    int h, w;
    cin >> h >> w;
    VVI a(h, VI(w, 0));
    REP(i, h) {
        REP(j, w) {
            char c;
            cin >> c;
            if (c == '#') {
                a[i][j] = 1;
            }
        }
    }

    int x=0,y=0;
    a[0][0]=0;
    while(x!=h-1 ||  y!=w-1){
        if(x<h-1){
            if(a[x+1][y]==1){
                a[x+1][y]=0;
                x++;
                continue;
            }
        }
        if(y<w-1){
            if(a[x][y+1]==1){
                a[x][y+1]=0;
                y++;
                continue;
            }
        }
        cout << "Impossible" << endl;
        return 0;
    }

    REP(i, h) {
        REP(j, w) {
            char c;
            if (a[i][j] == 1) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    cout << "Possible" << endl;


    return 0;
}