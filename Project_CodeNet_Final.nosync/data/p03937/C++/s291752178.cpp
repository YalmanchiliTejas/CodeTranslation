#pragma region includes, macros
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef int64_t i64;
typedef pair<i64, i64> P;

template<class T>
const T INF = numeric_limits<T>::max();
template<class T>
const T SINF = numeric_limits<T>::max() / 10;
static const i64 MOD = 1000000007;

//int dx[5] = {-1,0,0,0,1}, dy[5] = {0,-1,0,1,0};
//int dx[8] = {-1,0,1,1,1,0,-1,-1}, dy[8] = {1,1,1,0,-1,-1,-1,0};
//int dx[9] = {-1,0,1,1,1,0,-1,-1,0}, dy[9] = {1,1,1,0,-1,-1,-1,0,0};

struct edge {
    i64 from, to, cost;
    edge(i64 to, i64 cost) : from(-1), to(to), cost(cost) {}
    edge(i64 src, i64 to, i64 cost) : from(src), to(to), cost(cost) {}
};

// http://beet-aizu.hatenablog.com/entry/2018/04/08/145516
template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T& t, const V& v) { t = v; }

template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T& t, const V& v) {
    for (auto& e : t) fill_v(e, v);
}
//

#pragma endregion

int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };

vector< int64_t > divisor(int64_t n) {
    vector< int64_t > ret;
    for (int64_t i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

int main() {
    i64 h, w;
    cin >> h >> w;
    vector<vector<int>> dp(10, vector<int>(10, 0));
    vector<string> s(h);
    for(int i = 0; i < h; ++i){
        cin >> s[i];
    }
    int l = 0;
    int r = -1;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < l; ++j){
            if(s[i][j] == '#'){
                cout << "Impossible" << endl;
                return 0;
            }
        }
        for(int j = l; j <= w; ++j){
            if(j == w) r = j - 1;
            else if(s[i][j] == '.'){
                r = j - 1;
                break;
            }
        }
        for(int j = r + 1; j < w; ++j){
            if(s[i][j] == '#'){
                cout << "Impossible" << endl;
                return 0;
            }
        }
        if(l > r){
            cout << "Impossible" << endl;
            return 0;
        }else{
            l = r;
        }
    }
    if(r == w - 1)cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}

// n = am + b (a == b)
// n = a(m + 1) 1, 2, 4, 8
