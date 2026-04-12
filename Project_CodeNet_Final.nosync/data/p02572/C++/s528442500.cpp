using namespace std;
#include<string>
#include<cmath>
#include<list>
#include <map>
#include <unordered_map>
#include <set>
#define ll long long
#define ld long double
#define ull unsigned long long
#define ml map<ll,ll>
#define pb push_back
#define mp make_pair
#define ppl pair<ll,ll>
#define F first
#define S second
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#define fr(i,a,b) for(ll i=a;i<b;i++)
#define ffr(i,a,b) for(ll i=a;i>=b;i--)
#include<bits/stdc++.h>
#include<vector>
#define vl vector<ll>
#define PI 3.141592654
const ll N = 1e9 + 7;
#include<iterator>
#define EPSILON numeric_limits<double>::epsilon()





void solve() {
	ll n, sumsq = 0, sum = 0; cin >> n;
	ll a[n], sums[n - 1];
	fr(i, 0, n) {
		cin >> a[i];
		sum += (a[i] % N);
	}
	fr(i, 0, n - 1) {
		sums[i] = (sum - a[i]) % N;
		sum -= a[i];
	}
	fr(i, 0, n - 1) {
		sumsq += (sums[i] * a[i]) % N;
	}
	cout << sumsq % N;
}






int main() {
	fio;
#ifndef ONLINE_JUDGE
	// for getting input
	freopen("input.txt", "r", stdin);
	//for writing output
	freopen("jout.txt", "w", stdout);
#endif

	ll t;
	if (1)
		t = 1;
	else
		cin >> t;
	while (t--) {
		//cout << "Case #" << h << ": ";
		solve();
		//h++;
		cout << '\n';
	}
	return 0;
}




