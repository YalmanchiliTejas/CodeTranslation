#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
// *st.find_by_order(index), 0-based
// order_of_key(e)

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int X; cin>>X;
	cout<<(X>=30 ? "Yes" : "No")<<"\n";
	return 0;
}