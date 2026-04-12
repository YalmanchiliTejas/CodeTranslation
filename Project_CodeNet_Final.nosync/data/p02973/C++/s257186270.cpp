#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<complex>
#include<functional>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<stack>
#include<set>

using namespace std;
#define endl '\n'
#define eb emplace_back
#define fst first
#define scd second

constexpr int mod = 1000000007;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

// value
int N;
int A[100010];

int backet[100];

void solve() {

	cin >> N;
	multiset<int> mm;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		auto it = mm.lower_bound(A[i]);
		if (it != mm.begin()) {
			mm.erase(--it);
		}
		mm.insert(A[i]);
	}

	cout << mm.size() << endl;

	return;

}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	solve();

	return 0;

}
