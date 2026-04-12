#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	ll n;
	cin >> n;
	vector <ll> arr(n);
	ll temp = 0;
	ll count = 0;
	for (int z=0;z<n;z++){
		ll a;
		cin >> a;
		if (a >= temp){
			count++;
			temp = a;
		}
	}
	cout << count << endl;
	cin >> n;
}