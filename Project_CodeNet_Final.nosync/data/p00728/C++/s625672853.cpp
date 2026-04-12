#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
	while(true){
		int n;
		cin >> n;
		if(n == 0){ break; }
		int minval = INT_MAX, maxval = 0, sum = 0;
		for(int i = n; i > 0; --i){
			int s;
			cin >> s;
			minval = min(s, minval);
			maxval = max(s, maxval);
			sum += s;
		}
		cout << (sum - minval - maxval) / (n - 2) << endl;
	}
	return 0;
}