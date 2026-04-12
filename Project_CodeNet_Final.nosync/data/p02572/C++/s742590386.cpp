#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
// *st.find_by_order(index), 0-based
// order_of_key(e)

const int mul=500000004;
const int mod=1e9+7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int N; cin>>N;
	ll x=0, y=0, A;
	for (int i=0; i<N; i++) {
		cin>>A;
		x=(x+A)%mod;
		y=(y+A*A)%mod;
	}
	cout<<(x*x+mod-y)%mod * mul % mod<<"\n";
	return 0;
}