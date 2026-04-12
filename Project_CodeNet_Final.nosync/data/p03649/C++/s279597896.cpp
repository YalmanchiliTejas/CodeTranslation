#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int n;
	ll a[52];
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		cin >> a[i];
	}
	
	ll ret = 0;
	while(1){
		ll memo = ret;
		for(int i = 0 ; i < n ; i ++){
			ll x = a[i]/n;
			ret += x;
			a[i] %= n;
			for(int j = 0 ; j < n ; j ++){
				if(i!=j)a[j] += x;
			}
		}
		if(memo == ret)break;
	}
	cout << ret << endl;
}