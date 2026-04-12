#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n; cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) {
    	cin >> v[i];
    }
    ll cnt = 0;
    while(1) {
    	ll sum = 0;
    	ll maxv = -1;
    	for(int i = 0; i < n; i++) {
    		sum += v[i]/n*(1LL);
    		maxv = max(maxv, v[i]);
    	}
    	if(maxv < n) break;
    	for(int i = 0; i < n; i++) {
    		v[i] = v[i] + sum - v[i]/n*(1LL) - (v[i]/n*(1LL))*n;
    	}
    	cnt += sum;
    }
    cout << cnt;
    
	return 0;
}
