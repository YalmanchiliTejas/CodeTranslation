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

vector<int> ans;
int solve(int N){
    int ma = -1;
    int mi = 1001;
    int sum = 0;
    for (int i = 0; i < N; i++){
        int s; cin >> s;
        sum += s;
        mi = min(mi, s);
        ma = max(ma, s);
    }
    return (sum - mi - ma)/(N-2);
}

int main(){
    cin.tie(0);

    int N;
    while (1){
        cin >> N;
        if (!N) break;
        ans.push_back(solve(N));
    }
    for (auto itr = ans.begin(); itr != ans.end(); itr++){
        cout << *itr << endl;
    }

}


