using namespace std;
#include<string>
#include<cmath>
#include <map>
#include <unordered_map>
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
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
const ll N = 1e9;
#include<iterator>

void solve() {
	ll x; cin >> x;
	if (x >= 30)cout << "Yes";
	else cout << "No";
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
		//cout << "Case #" << h << ":\n";
		solve();
		//h++;
		cout << '\n';
	}
	return 0;
}
