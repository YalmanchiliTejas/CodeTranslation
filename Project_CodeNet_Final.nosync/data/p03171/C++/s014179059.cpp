#include<bits/stdc++.h>
using namespace std;

#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)


typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

template <class T>
using pqueue = priority_queue<T>;
template <class T>
using rpqueue = priority_queue<T, vector<T>, greater<T> >;


int sint() { int x; scanf("%d", &x); return x; }
ll sll() { ll x; scanf("%lld", &x); return x; }
double sdb() { double x; scanf("%lf", &x); return x; }

int arr[4000] = {};
ll memo[3100][3100][2] = {};

ll dp(int l, int r, int pos) {
	if(l > r) {
		return 0;
	} else if(memo[l][r][pos] != -1) {
		return memo[l][r][pos];
	} else if(pos) {
		return memo[l][r][pos] = min(dp(l+1, r, 1-pos)-arr[l], dp(l, r-1, 1-pos)-arr[r]);
	} else {
		return memo[l][r][pos] = max(dp(l+1, r, 1-pos)+arr[l], dp(l, r-1, 1-pos)+arr[r]);
	}
}

int main() {
	memset(memo, -1, sizeof(memo));
	
	int n = sint();
	for(int i = 0; i < n; i++) {
		arr[i] = sint();
	}
	
	printf("%lld\n", dp(0, n-1, 0));
}