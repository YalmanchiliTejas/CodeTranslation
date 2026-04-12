#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;


int main () {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> v;
		int count = 0;

		for(int i = 0; i < n; i++){
			int a;
			cin >> a;
			count+=a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		count-=v[0];
		count-=v[v.size()-1];
		cout << count/(n-2) << endl;
	}
	
	return 0;
}
