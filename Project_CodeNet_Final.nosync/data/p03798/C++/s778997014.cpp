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

typedef long long ll;
typedef uint64_t ull;
typedef pair<int, int> P;
constexpr double PI = 3.1415926535897932;   // acos(-1)
constexpr double EPS = 1e-9;
constexpr int INF = 1001001001;
constexpr int mod = 1000000007;
// constexpr int mod = 998244353;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define chadd(x, y) x = (x + y) % mod

void output(vector<int>& v){
    int sz = v.size();
    for(int i = 0; i < sz; ++i){
        if(v[i] == 1)   cout << 'W';
        if(v[i] == 0)   cout << 'S';
    }
    cout << endl;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    // 0 : 'S', 1 : 'W'
    if(s[0] == 'o'){
        bool ok = false;

        vector<int> foo(n);
        foo[0] = 0, foo[1] = 0;
        for(int i = 1; i + 1 < n; ++i){
            if(s[i] == 'o'){
                if(foo[i] == 0) foo[i + 1] = foo[i - 1];
                else    foo[i + 1] = foo[i - 1] ^ 1;
            }
            else{
                if(foo[i] == 0) foo[i + 1] = foo[i - 1] ^ 1;
                else    foo[i + 1] = foo[i - 1];
            }
        }
        if(s[n - 1] == 'o'){
            bool b1 = (foo[n - 1] == 0) ? (foo[n - 2] == foo[0]) : (foo[n - 2] != foo[0]);
            if(s[0] == 'o'){
                bool b2 = (foo[0] == 0) ? (foo[1] == foo[n - 1]) : (foo[1] != foo[n - 1]);
                ok = b1 & b2;
            }
            else{
                bool b2 = (foo[0] == 0) ? (foo[1] != foo[n - 1]) : (foo[1] == foo[n - 1]);
                ok = b1 & b2;
            }
        }
        else{
            bool b1 = (foo[n - 1] == 0) ? (foo[n - 2] != foo[0]) : (foo[n - 2] == foo[0]);
            if(s[0] == 'o'){
                bool b2 = (foo[0] == 0) ? (foo[1] == foo[n - 1]) : (foo[1] != foo[n - 1]);
                ok = b1 & b2;
            }
            else{
                bool b2 = (foo[0] == 0) ? (foo[1] != foo[n - 1]) : (foo[1] == foo[n - 1]);
                ok = b1 & b2;
            }
        }
        if(ok){
            output(foo);
            return 0;
        }

        foo[0] = 0, foo[1] = 1;
        for(int i = 1; i + 1 < n; ++i){
            if(s[i] == 'o'){
                if(foo[i] == 0) foo[i + 1] = foo[i - 1];
                else    foo[i + 1] = foo[i - 1] ^ 1;
            }
            else{
                if(foo[i] == 0) foo[i + 1] = foo[i - 1] ^ 1;
                else    foo[i + 1] = foo[i - 1];
            }
        }
        if(s[n - 1] == 'o'){
            bool b1 = (foo[n - 1] == 0) ? (foo[n - 2] == foo[0]) : (foo[n - 2] != foo[0]);
            if(s[0] == 'o'){
                bool b2 = (foo[0] == 0) ? (foo[1] == foo[n - 1]) : (foo[1] != foo[n - 1]);
                ok = b1 & b2;
            }
            else{
                bool b2 = (foo[0] == 0) ? (foo[1] != foo[n - 1]) : (foo[1] == foo[n - 1]);
                ok = b1 & b2;
            }
        }
        else{
            bool b1 = (foo[n - 1] == 0) ? (foo[n - 2] != foo[0]) : (foo[n - 2] == foo[0]);
            if(s[0] == 'o'){
                bool b2 = (foo[0] == 0) ? (foo[1] == foo[n - 1]) : (foo[1] != foo[n - 1]);
                ok = b1 & b2;
            }
            else{
                bool b2 = (foo[0] == 0) ? (foo[1] != foo[n - 1]) : (foo[1] == foo[n - 1]);
                ok = b1 & b2;
            }
        }
        if(ok){
            output(foo);
            return 0;
        }

        foo[0] = 1, foo[1] = 0;
        for(int i = 1; i + 1 < n; ++i){
            if(s[i] == 'o'){
                if(foo[i] == 0) foo[i + 1] = foo[i - 1];
                else    foo[i + 1] = foo[i - 1] ^ 1;
            }
            else{
                if(foo[i] == 0) foo[i + 1] = foo[i - 1] ^ 1;
                else    foo[i + 1] = foo[i - 1];
            }
        }
        if(s[n - 1] == 'o'){
            bool b1 = (foo[n - 1] == 0) ? (foo[n - 2] == foo[0]) : (foo[n - 2] != foo[0]);
            if(s[0] == 'o'){
                bool b2 = (foo[0] == 0) ? (foo[1] == foo[n - 1]) : (foo[1] != foo[n - 1]);
                ok = b1 & b2;
            }
            else{
                bool b2 = (foo[0] == 0) ? (foo[1] != foo[n - 1]) : (foo[1] == foo[n - 1]);
                ok = b1 & b2;
            }
        }
        else{
            bool b1 = (foo[n - 1] == 0) ? (foo[n - 2] != foo[0]) : (foo[n - 2] == foo[0]);
            if(s[0] == 'o'){
                bool b2 = (foo[0] == 0) ? (foo[1] == foo[n - 1]) : (foo[1] != foo[n - 1]);
                ok = b1 & b2;
            }
            else{
                bool b2 = (foo[0] == 0) ? (foo[1] != foo[n - 1]) : (foo[1] == foo[n - 1]);
                ok = b1 & b2;
            }
        }
        if(ok){
            output(foo);
            return 0;
        }

        foo[0] = 1, foo[1] = 1;
        for(int i = 1; i + 1 < n; ++i){
            if(s[i] == 'o'){
                if(foo[i] == 0) foo[i + 1] = foo[i - 1];
                else    foo[i + 1] = foo[i - 1] ^ 1;
            }
            else{
                if(foo[i] == 0) foo[i + 1] = foo[i - 1] ^ 1;
                else    foo[i + 1] = foo[i - 1];
            }
        }
        if(s[n - 1] == 'o'){
            bool b1 = (foo[n - 1] == 0) ? (foo[n - 2] == foo[0]) : (foo[n - 2] != foo[0]);
            if(s[0] == 'o'){
                bool b2 = (foo[0] == 0) ? (foo[1] == foo[n - 1]) : (foo[1] != foo[n - 1]);
                ok = b1 & b2;
            }
            else{
                bool b2 = (foo[0] == 0) ? (foo[1] != foo[n - 1]) : (foo[1] == foo[n - 1]);
                ok = b1 & b2;
            }
        }
        else{
            bool b1 = (foo[n - 1] == 0) ? (foo[n - 2] != foo[0]) : (foo[n - 2] == foo[0]);
            if(s[0] == 'o'){
                bool b2 = (foo[0] == 0) ? (foo[1] == foo[n - 1]) : (foo[1] != foo[n - 1]);
                ok = b1 & b2;
            }
            else{
                bool b2 = (foo[0] == 0) ? (foo[1] != foo[n - 1]) : (foo[1] == foo[n - 1]);
                ok = b1 & b2;
            }
        }
        if(ok){
            output(foo);
            return 0;
        }
    }

    else{
        bool ok = false;
        vector<int> foo(n);
        foo[0] = 1, foo[1] = 1;
        for(int i = 1; i + 1 < n; ++i){
            if(s[i] == 'o'){
                if(foo[i] == 0) foo[i + 1] = foo[i - 1];
                else    foo[i + 1] = foo[i - 1] ^ 1;
            }
            else{
                if(foo[i] == 0) foo[i + 1] = foo[i - 1] ^ 1;
                else    foo[i + 1] = foo[i - 1];
            }
        }
        if(s[n - 1] == 'o'){
            bool b1 = (foo[n - 1] == 0) ? (foo[n - 2] == foo[0]) : (foo[n - 2] != foo[0]);
            if(s[0] == 'o'){
                bool b2 = (foo[0] == 0) ? (foo[1] == foo[n - 1]) : (foo[1] != foo[n - 1]);
                ok = b1 & b2;
            }
            else{
                bool b2 = (foo[0] == 0) ? (foo[1] != foo[n - 1]) : (foo[1] == foo[n - 1]);
                ok = b1 & b2;
            }
        }
        else{
            bool b1 = (foo[n - 1] == 0) ? (foo[n - 2] != foo[0]) : (foo[n - 2] == foo[0]);
            if(s[0] == 'o'){
                bool b2 = (foo[0] == 0) ? (foo[1] == foo[n - 1]) : (foo[1] != foo[n - 1]);
                ok = b1 & b2;
            }
            else{
                bool b2 = (foo[0] == 0) ? (foo[1] != foo[n - 1]) : (foo[1] == foo[n - 1]);
                ok = b1 & b2;
            }
        }
        if(ok){
            output(foo);
            return 0;
        }

        foo[0] = 1, foo[1] = 0;
        for(int i = 1; i + 1 < n; ++i){
            if(s[i] == 'o'){
                if(foo[i] == 0) foo[i + 1] = foo[i - 1];
                else    foo[i + 1] = foo[i - 1] ^ 1;
            }
            else{
                if(foo[i] == 0) foo[i + 1] = foo[i - 1] ^ 1;
                else    foo[i + 1] = foo[i - 1];
            }
        }
        if(s[n - 1] == 'o'){
            bool b1 = (foo[n - 1] == 0) ? (foo[n - 2] == foo[0]) : (foo[n - 2] != foo[0]);
            if(s[0] == 'o'){
                bool b2 = (foo[0] == 0) ? (foo[1] == foo[n - 1]) : (foo[1] != foo[n - 1]);
                ok = b1 & b2;
            }
            else{
                bool b2 = (foo[0] == 0) ? (foo[1] != foo[n - 1]) : (foo[1] == foo[n - 1]);
                ok = b1 & b2;
            }
        }
        else{
            bool b1 = (foo[n - 1] == 0) ? (foo[n - 2] != foo[0]) : (foo[n - 2] == foo[0]);
            if(s[0] == 'o'){
                bool b2 = (foo[0] == 0) ? (foo[1] == foo[n - 1]) : (foo[1] != foo[n - 1]);
                ok = b1 & b2;
            }
            else{
                bool b2 = (foo[0] == 0) ? (foo[1] != foo[n - 1]) : (foo[1] == foo[n - 1]);
                ok = b1 & b2;
            }
        }
        if(ok){
            output(foo);
            return 0;
        }

        foo[0] = 0, foo[1] = 0;
        for(int i = 1; i + 1 < n; ++i){
            if(s[i] == 'o'){
                if(foo[i] == 0) foo[i + 1] = foo[i - 1];
                else    foo[i + 1] = foo[i - 1] ^ 1;
            }
            else{
                if(foo[i] == 0) foo[i + 1] = foo[i - 1] ^ 1;
                else    foo[i + 1] = foo[i - 1];
            }
        }
        if(s[n - 1] == 'o'){
            bool b1 = (foo[n - 1] == 0) ? (foo[n - 2] == foo[0]) : (foo[n - 2] != foo[0]);
            if(s[0] == 'o'){
                bool b2 = (foo[0] == 0) ? (foo[1] == foo[n - 1]) : (foo[1] != foo[n - 1]);
                ok = b1 & b2;
            }
            else{
                bool b2 = (foo[0] == 0) ? (foo[1] != foo[n - 1]) : (foo[1] == foo[n - 1]);
                ok = b1 & b2;
            }
        }
        else{
            bool b1 = (foo[n - 1] == 0) ? (foo[n - 2] != foo[0]) : (foo[n - 2] == foo[0]);
            if(s[0] == 'o'){
                bool b2 = (foo[0] == 0) ? (foo[1] == foo[n - 1]) : (foo[1] != foo[n - 1]);
                ok = b1 & b2;
            }
            else{
                bool b2 = (foo[0] == 0) ? (foo[1] != foo[n - 1]) : (foo[1] == foo[n - 1]);
                ok = b1 & b2;
            }
        }
        if(ok){
            output(foo);
            return 0;
        }

        foo[0] = 0, foo[1] = 1;
        for(int i = 1; i + 1 < n; ++i){
            if(s[i] == 'o'){
                if(foo[i] == 0) foo[i + 1] = foo[i - 1];
                else    foo[i + 1] = foo[i - 1] ^ 1;
            }
            else{
                if(foo[i] == 0) foo[i + 1] = foo[i - 1] ^ 1;
                else    foo[i + 1] = foo[i - 1];
            }
        }
        if(s[n - 1] == 'o'){
            bool b1 = (foo[n - 1] == 0) ? (foo[n - 2] == foo[0]) : (foo[n - 2] != foo[0]);
            if(s[0] == 'o'){
                bool b2 = (foo[0] == 0) ? (foo[1] == foo[n - 1]) : (foo[1] != foo[n - 1]);
                ok = b1 & b2;
            }
            else{
                bool b2 = (foo[0] == 0) ? (foo[1] != foo[n - 1]) : (foo[1] == foo[n - 1]);
                ok = b1 & b2;
            }
        }
        else{
            bool b1 = (foo[n - 1] == 0) ? (foo[n - 2] != foo[0]) : (foo[n - 2] == foo[0]);
            if(s[0] == 'o'){
                bool b2 = (foo[0] == 0) ? (foo[1] == foo[n - 1]) : (foo[1] != foo[n - 1]);
                ok = b1 & b2;
            }
            else{
                bool b2 = (foo[0] == 0) ? (foo[1] != foo[n - 1]) : (foo[1] == foo[n - 1]);
                ok = b1 & b2;
            }
        }
        if(ok){
            output(foo);
            return 0;
        }
    }

    cout << -1 << endl;
}