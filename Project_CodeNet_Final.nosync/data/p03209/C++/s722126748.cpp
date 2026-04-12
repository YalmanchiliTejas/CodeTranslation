#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
template<class T> inline istream& operator >> (istream & c, vector<T> & A) {rep(i, A.size()) c >> A[i];return c;}
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, x;
	cin >> n >> x;
	vector<long long> b(n + 1), p(n + 1);
	b[0] = 1;
	for (int i = 1; i < n + 1; ++i) b[i] = b[i - 1] * 2 + 3;
	p[0] = 1;
	for (int i = 1; i < n + 1; ++i) p[i] = p[i - 1] * 2 + 1;
	function<long long(long long, long long)> Dfs = [&](long long now_class, long long now_x) {
		if (now_class == 0 && now_x >= 1) return 1LL;
		long long now = 0;
		long long ret_p = 0;
		now++;
		if (now >= now_x) return 0LL;
		now += b[now_class - 1];
		if (now >= now_x) {
			ret_p += Dfs(now_class - 1, now_x - 1);
			return ret_p;
		}
		else {
			ret_p += p[now_class - 1];
		}
		now++;
		if (now >= now_x) return ret_p + 1;
		else ret_p++;
		now += b[now_class - 1];
		if (now >= now_x) {
			ret_p += Dfs(now_class - 1, now_x - b[now_class - 1] - 2);
			return ret_p;
		}
		else {
			ret_p += p[now_class - 1];
		}
		return ret_p;
	};
	long long ans = Dfs(n, x);
	cout << ans << endl;
	return 0;
}