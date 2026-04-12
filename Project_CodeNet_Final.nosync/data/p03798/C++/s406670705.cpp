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
        for(int i = 0; i < n; ++i){
            if(s[i] == 'o'){
                if(a[i]){
                    if(a[(i + 1) % n] == a[(i - 1 + n) % n])    return false;
                } else {
                    if(a[(i + 1) % n] != a[(i - 1 + n) % n])    return false;
                }
            } else {
                if(a[i]){
                    if(a[(i + 1) % n] != a[(i - 1 + n) % n])    return false;
                } else {
                    if(a[(i + 1) % n] == a[(i - 1 + n) % n])    return false;
                }
            }
        }
        return true;
    };
    // auto judge = [&](){
    //     if(s[n - 1] == 'o'){
    //         if(a[n - 1]){
    //             if(a[0] == a[n - 2])    return false;
    //         } else {
    //             if(a[0] != a[n - 2])    return false;
    //         }
    //     } else {
    //         if(a[n - 1]){
    //             if(a[0] != a[n - 2])    return false;
    //         } else {
    //             if(a[0] == a[n - 2])    return false;
    //         }
    //     }
    //     if(s[0] == 'o'){
    //         if(a[0]){
    //             if(a[1] == a[n - 1])    return false;
    //         } else {
    //             if(a[1] != a[n - 1])    return false;
    //         }
    //     } else {
    //         if(a[n - 1]){
    //             if(a[1] != a[n - 1])    return false;
    //         } else {
    //             if(a[1] == a[n - 1])    return false;
    //         }
    //     }
    //     return true;
    // };
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