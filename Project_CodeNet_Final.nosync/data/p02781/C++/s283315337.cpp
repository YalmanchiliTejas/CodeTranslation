#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;

typedef vector<vll> vvll;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef vector<pll> vpll;
typedef vector<plli> vplli;
typedef vector<pill> vpill;

#define mem(A, N) memset(A, N, sizeof(A))
#define F first
#define S second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define rep(i, x, y)  for(int i = x; i < y; ++i)
#define Rep(i, x, y)  for(int i = x; i <= y; ++i)
#define srep(i, x, y) for(int i = x; i > y; --i)
#define sRep(i, x, y) for(int i = x; i >= y; --i)
#define All(v) v.begin(),v.end()
#define sortA(a) sort(a, a+n)
#define SortA(a) sort(a + 1, a + n + 1)
#define sortArr(a, i, n) sort(a+i, a+n)
#define SortArr(a, i, n) sort(a+i, a+n+1)
#define Sort(x) sort(x.begin(), x.end())
#define concatenate(a, b) std::copy(b.begin(), b.end(), std::back_inserter(a));
#define fcout(x) cout << fixed << setprecision(x)
#define ifcout(x, a, b) if(x) cout << a << '\n'; else cout << b << '\n'
#define makeUnique(v) v.erase(unique(v.begin(), v.end()), v.end())
#define inRange(x, y, z) (x <= y && y < z)
#define min3(a, b, c) (min(min(a, b), c))
#define max3(a, b, c) (max(max(a, b), c))

static constexpr int inf = 1'000'000'001;
static constexpr int ninf = -1'000'000'001;
static constexpr long long llInf = 2'000'000'000'000'000'001LL;
static constexpr long long nllInf = -2'000'000'000'000'000'001LL;

static constexpr double Pi = 3.14159265358979323846;
static constexpr double eps = 1e-9;
static constexpr int mod = 1000000007;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", ", _print(v...);}

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif

// ***************** End Of Template ********************



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s; cin >> s; int k; cin >> k;
	if(k == 1) {
		ll ans = 0;
		int i = 1;
		int n = s.length();
		while(i <= n - 1) {
			ans += 9;
			i++;
		}
		ans += (s[0] - '0');
		cout << ans << '\n';
	}
	else if(k == 2) {
		if(s.length() <= 1) {
			cout << 0 << '\n';
			return 0;
		}
		int n = s.length();
		int p = 2;
		ll ans = 0;
		while(p <= n - 1) {
			ans += 9LL * (p - 1) * 9;
			p++;
		}
		
		int lead = (s[0] - '0');
		ans += (ll) (lead - 1) * (n - 1) * 9;
		
		Rep(i, 1, n - 1) {
			if(s[i] > '0') {
				ans += (ll) (s[i] - '0');
				int leftD = n - i - 1;
				if(leftD >= 1) {
					ans += (ll) leftD * 9;
				}
				break;
			}
		}

		cout << ans << '\n';
	}
	else {
		if(s.length() <= 2) {
			cout << 0 << '\n';
			return 0;
		}
		int n = s.length();
		
		int p = 3;
		ll ans = 0;
		while(p <= n - 1) {
			Rep(j, 1, p - 2) {
				ans += 9LL * 9 * (p - j - 1) * 9;
			}
			p++;
		}

		int lead = (s[0] - '0');
		Rep(j, 1, n - 2) {
			ans += (ll) (lead - 1) * 9 * (n - j - 1) * 9;
		}

		bool found = false;
		Rep(i, 1, n - 2) {
			if(!found) {
				if(s[i] > '0') {
					found = true;
					
					int secondLead = (s[i] - '0');
					ans += (ll) (secondLead - 1) * (n - i - 1) * 9;
					
					bool first = true;
					Rep(j, i + 1, n - 1) {
						if(first) {
							if(s[j] > '0') {
									ans += (s[j] - '0');
									first = false;
							}
						}
						else {
							ans += 9;
						}
					}
				}
			}
			else {
				ans += 9LL * (n - i - 1) * 9;
			}
		}

		cout << ans << '\n';
	}
	return 0;
}