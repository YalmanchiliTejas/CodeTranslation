#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	int n;
	vector<llong> a;

	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = n-1; i >= 0; i -= 2)
		cout << a[i] << " ";
	for(int i = n%2 ? 1 : 0; i < n; i += 2){
		cout << a[i];
		if(i+2 < n)
			cout << " ";
	}


	cout << endl;

	return 0;
}