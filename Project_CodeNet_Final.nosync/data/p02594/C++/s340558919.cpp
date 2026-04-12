#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define ppb pop_back()
#define fi first
#define se second
#define pi pair<int, int>
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define REP(i, a, n) for(int i = a; i < n; i++)
#define Y "Yes"
#define N "No"
using namespace std;

int T, n;

void solve() {
	cin >> n;
	if (n >= 30) cout << Y;
	else cout << N;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//freopen("in.txt", "r", stdin);

	///cin >> T;
	//while (T--) {
		solve();
		//cout << '\n';
	//}
}