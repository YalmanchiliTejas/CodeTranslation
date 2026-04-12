#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;

const int mod = 1e9 + 7;

int mul(int a, int b) {
	return (ll) a * b % mod;
}
int my_pow(int a, int b) {
	int r = 1;
	while(b) {
		if(b % 2) r = mul(r, a);
		a = mul(a, a);
		b /= 2;
	}
	return r;
}
int my_inv(int a) { return my_pow(a, mod - 2); }

int f(vector<int> h) {
	h.push_back(1);
	int n = h.size();
	vector<int> dp(n);
	dp[n-1] = 1;
	for(int i = n - 2; i >= 0; --i) {
		dp[i] = mul(dp[i+1], 2); // not destroying
		if(i > 0 && h[i] <= h[i-1]) continue;
		const int prv = i ? h[i-1] : 1;
		int min_so_far = h[i];
		int multiplier = 2;
		for(int j = i + 1; j <= n - 1; ++j) {
			if(h[j] < min_so_far) {
				//~ int diff = max(0, min_so_far - max(h[j], prv));
				int low = max(h[j], prv) + 1;
				int high = min_so_far;
				swap(low, high);
				low = h[i] - low;
				high = h[i] - high;
				int a = low;
				int b = high;
				if(low <= high) {
					dp[i] = (dp[i] + mul(dp[j], mul(multiplier, mul(my_pow(2, a), my_pow(2, b - a + 1) - 1)))) % mod;
				}
				//~ for(int k = low; k <= high; ++k)
					//~ dp[i] = (dp[i] + mul(dp[j], mul(multiplier, my_pow(2, k)))) % mod;
				//~ dp[i] = (dp[i] + mul(dp[j], mul(2, diff)));
				min_so_far = h[j];
			}
			//~ if(h[j] > h[j-1]) multiplier = mul(2, multiplier);
			multiplier = mul(multiplier, my_pow(2, max(0, h[j] - h[j-1])));
		}
	}
	debug() << imie(dp);
	return dp[0];
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> h(n);
	for(int & x : h) scanf("%d", &x);
	int answer = 1;
	for(int i = 0; i < n; ++i) {
		if(h[i] > 1) {
			vector<int> gather;
			gather.push_back(h[i]);
			while(i + 1 < n && h[i+1] > 1) {
				++i;
				gather.push_back(h[i]);
			}
			answer = mul(answer, f(gather));
		}
		else answer = mul(answer, 2);
	}
	answer %= mod;
	if(answer < 0) answer += mod;
	printf("%d\n", answer);
	//~ int answer = 1 << (n - 1);
	//~ for(int i = 0; i < n; ++i) {
		//~ int prv = i ? h[i-1] : 0;
		//~ answer <<= max(0, h[i] - prv);
	//~ }
	//~ cout << answer << endl;
	/*vector<int> dp(2);
	// dp[0] = takie same, nie mozna wybierac :(
	dp[1] = 1;
	for(int ii = 0; ii < n; ++ii) {
		int here = h[ii];
		int prv = ii ? h[ii-1] : 0;
		int sure = 0;
		if(ii == 0) sure = here;
		else sure = max(0, here - prv);
		
	}
	int answer = (dp[0] + dp[1]) % mod;
	printf("%d\n", answer);*/
}
