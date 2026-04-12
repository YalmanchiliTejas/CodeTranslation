#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> d(n);
	for(int i=0; i<n; i++){
		cin >> d[i];
	}
	
	bool ans = true;
	for(int r=0; r<2 && ans; r++){
		int maxdist = 0;
		for(int i=0; i<n; i++){
			if(maxdist < i*10){
				ans = false;
				break;
			}
			maxdist = max(maxdist, i*10 +d[i]);
		}
		reverse(d.begin(), d.end());
	}
	if(ans){
		cout << "yes" << endl;
	}else{
		cout << "no" << endl;
	}
	return 0;
}

