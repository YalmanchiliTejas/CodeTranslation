#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n; cin >> n;
	vector<ll> a(n);
	vector<ll> done(n, false);
	for(int i=0;i<n;i++) cin >> a[i];

	multiset<int> heads;
	int colors = 0;
	for(int i=0;i<n;i++){
		// if(heads)
		auto it = heads.lower_bound(a[i]);

		// cout << (it == heads.begin()) << " | "<< (it == heads.end()) 
		//  << " | it: "<<*it << " | search: "<<a[i] << endl;

		if(heads.size() == 0 || it == heads.begin()){
			colors++;
			heads.insert(a[i]);
		}else{
			it--;
			heads.erase(it);
			heads.insert(a[i]);
		}
	}
	cout << colors << endl;

	return 0;
}