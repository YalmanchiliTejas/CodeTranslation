#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>
#include <list>
#include <limits>
#include <unordered_map>
#define Debug 0
//#include <boost/multiprecision/cpp_int.hpp>

const double EPS = (1e-10);


using namespace std;
using Int = long long;
//using namespace boost::multiprecision;

const Int MOD = 1000000007;

Int mod_pow(Int x, Int n) {
    Int res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % MOD; //ビット演算(最下位ビットが1のとき)
        x = (x * x) % MOD;
        n >>= 1; //右シフト(n = n >> 1)
    }
    return res;
}

//最大公約数
template<typename T>
T gcd(T a, T b) {
    return b != 0 ? gcd(b, a % b) : a;
}

//最小公倍数
template<typename T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

void fast_input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int h[21];

int main(){
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    int ma = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (ma <= h[i]) ans++;
        ma = max(h[i], ma);
    }
    cout << ans << endl;
}


