//
#include <vector>
#include <set>
#include <array>
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <bitset>
//
using ll = long long;
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);++i)
inline void yes(bool cond) { cond ? puts("Yes") : puts("No"); }
template<typename Type> inline void chmin(Type& a, Type b) { if (a > b) a = b; }
template<typename Type> inline void chmax(Type& a, Type b) { if (a < b) a = b; }
#define BIGP   1000000007
#define INF_I  std::numeric_limits<ll>::max()
#define INF_F  std::numeric_limits<float>::infinity()
//
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    ll X;
    cin >> X;
    yes(30 <= X);
}