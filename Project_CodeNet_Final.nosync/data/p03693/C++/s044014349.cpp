#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;

#define F first
#define S second
#define mkp make_pair
#define pb push_back
#define ppb pop_back
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define show(x) cerr << "# " << #x << " = " << (x) << endl
//#define int ll

const int N = 2e6 + 1;
const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int szT = (1 << 17) - 1;
const double PI = acos(-1.0);
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

int a, b, c;

int main () {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios_base :: sync_with_stdio(0);
    cin >> a >> b >> c;
    int x = (a * 100) + (b * 10) + c;
    if (x % 4 == 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
