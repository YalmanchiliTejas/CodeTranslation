#include "bits/stdc++.h"

using namespace std;

#define int long long
#define ll long long
typedef pair<int, int> P;
#define mod 998244353
#define INF (1LL<<60)

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define YES puts("YES\n")
#define Yes puts("Yes\n")
#define NO  puts("NO\n")
#define No  puts("No\n")
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }



signed main() {

	int N;
	cin >> N;
	vector<int> a(N);
	rep(i,N) cin >> a[i];
	
	vector<int> v;
	v.push_back(a[0]);

	for (int i = 1; i < N; i++) {

		auto it = upper_bound(v.begin(), v.end(), a[i], greater<int>());
		if (it == v.end())
			v.push_back(a[i]);
		else
			*it = a[i];
	}
	cout << v.size() << endl;

	return 0;
}