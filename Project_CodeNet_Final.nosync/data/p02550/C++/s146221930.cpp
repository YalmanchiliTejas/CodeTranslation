#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
#include <math.h>
#include <numeric>
#include <assert.h>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <queue>
#include <random>
#include <chrono>
#include <limits.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define endl "\n"
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> OST;
typedef tree<pair<int, int>, null_type, less_equal<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> OST_multiset;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const ll inf = 1e9 + 69;
const ld pi = 3.14159265358979323L;
const ld eps = 1e-15;

void setIn(string s){freopen(s.c_str(), "r", stdin);}
void setOut(string s){freopen(s.c_str(), "w", stdout);}
void unsyncIO(){cin.tie(0) -> sync_with_stdio(0);}
int setIO_count = 0;
void setIO(string s = ""){
	if(!setIO_count){
		unsyncIO();
		setIO_count = 1;
	}
	if(s.size()){ //output only
		setIn(s + ".in");
		setOut(s + ".out");
	}
}

#define gc getchar//_unlocked //can't for window server
#define pc putchar//_unlocked //can't for window server
ll inp(){
	char c = gc(); bool neg = false;
	for(; c < '0'||'9' < c; c = gc())
		if(c == '-') neg=true;
	ll rs = c - '0'; c = gc();
	for(; '0' <= c && c <= '9'; c = gc())
		rs = (rs << 1) + (rs << 3) + (c - '0');
	if(neg) rs = -rs;
	return rs;
}
void pri(ll _n){
	ll N = _n, rev, count = 0;
	bool neg = false;
	if(N < 0){
		N = -N; neg = true;
	}
	rev = N;
	if(N == 0) {pc('0'); return;}
	if(neg) pc('-');
	while(rev % 10 == 0) {count ++; rev /= 10;}
	rev = 0;
	while(N != 0) {rev = (rev << 3) + (rev << 1) + N % 10; N /= 10;}
	while(rev != 0) {pc(rev % 10 + '0'); rev /= 10;}
	while(count --) pc('0');
}

const ll mod = 1e9 + 7;
const int N = 2 * 100 * 1000 + 5;

int main(){
	setIO("");

	ll n, x, m;
	cin >> n >> x >> m;

	vector<int> vis(m + 1, -1);
	vis[x] = 0;
	vector<int> li; li.push_back(x);
	ll nw = x;
	int bf = -1, cnt = 1;
	for(;;cnt ++){
		nw = (nw * 1ll * nw) % m;
		if(vis[nw] != -1){
			bf = vis[nw];
			break;
		}
		vis[nw] = cnt; li.push_back(nw);
	}

	ll sum = 0ll;
	for(int i = 0; i < min((ll)n, (ll)bf); i ++)
		sum += (ll)li[i];
	if(n <= bf){
		cout << sum << endl;
		return 0;
	}

	n -= bf;
	for(int i = 0; i < n % (cnt - bf); i ++)
		sum += (ll)li[i + bf];
	n /= (ll)(cnt - bf);
	ll tt = 0ll;
	for(int i = 0; i < cnt - bf; i ++)
		tt += (ll)li[i + bf];
	sum += tt * 1ll * n;
	cout << sum << endl;

	return 0;
}