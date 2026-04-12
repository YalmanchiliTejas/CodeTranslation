#include <bits/stdc++.h>
#include  <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
#define endl '\n'
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> index_set;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ii = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define pb push_back

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	cin >> n;
	if(n >=30)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;    
}
