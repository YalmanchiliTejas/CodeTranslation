#include <bits/stdc++.h>

using namespace std;



main(){

	ios::sync_with_stdio(false);
	// cin.tie(0); cout.tie(0);

	int n; cin >> n;

	vector <int> a(n);

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}



	multiset <int> m;


	for(int i = 0; i < n; i++){
		auto it = m.lower_bound(a[i]);

			if(it == m.begin()){
				m.insert(a[i]);
			}else{
				m.erase(prev(it));
				m.insert(a[i]);
			}
	}

	// cout << " ---- " << endl;
	// for(auto it : m){
	// 	cout << it << endl;
	// }


	cout << m.size() << endl;

	return 0;
}