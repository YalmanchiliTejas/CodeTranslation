#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>
#include <set>
#include <numeric>

using namespace std;

template <typename T>
using TABLE = vector<vector<T>>;

using LONG = long long;
using LVEC = vector<long long>;

#define FOR(_i, s, e) for(_i = s; _i < e; ++_i)
#define FOR_INV(_i, s, e) for(_i = e - 1; _i >= s; --_i)

long long PRIME = 1e9 + 7;
long long PRIME2 = 998244353;


using pos = std::pair<LONG, LONG>;



int main(){
    LONG i, j, k;

    LONG N;
    cin >> N;

    multiset<LONG, greater<LONG>> colors;

    LONG A;
    FOR(i, 0, N){
        cin >> A;

        auto it = colors.upper_bound(A);
        if(it != colors.end()){
            colors.erase(it);
        }
        colors.insert(A);
    }

    cout << colors.size() << endl;

}
