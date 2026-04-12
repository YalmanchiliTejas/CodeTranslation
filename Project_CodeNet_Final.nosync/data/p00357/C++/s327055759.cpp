#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	llong N;
	vector<llong> d;

	cin >> N;
	d.resize(N);
	for(int i = 0; i < N; i++)
		cin >> d[i];

	llong maxi = 0;
	for(int i = 0; i < N; i++){
		if(maxi < i*10)
			break;

		maxi = max(maxi, i*10+d[i]);
	}
	if(maxi < 10*(N-1)){
		cout << "no" << endl;
		return 0;
	}

	reverse(BE(d));
	maxi = 0;
	for(int i = 0; i < N; i++){
		if(maxi < i*10)
			break;

		maxi = max(maxi, i*10+d[i]);
	}
	if(maxi < 10*(N-1))
		cout << "no" << endl;
	else
		cout << "yes" << endl;

	return 0;
}
