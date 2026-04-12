#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
pl v[200200];
multiset<ll> rb,bb;
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		ll a,b;
		cin >> a >> b;
		if(a > b) {swap(a,b);}
		v[i] = {a,b};
		rb.insert(a);
		bb.insert(b);
	}
	sort(v,v+n);
	ll ma = 1LL<<61;
	for(int i=0;i<n;i++) {
		ll rv = (*rb.rbegin())-(*rb.begin());
		ll bv = (*bb.rbegin())-(*bb.begin());
		ma = min(ma,rv*bv);
		ll a = v[i].first,b = v[i].second;
		rb.erase(rb.find(a));
		bb.erase(bb.find(b));
		rb.insert(b);
		bb.insert(a);
	}
	ll rv = (*rb.rbegin())-(*rb.begin());
	ll bv = (*bb.rbegin())-(*bb.begin());
	ma = min(ma,rv*bv);
	cout << ma << '\n';
}