#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX_N = 1<<20;
ll n,dat[2*MAX_N-1] = {},lazy[2*MAX_N-1] = {},dp[200010];
bool flag[2*MAX_N-1];
vector<pair<ll,ll>> v[200010];
void init(int m){
	n = 1;
	while(n<m) n *= 2;
	for(int i=0;i<2*n - 1;i++) flag[i] = false;
}
void eval(int k, int l, int r){
	if(flag[k]){
		dat[k] += lazy[k];
		if(r - l>1){
			lazy[2*k+1] += lazy[k]; flag[2*k+1] = true;
			lazy[2*k+2] += lazy[k]; flag[2*k+2] = true;
		}
		lazy[k] = 0; flag[k] = false;
	}
}

void add(int a, int b, ll x, int k = 0, int l = 0, int r = -1){
	if(r<0) r = n;
	eval(k,l,r);
	if(b<=l || r<=a) return;
	if(a<=l && r<=b){
		lazy[k] += x; flag[k] = true;
		eval(k,l,r);
	}else{
		add(a,b,x,2*k+1,l,(l+r)/2); add(a,b,x,2*k+2,(l+r)/2,r);
		dat[k] = max(dat[2*k+1],dat[2*k+2]);
	}
}

ll query(int a, int b, int k, int l, int r){
	eval(k,l,r);
	if(r<=a || b<=l){
		return 0;
	}
	if(a<=l && r<=b){
		return dat[k];
	}else{
		ll vl = query(a,b,k*2+1,l,(l+r)/2);
		ll vr = query(a,b,k*2+2,(l+r)/2,r);
		return max(vl,vr);
	}
}

int main(){
	ll i,j,m,q;
	cin >> m >> q;
	for(i=0;i<q;i++){
		int l,r,a;
		cin >> l >> r >> a;
		v[r].push_back({l,a});
	}
	init(m + 1);
	dp[0] = 0;
	for(i=1;i<=m;i++){
		dp[i] = query(0,i,0,0,n);
		add(i,i + 1,dp[i],0,0,n);
		for(auto x:v[i]){
			add(x.first,i + 1,x.second,0,0,n);
		}
	}
	cout << query(0,m + 1,0,0,n) << endl;
}