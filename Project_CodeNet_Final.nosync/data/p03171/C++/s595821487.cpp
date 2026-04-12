#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
#define int ll
vector<vector<ll>> memot(3e3+3, vector<ll>(3e3, -1));
vector<vector<ll>> memoj(3e3+3, vector<ll>(3e3, -1));
vector<ll> pref(3e3+3);

ll jiro(vector<int> &v, int l, int r);

ll taro(vector<int> &v, int l, int r){
	if(l == r){
		return v[l]; 
	}
	if(memot[l][r] != -1)
		return memot[l][r];
	ll f, ff, b, bb;
	if(l > 0){
		ff = pref[r] - pref[l-1] - jiro(v, l+1, r);
		bb = pref[r] - pref[l-1] - jiro(v, l, r-1);

		f = ff - jiro(v, l+1, r);
		b = bb - jiro(v, l, r-1);
	}else{
		ff = pref[r] - jiro(v, l+1, r);
		bb = pref[r] - jiro(v, l, r-1);		

		f = ff - jiro(v, l+1, r);
		b = bb - jiro(v, l, r-1);		
	}
	if(f > b)
		memot[l][r] = ff;
	else
		memot[l][r] = bb;
	return memot[l][r];
}

ll jiro(vector<int> &v, int l, int r){
	if(l == r){
		return v[l]; 
	}
	if(memoj[l][r] != -1)
		return memoj[l][r];
	ll f, ff, b, bb;
	if(l > 0){
		ff = taro(v, l+1, r) - pref[r] + pref[l-1];
		ff = -ff;
		f = taro(v, l+1, r) - ff; 
		bb = taro(v, l, r-1) - pref[r] - pref[l-1];
		bb = -bb;
		b = taro(v, l, r-1) - bb;
	}else{
		ff = taro(v, l+1, r) - pref[r];
		bb = taro(v, l, r-1) - pref[r];
		ff = -ff;
		bb = -bb;
		f = taro(v, l+1, r) - ff;
		b = taro(v, l, r-1) - bb;
	}
	if(f < b){
		memoj[l][r] = ff;
	}else{
		memoj[l][r] = bb;
	}
	return memoj[l][r];
}
ll t(vector<int> &v, int l, int r);
ll j(vector<int> &v, int l, int r){
	if(l == r)
		return -v[l];
	if(memoj[l][r] != -1)
		return memoj[l][r];
	ll f, b;
	f = t(v, l+1, r)-v[l];
	b = t(v, l, r-1)-v[r];
	return memoj[l][r] = min(f, b);
}
ll t(vector<int> &v, int l, int r){
	if(l == r)
		return v[l];
	if(memot[l][r] != -1)
		return memot[l][r];
	ll f, b;
	f = j(v, l+1, r)+v[l];
	b = j(v, l, r-1)+v[r];
	return memot[l][r] = max(f, b);
}

signed main() { 
	cin.tie(0);
	cin.sync_with_stdio();
	int n; 
	cin>>n;
	vector<int> v(n);
	for(int &i : v)
		cin>>i;
	pref[0] = v[0];
	for(int i = 1; i < n; i++){
		pref[i] = pref[i-1]+v[i];
	}
	cout<<t(v, 0, n-1);
	
}
