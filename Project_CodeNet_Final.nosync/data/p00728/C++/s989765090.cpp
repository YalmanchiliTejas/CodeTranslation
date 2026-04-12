#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	while(1){
		cin >> n;
		vector<int> data;
		if(n == 0) break;

		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			data.push_back(x);
		}
		sort(data.begin(), data.end());
		long long sum = 0;
		for(int i=1; i<n-1; i++){
			sum += data[i];
		}
		sum /= n-2;
		cout << sum << endl;
	}


	return 0;
}