#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <list>
#include <numeric>
#include <math.h>
#include <cstdlib>
#include <queue>
#include <iterator>
#include <limits>
#include <string>
#include <sstream>
#include <iomanip>
#include <bitset>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <stack>
#include <memory>
#include <deque>
#include <string_view>
#include <random>
#include <chrono>
#include <cstring>

using namespace std;

static int my_speed_up = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
using ll = long long; using ull = unsigned long long;
template<class T> using v = vector<T>;
template<class T> using vv = vector<vector<T>>;
template<class T> using vvv = vector<vector<vector<T>>>;
template<class T> using vvvv = vector<vector<vector<vector<T>>>>;
#define for_b(i, b) for (int i = 0; i < (b); ++i)
#define for_ab(i, a, b) for (int i = a; i < (b); ++i)
#define what_is(x) cout << #x << " = " << x << endl;
#define what_are(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define pad(x) for_b(i, x) cout << "  ";
#define show_1d(___x) cout << #___x << " = "; for (auto& ___num : ___x) cout << ___num << ", "; cout << endl;
#define show_2d(___x) cout << #___x << endl; for (auto& ___row : ___x) { for (auto ___num : ___row) cout << ___num << ", "; cout << endl; }
#define show_3d(___x) cout << #___x << endl; for (auto& ___row : ___x) { for (auto& ___row2 : ___row) { for (auto ___num : ___row2) cout << ___num << ", "; cout << endl; }cout << endl; }


int main()
{
    int v;
    cin >> v;
    
    if (v >= 30)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;
}