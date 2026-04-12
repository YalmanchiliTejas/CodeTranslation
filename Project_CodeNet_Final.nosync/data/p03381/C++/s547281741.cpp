#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <string>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define eb emplace_back
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ost;

const ll maxN = 1e7;
const ll INF = 1e17;
const ll MOD = 1e9 + 7;

ll xs[] = {-1, 1, 0, 0, -1, 1, 1, -1};
ll ys[] = {0, 0, -1, 1, -1, 1, -1, 1};

ll segtree[maxN << 2];
ll lazy[maxN << 2];
ll A[maxN];

inline ll left(ll x){
	return x << 1;
}

inline ll right(ll x){
	return (x<<1) + 1;
}

void build(ll node, ll start, ll end){
	if(start == end)
		segtree[node] = A[start];
	else{
		ll mid = (start + end)/2;
		build(left(node), start, mid);
		build(right(node), mid+1, end);
		segtree[node] = segtree[left(node)] + segtree[right(node)];
	}
}

void update(ll node, ll start, ll end, ll l, ll r, ll val){
	if(lazy[node] != 0){
		segtree[node] += (end-start+1)*lazy[node];
		if(start != end){
			lazy[left(node)] += lazy[node];
			lazy[right(node)] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(start > end or l > start or r < end)
		return ;
	else if(start >= l and r >= end){
		segtree[node] += val;
		if(start != end){
			lazy[left(node)] += val;
			lazy[right(node)] += val;
		}
	}
	else{
		ll mid=(start + end)/2;
		update(left(node), start, mid, l, r, val);
		update(right(node), mid+1, end, l, r, val);
		segtree[node] = segtree[left(node)] + segtree[right(node)];
	}
}

ll sums(ll node, ll start, ll end, ll l, ll r){
	if(lazy[node] != 0){
		segtree[node] += (end-start+1)*lazy[node];
		if(start != end){
			lazy[left(node)] += lazy[node];
			lazy[right(node)] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(l > end or r < start or start > end)
		return 0;
	if(l <= start and r >= end)
		return segtree[node];
	ll mid = (start+end)/2;
	return sums(left(node), start, mid, l , r) + sums(left(node), mid + 1, end, l , r);
}

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	map<ll, pair<ll, ll> > ind;
	map<ll, ll> aind;
	ll a[n];
	ll b[n];
	for(ll i=0; i<n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b+n);
	for(ll i=0; i<n; i++){
		if(a[i] <= b[(n-1)/2])
			cout << b[(n)/2] << "\n";
		else
			cout << b[((n-1)/2)] << "\n";
	}
	return 0;
}