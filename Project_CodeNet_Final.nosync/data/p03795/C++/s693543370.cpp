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
#define MOD 1e9 + 7
#define INF 1e9
#define SENTINEL 2e9
#define PIE 3.14159265358979323

template <class T>
inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}
template <class T>
inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template <class T>
inline T GCD(T a, T b){if (b == 0) return a; else return GCD(b, a % b);}
template <class T>
inline T LCM(T a, T b) {return (a * b) / GCD(a, b);}

//困ったら全探索
//全探索をしろ
//範囲を絞ればACするはずだ

int main(){
    int n;
    cin >> n;
    int x = 800*n;
    int y = 200*(n / 15);
    cout << x - y << endl;
}