#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define endl "\n"
#define all(a) a.begin(),a.end()
#define debug(x) cout << x << endl;
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
/* 	1) order_of_key (k) : Number of items strictly smaller than k .
	2) find_by_order(k) : K-th element in a set (counting from zero).
*/
using namespace __gnu_pbds;
using namespace std;
using LD = long double;

const int N = 1e4+2;
const int mod = 1e9+7;
const int INF = 1e18;
int row[8] = {1,1,0,-1,-1,-1,0,1};
int col[8] = {0,-1,-1,-1,0,1,1,1};

void solve() {
	int x;
	cin >> x;
	if(x >= 30)
		cout << "Yes";
	else
		cout << "No";
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1,i = 1;
    //cin >> t;
    while(t--) {
        //cout << "Case #" << i << ": ";
        solve();
        //i++;
    }
    return 0;
}
