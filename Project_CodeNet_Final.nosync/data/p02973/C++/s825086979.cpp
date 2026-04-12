#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<functional>
#include<map>
using namespace std;
int p = 1000000007;
#define int long long
#define vel vector<long long>
#define vvel vector<vel>
#define rep(i,n) for(long long i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define qin pair<pin,int>
#define V vector
#define Endl endl
#define veb vector<bool>
#define sq(a) (a)*(a)
#define rev(s) reverse(s.begin(),s.end())
#define end_pr(s) cout << s <<endl;return 0
#define itn int
#define bs bitset<5001>

int kai_size = 1000001;
vel kai(kai_size, 1);
vel ink(kai_size, 1);
vel dist;
signed main() {
	int n; cin >> n;
	V<pin> a(n);
	rep(i, n) { int x; cin >> x; a[i] = mkp(x, -i); }
	sor(a);
	vel b(n);
	rep(i, n) { b[-a[i].second] = i; }
	set<int> se;
	se.insert(-b[0]);
	for (int i = 1; i < n; i++) {
		auto itr=se.lower_bound(-b[i]);
		if (itr == se.end()) { se.insert(-b[i]); }
		else{
			se.erase(itr);
			se.insert(-b[i]);
		}
	}
	cout << se.size() << endl;
	return 0;
}