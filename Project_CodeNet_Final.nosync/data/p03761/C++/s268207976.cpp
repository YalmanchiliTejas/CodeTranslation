#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <stack>
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
typedef uint64_t ull;
typedef pair<int, int> P;
constexpr double PI = 3.1415926535897932;   // acos(-1)
constexpr double EPS = 1e-9;
constexpr int INF = 1001001001;
constexpr int mod = 1000000007;
// constexpr int mod = 998244353;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> common(26, INF);
    vector<int> cnt;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        cnt.assign(26, 0);
        int len = s.length();
        for(int j = 0; j < len; ++j)    ++cnt[s[j] - 'a'];
        for(int j = 0; j < 26; ++j) chmin(common[j], cnt[j]);
    }
    string ans = "";
    for(int i = 0; i < 26; ++i){
        for(int j = 0; j < common[i]; ++j){
            ans += 'a' + i;
        }
    }
    cout << ans << endl;
}