#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()
#define END return 0
typedef int64_t ll;
const int mod7 = 1e9 + 7;
const int mod9 = 1e9 + 9;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
template<typename T> T gcd(T a, T b) {return b ? gcd(b, a % b) : abs(a);}
template<typename T> T lcm(T a, T b) {return a / gcd(a, b) * b;}
template<typename T> bool chmax(T &a, T b) {if (a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if (a > b) {a = b; return true;} return false;}
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val) {fill((T*)array, (T*)(array+N), val);}

int main() {
    int n, m;
    cin >> n >> m;
    if(n == m) cout << "Yes" << endl;
    else cout << "No" << endl;
}