#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <array>
#include <complex>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <list>
#include <functional>
#include <numeric>
#include <stack>
#include <tuple>

using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
const int INF = 100000000;
const long long LINF = 1LL << 60;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-6;
using pii = std::pair<int, int>;
using pLL = std::pair<long long, long long>;
using ll = long long;
#define SORT(v) std::sort(v.begin(), v.end())
#define rSORT(v) std::sort(v.begin(), v.end(),std::greater<int>())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> x(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }
    int ans = 1;
    for (int i = 1; i < N; ++i) {
        bool watch = true;
        for (int j = 0; j < i; ++j) {
            if (x[i] < x[j]) watch=false;
        }
        if (watch != false) ans++;
    }
    cout << ans << endl;
    
    return 0;
}