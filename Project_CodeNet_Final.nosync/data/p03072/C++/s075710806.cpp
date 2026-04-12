/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	cin >> n;
	int a[n];
	int ans = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		bool f = true;
		for (int j = 0; j < i; j++){
			if (a[j] > a[i])
				f = false;
		}
		if (f)
			ans ++;
	}
	cout << ans << endl;
}
