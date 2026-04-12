#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using vi  = vector<int>;
using ii  = pair<int,int>;
using vii = vector<ii>;
using ll  = long long;

typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) int((x).size())
#define REP(i, a, b) for (auto (i) = (a); (i) <= (b); (i)++)
#define PER(i, a, b) for (auto (i) = (a); (i) >= (b); (i)--)
#define ITR(i, x) for (auto (i) = (x).begin(); (i) != (x).end(); (i)++)

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	if (n >= 30) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	return 0;
}