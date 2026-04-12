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

int mx=1e5+777;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll N,X,M; cin>>N>>X>>M;
	ll cur=X;
	map<ll,ll> A;
	map<ll,ll> idx;
	A[0]=cur;
	idx[cur]=0;
	ll period=-1, start=-1;
	for (ll i=1; i<mx; i++) {
		ll nxt=(cur*cur)%M;
		if(idx.count(nxt)) {
			period=i-idx[nxt];
			start=idx[nxt];
			break;
		}
		idx[nxt]=i;
		A[i]=nxt;
		cur=nxt;
	}

	ll sum=0;
	for (int i=0; i<period; i++)
		sum+=A[start+i];

	ll q=(N-start)/period, r=N-q*period;
	ll ret=q*sum;
	for (int i=0; i<r; i++)
		ret+=A[i];
	cout<<ret<<"\n";
	return 0;
}