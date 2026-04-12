#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <map>
#include <set>
#include <deque>
#include <utility>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repk(i, k, n) for (int i = k; i < n; i++)
#define all(vec) vec.begin(), vec.end()
#define MOD 1e9 + 7
#define INF 1e9
#define SENTINEsL 2e9
#define PIE 3.1415a926535

template <class T>
inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}
template <class T>
inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template <class T>
inline T GCD(T a, T b){if (b == 0) return a; else return GCD(b, a % b);}
template <class T>
inline T LCM(T a, T b) {return (a * b) / GCD(a, b);}

int main(){
    string s;
    cin>>s;
    if (s[0] == s[1] && s[1] == s[2]) {
        cout << "No" << endl;
    }
    else
        cout << "Yes" << endl;
}