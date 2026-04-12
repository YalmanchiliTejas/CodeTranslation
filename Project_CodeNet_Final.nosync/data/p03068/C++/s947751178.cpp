#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define INF 1000000000000000
#define fi first
#define se second
#define all(v) v.begin(),v.end()
typedef pair<int, int> P;
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
struct edge { int to, cost; };
int n, k;
string s;
signed main() {
	cin >> n >> s >> k;
	rep(i, n) {
		if (s[k - 1] != s[i])cout << '*';
		else cout << s[i];
	}
	cout << endl;
	return 0;
}
