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

using ll = long long;
using ull = uint64_t;
using P = pair<int, int>;
constexpr double EPS = 1e-9;
constexpr int INF = 1001001001;
constexpr int mod = 1000000007;
// constexpr int mod = 998244353;

template<class T>
inline bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}
template<class T>
inline bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    
    vector<int> a(n);
    auto construct = [&](){
        for(int i = 1; i + 1 < n; ++i){
            int val = a[i];
            if(s[i] == 'x') val ^= 1;
            a[i + 1] = a[i - 1] ^ val;
        }
        return;
    };
    auto judge = [&](){
        bool ok;
        if(s[n - 1] == 'o'){
            bool b1 = (a[n - 1] == 0) ? (a[n - 2] == a[0]) : (a[n - 2] != a[0]);
            if(s[0] == 'o'){
                bool b2 = (a[0] == 0) ? (a[1] == a[n - 1]) : (a[1] != a[n - 1]);
                ok = b1 & b2;
            }
            else{
                bool b2 = (a[0] == 0) ? (a[1] != a[n - 1]) : (a[1] == a[n - 1]);
                ok = b1 & b2;
            }
        }
        else{
            bool b1 = (a[n - 1] == 0) ? (a[n - 2] != a[0]) : (a[n - 2] == a[0]);
            if(s[0] == 'o'){
                bool b2 = (a[0] == 0) ? (a[1] == a[n - 1]) : (a[1] != a[n - 1]);
                ok = b1 & b2;
            }
            else{
                bool b2 = (a[0] == 0) ? (a[1] != a[n - 1]) : (a[1] == a[n - 1]);
                ok = b1 & b2;
            }
        }
        return ok;
    };
    auto output = [&](){
        for(int i = 0; i < n; ++i){
            if(a[i])    cout << 'W';
            else    cout << 'S';
        }
        cout << endl;
        return;
    };

    for(int i = 0; i <= 1; ++i){
        a[0] = i;
        for(int j = 0; j <= 1; ++j){
            a[1] = j;
            construct();
            if(judge()){
                output();
                return 0;
            }
        }
    }
    cout << -1 << endl;
}