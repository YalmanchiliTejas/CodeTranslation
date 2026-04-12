// LNU_Algotesters
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <ctime>
#include <fstream>
#include <complex>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;

const int MAX = 2000 + 47;
const double EPS = 1e-9;




int main()
{
    
   // freopen("in.txt", "r", stdin);
    //ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    string s;
    int tot = 0;
    FOR(i, 0, n)
    {
        cin >> s;
        FOR(j, 0, m)
        tot += s[j] == '#';
    }
    if (tot == n + m - 1)
        cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}



