/* 
* code by: imasnegi
**/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"
#define spc " "
#define fr(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define deb(a) cout << #a << " " << a << nl;

template<typename T>
void printArray(vector<T>& v) {
	for(auto& i : v)
		cout << i << spc;
	cout << nl;
}
const int MaxN = 2e5 + 5;
const int MOD = 1e9 + 7;

void solve_cases() {
	int n;
	cin >> n;
	if(n >= 30) cout << "Yes" << nl;
	else cout << "No" << nl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cout << setprecision(10) << fixed;
	int t = 1;
	//cin >> t;
	FOR(tt, 1, t) {
		//cout << "Case #" << tt << ": ";
		solve_cases();
	}
}