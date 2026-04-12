#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

long eval(ll p, ll q) {
	if(!q) return 0;
	if(!p) return 1;
	ll m=1LL<<p;
	return (q<2*m-1) ? eval(p-1,q-1) : m+eval(p-1,q-2*m+1);
}

int main() {
	ll n,x; cin>>n>>x;
	cout<<eval(n,x)<<"\n";
	return 0;
}