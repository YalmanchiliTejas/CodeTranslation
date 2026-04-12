#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

int n;

int main(int argc, char const *argv[]) {
	cin>>n;
	map<char,int> x;
	for (char q = 'a'; q<='z'; ++q) x[q] = INF;

	rep(i,n) {
		map<char,int> mp;
		string s;
		cin>>s;
		int m = s.length();
		rep(j,m) mp[s[j]]++;
		for (char c = 'a'; c <= 'z'; ++c) {
			x[c] = min(x[c], mp[c]);
		}
	}

	string ans;

	for (auto &&e: x) {
		rep(i,e.second) ans.push_back(e.first);
	}

	cout << ans << endl;
	return 0;
}
