#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <tuple>
#include <deque>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <random>
#include <limits>
#include <iterator>
#include <functional>
#include <sstream>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
typedef pair<ll, int> Pl;
const double PI = 3.1415926535897932;   // acos(-1)
const double EPS = 1e-15;
const int INF = 1001001001;
const ll mod = 1e+9 + 7;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define chadd(x, y) x = (x + y) % mod

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, c;
    int x, y;
    cin >> a >> b >> c >> x >> y;
    ll res = 1e+18;
    for(int i = 0; i <= max(x, y); ++i){
        ll hoge = c * 2 * i;
        hoge += a * max(0, x - i);
        hoge += b * max(0, y - i);
        chmin(res, hoge);
    }
    cout << res << endl;
}