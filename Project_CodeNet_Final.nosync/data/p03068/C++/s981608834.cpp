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
	string a;
	cin >> a;
	ll k;
	cin >> k;
	for (int z=0;z<n;z++){
		if (a[z] != a[k-1]){
			cout << "*";
		} else {
			cout << a[k-1];
		}
	}
	cout << endl;
	cin >> n;
}