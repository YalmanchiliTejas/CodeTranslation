#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
template<class T> inline void chmin(T& a, T b) {if (a>b) a=b; }
template<class T> inline void chmax(T& a, T b) {if (a<b) a=b; }
inline void print() { cout << endl; }
template <class Head, class... Tail> inline void print(Head&& head, Tail&&... tail) {cout << head; if (sizeof...(tail) != 0) cout << " "; print(forward<Tail>(tail)...);}
template <class T> inline void print(vector<T>& vec) { for (auto& a : vec) {cout << a; if (&a != &vec.back()) cout << " "; } cout << endl;}
template <class T> inline void print(vector<vector<T>>& df) { for (auto& vec : df) { print(vec); }}
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;

vector<ll> a;
vector<ll> p;

ll rec(ll n, ll x) {
    if (n==0) {
        return 1;
    } else if (x == 1) {
        return 0;
    } else if (x <= a[n-1] + 1) {
        return rec(n-1, x-1);
    } else if (x == 2 + a[n-1]) {
        return p[n-1] + 1;
    } else if (x < 2 + 2*a[n-1]) {
        return p[n-1] + 1 + rec(n-1, x - 2 - a[n-1]);
    } else {
        return p[n];
    }
}

int main() { 
    ll N; cin >> N;
    ll X; cin >> X;

    a.push_back(1);
    p.push_back(1);
    REP(i, N) {
        a.push_back(2*a[i]+3);
        p.push_back(2*p[i]+1);
    }

    cout << rec(N, X) << endl;
    
    return 0;
}