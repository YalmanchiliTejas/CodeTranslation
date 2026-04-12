#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <functional>
#include <cctype>
#include <list>
#include <limits>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>



using namespace std;
using Int = long long;
//using namespace boost::multiprecision;

const double EPS = 1e-10;
long long const MOD = 1000000007;

long long mod_pow(long long x, long long n) {
    long long res = 1;
    for (int i = 0;i < 60; i++) {
        if (n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

template<typename T>
T gcd(T a, T b) {
    return b != 0 ? gcd(b, a % b) : a;
}

template<typename T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

void fastInput() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

vector<long long> Divisor(long long n) {
    vector<long long> ret;
    for(long long i=1; i*i<=n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i*i!=n) ret.push_back(n / i);
        }
    }
    return ret;
}

int main(void) {
    int N; cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    map<long long, int> colors;
    for (int i = 0; i < N; i++) {
        auto itr = colors.lower_bound(a[i]);
        if (itr == colors.begin() || colors.size() == 0) {
            if (colors.count(a[i])) colors[a[i]]++;
            else colors[a[i]] = 1;
        } else {
            itr--;
            itr->second--;
            if (itr->second == 0) {
                colors.erase(itr);
            }
            if (colors.count(a[i])) colors[a[i]]++;
            else colors[a[i]] = 1;
        }
    }
    long long ans = 0;
    for (auto &itr : colors) {
        ans += itr.second;
    }
    cout << ans << endl;
}