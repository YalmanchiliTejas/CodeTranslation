#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n,x[200000],y[200000];
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> x[i];
		y[i] = x[i];
	}
	sort(y,y + n);
	for(int i = 0;i < n;i++){
		if(x[i] <= y[n / 2 - 1]) cout << y[n / 2] << endl;
		else cout << y[n / 2 - 1] << endl;
	}
	return 0;
}