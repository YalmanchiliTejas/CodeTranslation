#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef long double ld;
 
vector <ll> s;
vector <ll> a;
ll k;
 
void modify(int p,int x,int id = 1,int l = 0,int r = k){
	if(r - l < 2){
		s[id] = x;
		a[p] = x;
		return;
	}
	int mid = (l + r)/2;
	if(p < mid) modify(p, x, id * 2, l, mid);
	else modify(p, x, id * 2 + 1, mid, r);
	s[id] = max(s[id * 2],s[id * 2 + 1]);
}

int query(int x,int y,int id = 1,int l = 0,int r = k){
	if(x >= r or l >= y)	return 0;
	if(x <= l && r <= y)	return s[id];
	int mid = (l+r)/2;
	return max(query(x, y, id * 2, l, mid),
	       query(x, y, id * 2 + 1, mid, r));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	vector <ll> arr(n);
	map <ll,ll> mapp;
	for (int z=0;z<n;z++){
		cin >> arr[z];
		mapp[arr[z]]++;
	}
	unordered_map <ll,ll> index;
	a.resize(mapp.size());
	k = mapp.size();
	ll c = 0;
	for (auto it = mapp.begin();it != mapp.end();it++){
		index[it->first] = c;
		c++;
	}
	s.resize(k*4,0);
	ll ans = 0;
	for (int z=0;z<n;z++){
		ll i = index[arr[z]];
		ll j = query(i,k);
		modify(i,j+1);
		ans = max(ans,j+1);
	}
	cout << ans << endl;
}