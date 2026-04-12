#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define int long long
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e18;

signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	if(!(s[0] == s[1] && s[1] == s[2])) cout << "Yes" << endl;
	else cout << "No" << endl;
}