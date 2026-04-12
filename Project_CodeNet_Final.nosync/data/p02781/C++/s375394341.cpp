#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int go(int n, int m) {
	if(m > n) return 0;
	int ret = 1;
	for(int i = 0; i < m; i++)
		ret *= 9;
	for(int i = 1; i <= m; i++) {
		ret *= n--;
		ret /= i;
	}
	return ret;
}

signed main()
{
	IO_OP;
	
	string s;
	int k;
	cin >> s >> k;
	int cnt = 0, ans = 0;
	for(char c : s) if(c != '0') cnt++;
	if(cnt == k) ans++;
	cnt = 0;
	for(int i = 0; i < s.size(); i++) {
		if(cnt <= k && s[i] != '0') {
			int req = k - cnt;
			ans += go(s.size()-i-1, req);
			if(req && s[i] > '1') ans += (s[i] - '1') * go(s.size()-i-1, req-1);
		}
		cnt += s[i] != '0';

	}	
	cout << ans << endl;
}



