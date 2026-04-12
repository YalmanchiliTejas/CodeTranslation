#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (long long  i=a;i<n;i++)
#define sz(A) (int)(A.size())
#define all(x) (x).begin(),(x).end()
#define get(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;

void solve() {
	int n;
	cin >> n;
	if (n >= 30)cout << "Yes" << endl;
	else cout << "No" << endl;
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T_ = 1;
	//cin >> T_;
	for (int i = 0; i < T_; i++)solve();
	return 0;
}

