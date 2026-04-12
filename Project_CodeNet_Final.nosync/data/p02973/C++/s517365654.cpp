// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;
 
int main() {
    multiset<int> ms;
    int N; cin >> N;
    int ans = 0;
    for(int i=0; i<N; i++) {
        int val; cin >> val;
        if(ms.empty()) {
            ans++;
            ms.insert(val);
        }
        else {
            // val 未満で最大の要素
            auto itr = ms.lower_bound(val);
            if(itr == ms.begin()) {
                ans++;
                ms.insert(val);
            }
            else {
                --itr;
                ms.erase(itr);
                ms.insert(val);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
