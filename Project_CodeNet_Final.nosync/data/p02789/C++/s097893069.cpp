#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ll long long
#define vi vector<int>
#define pi pair<int, int>
#define pb push_back
#define ppb pop_back
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()


using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n, m;
	cin >> n >> m;
	if(n != m){
        cout << "No";
        return 0;
	}
	cout << "Yes";
	return 0;
}
