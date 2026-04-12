#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
using namespace std;
#define vel vector<long long>
#define vvel vector<vel>
#define int long long
#define rep(i,n) for(long long i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define V vector
vel uni(vel &list) {
	if (list.size() == 0) { return list; }
	sort(list.begin(), list.end());
	vel ql(1, list[0]);
	rep(i, list.size() - 1) {
		if (list[i] != list[i + 1]) { ql.push_back(list[i + 1]); }
	}
	list = ql;
	return ql;
}
signed main() {
	int n; cin >> n;
	vel s(n);
	rep(i, n) { cin >> s[i]; }
	int ans = 0;
	for (int a = 1; a < n; a++) {
		if ((n-1)%a == 0) {
			int qans = 0;
			int itr1 = a; int itr2 = n - a-1;
			while (itr1 < itr2) {
				qans += s[itr1] + s[itr2];
				itr1 += a; itr2 -= a;
				mmax(ans, qans);
			}
		}
		else {
			int qans = 0;
			int itr1 = a; int itr2 = n - a-1;
			while (a < itr2) {
				qans += s[itr1] + s[itr2];
				itr1 += a; itr2 -= a;
				mmax(ans, qans);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
