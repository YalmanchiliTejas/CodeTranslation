#include <bits/stdc++.h>
#include <stdint.h>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N ;
	
	vector<int> H(N,0);
	vector<int> max(N,0);
	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> H.at(i);
		if (i > 0){
			if (H.at(i) > max.at(i-1)) {
	//			cout << "dbg koushin" << endl;
				max.at(i) = H.at(i);
			} else {
				max.at(i) = max.at(i - 1);
	//			cout << "dbg low" << endl;
			}
			
		} else {
			max.at(i) = H.at(i);
		}
		if(max.at(i) == H.at(i)) {
			ans++;
	//		cout << "dbg " << i << ", " << H.at(i) << endl;
		}
		
	//	cout << "dbg2 " << H.at(i) << ", " << max.at(i) << endl;
		
	}
	
	cout << ans << endl;
	
	



	return 0;
}
