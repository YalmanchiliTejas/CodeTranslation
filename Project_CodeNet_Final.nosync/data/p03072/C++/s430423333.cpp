#include <bits/stdc++.h>

using namespace std;


#define PI 3.14159265
#define int long long




main(){


	int n;

	cin >> n;

	vector <int> h(n);
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}

	int m = h[0], cnt = 1;
	for(int i = 1; i < n; i++){
		if(h[i] >= m) cnt++;

		m = max(m, h[i]);
	}


	cout << cnt << endl;


	return 0;
}