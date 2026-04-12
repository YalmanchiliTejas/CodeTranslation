#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

	int n; cin >> n;
	vector<ll> v(n);
	for(ll& i : v) cin >> i;

	vector<ll> memo(n+1);

	for(int sz=1; sz<=n; sz++) {
		for(int i=0; i<=n-sz; i++) {
			if(sz%2 == n%2) memo[i] = max(memo[i]+v[i+sz-1], memo[i+1]+v[i]);
			else memo[i] = min(memo[i]-v[i+sz-1], memo[i+1]-v[i]);
		}
	}

	cout << memo[0] << endl;

	return 0;
}
