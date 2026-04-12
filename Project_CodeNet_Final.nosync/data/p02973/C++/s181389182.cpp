#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	int arr[n];
	
	for (int i=0; i<n; i++) cin >> arr[i];
	
	multiset<int> ends;
	
	for (int i=0; i<n; i++) {
		// can current be added to existing, or should new be made?
		int curr = arr[i];
		multiset<int>::iterator fd = ends.lower_bound(curr);
		if (fd == ends.begin()) {
			ends.insert(curr);
		}
		else {
			--fd;
			ends.erase(fd);
			ends.insert(curr);
		}
	}
	
	cout << ends.size() << endl;
	
	

}
