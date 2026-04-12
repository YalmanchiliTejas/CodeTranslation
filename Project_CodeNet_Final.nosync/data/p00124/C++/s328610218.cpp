#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool func(pair< string, int > a, pair< string, int > b){
	return a.second > b.second;
}

int main(){
	
	int n, w, l, d, c = 0;
	string country;
	vector< pair< string, int > > v;
	
	while(cin >> n, n){
		v.clear();
		
		for(int i = 0; i < n; ++i){
			cin >> country >> w >> l >> d;
			v.push_back(pair< string, int >(country, w * 3 + d));
		}
		
		sort(v.begin(), v.end(), func);
		
		
		if(c != 0) cout << endl;
		++c;
		
		for(vector< pair< string, int > >::iterator it = v.begin(); it != v.end(); ++it){
			cout << (it->first) << "," << (it->second) << endl;
		}
		
	}
	
	return 0;
}