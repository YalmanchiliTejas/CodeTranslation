/*
 * short          2^15-1 ~ 3e4
 * int, long x86  2^31-1 ~ 2e9
 * long long      2^63-1 ~ 9e18
 */
#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define fr(a, b) for (int a = 0; a < b; ++a)
using namespace std; typedef long long ll; const int inf = numeric_limits<int>::max(); void print() {cerr << endl;}
template<typename T, typename... Ts> void print(T&&a, Ts&&...etc) {cerr << a << ' '; print(etc...);}
template<typename T, typename U> ostream& operator<<(ostream& s, const pair<T,U>&p) {s << "<" << p.x << ", " << p.y << ">"; return s;} // ver. 2020-02-17
template<typename T> ostream& operator<<(ostream& s, const vector<T>&v) {s << "["; for (auto &x : v) s << x << ", "; if (!v.empty()) s << "\b\b"; s << "]"; return s;}
struct io{io(){ios_base::Init i; ios_base::sync_with_stdio(0); cin.tie(0);}}io;

int main() {
    string s;
    cin >> s;
    int a = 0, b = 0;
    fr(i,3) {
        if (s[i]=='A') ++a;
        else ++b;
    }
    cout << (a * b > 0 ? "Yes" : "No") << endl;
    return 0;
}
