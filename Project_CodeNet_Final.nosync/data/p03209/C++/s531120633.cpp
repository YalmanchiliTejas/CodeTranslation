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
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
typedef pair<ll, int> Pl;
typedef pair<int, pair<int, int>> PP;
const double PI = 3.1415926535897932;   // acos(-1)
const double EPS = 1e-15;
const int INF = 1001001001;
const int mod = 1e+9 + 7;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define chadd(x, y) x = (x + y) % mod

vector<ll> S, p;

ll rec(int n, ll x){
    if(n == 0)  return 1;
    ll len = S[n - 1];
    ll patty = p[n - 1];
    if(x == 1)  return 0;
    else if(x <= len + 1)   return rec(n - 1, x - 1);
    else if(x == len + 2)   return patty + 1;
    else if(x <= (len + 1) * 2) return patty + 1 + rec(n - 1, x - len - 2);
    else return patty * 2 + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll x;
    cin >> n >> x;

    S.resize(n + 2), p.resize(n + 2);
    S[0] = 1, p[0] = 1;
    for(int i = 0; i <= n; ++i){
        S[i + 1] = S[i] * 2 + 3;
        p[i + 1] = p[i] * 2 + 1;
    }
    cout << rec(n, x) << endl;
}