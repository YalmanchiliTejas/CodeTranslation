#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long long ll;
constexpr double PI = 3.141592653589793;
constexpr int INF = 1e9 + 10;
constexpr ll INFL = 1e18 + 10;

template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}

using namespace std;
//    cout << setprecision(20) << ans << "\n";



int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x;
    cin >> x;
    if (x >= 30){
        cout << "Yes"
             << "\n";
        return 0;
    }
    cout << "No"
         << "\n";
    return 0;
}
