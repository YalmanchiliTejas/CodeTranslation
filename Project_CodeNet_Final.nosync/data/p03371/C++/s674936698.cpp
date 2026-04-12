#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <queue>
#include <random>
#include <bitset>
#include <time.h>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
//#define endl '\n'
#define mp make_pair
#define pbc push_back
#define pob pop_back()
#define empb emplace_back
#define sp system("pause")
#define queuel queue<long long>
#define all(x) (x).begin(),(x).end()
#define matrix vector<vector<ll>>
#define pin(p) cin >> p.first >> p.second;
#define rev(v) reverse(v.begin(),v.end());
#define mx(v) max_element(v.begin(), v.end());
#define mn(v) min_element(v.begin(), v.end());
#define sout(s, c) for(auto i : s) cout << i << c;
#define pout(p) cout << p.first << " " << p.second;
#define er(v, l, r) erase(v.begin() + l, v.begin() + r);
#define vin(v) for(ll i = 0; i < v.size(); ++i) cin >> v[i];
#define vout(v, c) for(int i = 0; i < v.size(); ++i) cout << v[i] << c;
#define pushi(v, a) for(int i = 0; i < a.size(); ++i) v.push_back(a[i]);
#define sin(s, n) for(int i = 0; i < n; ++i){int a; cin >> a; s.insert(a);}
#define fastio() ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);srand(time(NULL));
//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
using namespace std;
//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
const ll INF = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
const int inf = 1000 * 1000 * 1000;
const ld PI = acos(-1.0);
const ll mod1 = inf + 7;
const ll mod2 = inf + 9;
const int MAXN = 500001;
const ld EPS = 1e-9;
int hp = 179;

signed main()
{
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans = inf;
	for (int ab = 0; ab <= 2 * max(x, y); ab += 2)
	{
		int tans = ab * c + max(x - ab / 2, 0) * a + max(y - ab / 2, 0) * b;
		ans = min(ans, tans);
	}
	cout << ans;
}	