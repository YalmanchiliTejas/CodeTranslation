#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll N,K,ret=0; cin>>N>>K;
	for (int b=1; b<=N; b++)
		ret+=(N/b) * max(0LL,b-K) + max(0LL,(N%b)-K+1) - !K;
	cout<<ret<<"\n";
	return 0;
}