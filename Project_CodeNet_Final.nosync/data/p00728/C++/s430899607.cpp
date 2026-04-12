#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

int main(){

	int n;
	
	while(cin >> n, n){
		
		vector<int> vc;
		
		for(int i=0; i<n; ++i){
			int a;
			cin >> a;
			vc.push_back(a);
		}
		
		sort(vc.begin(), vc.end());
		
		int sum = 0;
		
		for(int i=1; i<vc.size()-1; ++i){
			sum += vc[i];
		}
		
		cout << sum/(n-2) << endl;
	}
	
	return 0;
}
			