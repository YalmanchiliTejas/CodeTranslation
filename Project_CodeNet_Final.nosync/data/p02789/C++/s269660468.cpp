#pragma region RegionDefs
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include "boost/multi_array.hpp"
#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define reps(i,j,n) for(int i=(j),i##_len=(n);i<i##_len;++i)
#define repr(i,n) for(int i=(n);i>=0;--i)
#define all(x) begin(x),end(x)
using namespace std;
template<class T=int> using P  = pair<T, T>;
template<class T=int> using V  = vector<T>;
template<class T=int> using PQ = priority_queue<T>;
template<class T=int> using PQG = priority_queue<T, V<T>, greater<T>>;
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1000000007LL;
void in() {}
template<class Head, class... Tail>
void in(Head&& head, Tail&&... tail)
{
    cin >> head;
    in(move(tail)...);
}
#define IN(...) ll __VA_ARGS__; in(__VA_ARGS__)
//時間が厳しいとき使う
#define INI(...) int __VA_ARGS__; in(__VA_ARGS__)
#define INS(T, ...) T __VA_ARGS__; in(__VA_ARGS__)
#define VIN(T, v, n) V<T> v(n); for(auto& _elem:v)cin>>_elem
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if (a>b) {a=b; return 1;} return 0;}
#define y0 y__0
#define y1 y__1
#define j0 j__0
#define j1 j__1
#pragma endregion RegionDefs

void solve()
{
    IN(n, m);
    cout << (n == m ? "Yes" : "No") << endl;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(numeric_limits<double>::max_digits10);

    solve();

    return 0;
}