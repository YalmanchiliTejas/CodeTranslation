#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <cstdlib>
#define rep(i,n) for(int i = 0;i<(n);i++);
#define all(a) (a).begin(),(a).end()
using namespace std;
using ld = long double;
using ll = long long;
const ll INF = 100100100;
typedef pair<ll, ll> P;
ll gcd(ll a, ll b) {//a>b
	if (a < b)swap(a, b);
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}
int main() {
	ll n;
	cin >> n;
	vector<ll> num(n);
	for (int i = 0; i < n; i++)cin >> num[i];
	vector<ll> ans(n);
	if (n % 2 == 0) {
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0)ans[n / 2 + i / 2] = num[i];
			else ans[n / 2 - 1 - i / 2] = num[i];
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0)ans[n / 2 - i / 2] = num[i];
			else ans[n / 2 + i / 2 + 1] = num[i];
		}
	}
	for (int i = 0; i < n; i++)cout << ans[i] << " ";
	cout << endl;
}