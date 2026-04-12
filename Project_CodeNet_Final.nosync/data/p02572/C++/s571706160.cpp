/**
 * Author : RDP
 * There are no two words in the English language more harmful than "good job".
 * 1729 ;)
**/
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <numeric>
using namespace std;
using ll = long long;
#define endl '\n'
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) 
{
  cerr << " " << to_string(H);
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define FAST_IO ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define bp(x) __builtin_popcount(x)
#define zf(x) __builtin_clz(x)
#define zl(x) __builtin_ctz(x)
#define par(x) __bultin_parity(x)
#define all(x) (x).begin(), (x).end()
/* **************************************************************************************** */
const ll MOD = 1e9 + 7;
void test_case()
{
    int n;
    cin >> n;
    vector <ll> a(n);
    for(ll &x : a) cin >> x;
    vector <ll> prefix(n + 1);
    prefix[0] = 0;
    for(int i = 1; i <= n; i ++)
    {
        prefix[i] = (prefix[i - 1] + a[i - 1]) % MOD;
    }

    ll ans = 0;
    for(int i = 1; i < n; i ++)
    {
        ll add = (prefix[n] - prefix[i] + MOD ) % MOD;
        add = (add * a[i - 1]) % MOD;
        ans = (ans + add ) % MOD;
    }

    cout << ans << endl;
}
int main()
{
	FAST_IO
    int t = 1;
    //cin >> t;
    while(t--)
        test_case();
	return 0;
}